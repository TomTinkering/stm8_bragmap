/** ******************************************************************
   @file TOUCH_drv.c
   @brief  TOUCH_drv Source
   @details

   .....

******************************************************************* */

//*******************************************************************
//Includes
#include "Global.h"
#include "stm32f0xx.h"
#include "stm32f0xx_exti.h"
#include "stm32f0xx_syscfg.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_tim.h"
#include "TOUCH_drv.h"


//*******************************************************************
//Definitions

//*******************************************************************
//Variables

GPIO_InitTypeDef        GPIO_InitStructure;
uint32_t                TOUCH_results[32];
uint32_t                TOUCH_resRegs[32];
uint32_t                curMeas;
TOUCH_t                 measStatus;

//*******************************************************************
//Helper Function Prototypes (declare static!)

//*******************************************************************
//Function Implementations


/**
  * @brief  To be updated...
  * @param  None
  * @retval None
  */
void TOUCH_SetSide (TOUCH_side_t side, TOUCH_pin_t value) {

    //determine which set of pins to use for the selected side
    TOUCH_gpio_t gpioPins = (side == SIDE_A) ? TOUCH_SIDE_A_PINS : TOUCH_SIDE_B_PINS;

    //determine the input/output mode setting based on the given value
    GPIO_InitStructure.GPIO_Mode = (value == HIGH_Z) ? GPIO_Mode_IN : GPIO_Mode_OUT;

    //store the settings for the given pins and output mode
    GPIO_InitStructure.GPIO_Pin = gpioPins;
    GPIO_Init(TOUCH_GPIO_PORT, &GPIO_InitStructure);

    //when value was LOW or HIGH, set pins appropriately
    if (value == LOW) {
        TOUCH_GPIO_PORT->BRR = gpioPins;
    } else if (value == HIGH) {
        TOUCH_GPIO_PORT->BSRR = gpioPins;
    }

}


/**
  * @brief  To be updated...
  * @param  None
  * @retval None
  */
void TOUCH_DisableIRQ() {

    EXTI_InitTypeDef   EXTI_InitStructure;

    //for all pins, these settings are universal
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
    EXTI_InitStructure.EXTI_LineCmd = DISABLE;

    //configure all the 16 possible external interrupts
    for (uint8_t i=0; i<16; i++) {

       //set new interrupt settings if given pin is a TOUCH pin
        if( 1) {//IS_TOUCH_PIN(i) ) {

            //update settings
            EXTI_InitStructure.EXTI_Line = (1 << i); //see EXTI_LineXX definitions in stm32f0xx_exti.h
            EXTI_Init(&EXTI_InitStructure);

        }
    }
}

/**
  * @brief  To be updated...
  * @param  None
  * @retval None
  */
void TOUCH_SetInterrupts(TOUCH_side_t side, TOUCH_irq_t irqEdge) {

    EXTI_InitTypeDef   EXTI_InitStructure;

    //for all pins, these settings are universal
    EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitStructure.EXTI_Trigger = (irqEdge == IRQ_FALLING) ? EXTI_Trigger_Falling : EXTI_Trigger_Rising;

    //configure all the 16 possible external interrupts
    for (uint8_t i=0; i<16; i++) {

       //set new interrupt settings if given pin is a TOUCH pin
        if( IS_TOUCH_PIN(i) ) {

            //determine pin interrupt state depending on side
            if( side == SIDE_A ) {
                EXTI_InitStructure.EXTI_LineCmd = (IS_SIDE_A_PIN(i)) ? ENABLE : DISABLE;
            } else {
                EXTI_InitStructure.EXTI_LineCmd = (IS_SIDE_B_PIN(i)) ? ENABLE : DISABLE;
            }

            //update settings
            EXTI_InitStructure.EXTI_Line = (1 << i); //see EXTI_LineXX definitions in stm32f0xx_exti.h
            EXTI_Init(&EXTI_InitStructure);

        }
    }
}

/**
  * @brief  To be updated...
  * @param  None
  * @retval None
  */
void  TOUCH_StartTimer() {

    /* TIM2 enable counter */
    TIM_Cmd(TIM2, ENABLE);

}


/**
  * @brief  To be updated...
  * @param  None
  * @retval None
  */
void TOUCH_StartMeasurement (TOUCH_dir_t dir, TOUCH_side_t send, TOUCH_side_t recv) {

    //determine starting state of measurement
    TOUCH_t sendState = (dir == UP) ? HIGH : LOW;
    TOUCH_t recvState = (dir == UP) ? LOW : HIGH;
    TOUCH_t irqEdge  = (dir == UP) ? IRQ_RISING : IRQ_FALLING;

	//set initial pin states
	TOUCH_SetSide(send, sendState);
	TOUCH_SetSide(recv, recvState);

	//clear measurement variables
	curMeas = 0;
	measStatus = TOUCH_MEAS_ACTIVE;

	//enable receiver side interrupts, on proper edge, disable send side interrupts
	TOUCH_SetInterrupts (recv, irqEdge);

	//start the timer (initialized to overflow at xxMs, after which
	//the measurement is done
	TOUCH_StartTimer();

	//set receiving pins to HighZ input (no pull-up)
	TOUCH_SetSide(recv, HIGH_Z);

	//rely on interrupt routine to handle measurement
}

/**
  * @brief  To be updated...
  * @param  None
  * @retval None
  */
void TOUCH_Init(void)
{

    NVIC_InitTypeDef   NVIC_InitStructure;

    /* Enable SYSCFG clock */
     RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
     /* Enable GPIOA clock */
     RCC_AHBPeriphClockCmd(TOUCH_PERIPHERAL_CLOCK, ENABLE);

    //settings that overlap for all cases
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_Level_3;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;

    //disable all external interrupts
    TOUCH_DisableIRQ();

    //clear measurement variables
    curMeas = 0;
    measStatus = TOUCH_MEAS_DONE;

    //connect all the relevant external interrupt inputs
    for (uint8_t i=0; i<16; i++) {
        //only set interrupt settings if selected pin is a touch pin
        if( IS_TOUCH_PIN(i) ) {
            SYSCFG_EXTILineConfig(TOUCH_EXTI_SOURCE, i); //see stm32f0xx_syscfg.h for i -> line relation
        }
    }

//    //if pin 0 or pin 1 are used, enable interrupts
//    if ( (TOUCH_ALL_PINS & 0x01) || (TOUCH_ALL_PINS & 0x02) ) {
//
//        /* Enable and set EXTI Line0 and Line1 Interrupt */
//        NVIC_InitStructure.NVIC_IRQChannel = EXTI0_1_IRQn;
//        NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
//        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//        NVIC_Init(&NVIC_InitStructure);
//
//    }
//
//    //if pin 2 or pin 3 are used, enable interrupts
//    if ( (TOUCH_ALL_PINS & 0x04) || (TOUCH_ALL_PINS & 0x08) ) {
//
//        /* Enable and set EXTI Line2 and Line3 Interrupt */
//        NVIC_InitStructure.NVIC_IRQChannel = EXTI2_3_IRQn;
//        NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
//        NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//        NVIC_Init(&NVIC_InitStructure);
//
//    }
//

  /* Enable and set EXTI Line4-Line15 Interrupts */
  NVIC_InitStructure.NVIC_IRQChannel = EXTI4_15_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0x00;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  //setup timer
  /* Enable the TIM2 global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  /* TIM2 Configuration */
  TIM_DeInit(TIM2);

  /* TIM2 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  TIM_TimeBaseInitTypeDef timerInitStructure;
  timerInitStructure.TIM_Prescaler = 0;
  timerInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  timerInitStructure.TIM_Period = 240000;
  timerInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
  timerInitStructure.TIM_RepetitionCounter = 0;
  TIM_TimeBaseInit(TIM2, &timerInitStructure);

  // Enable Timer update events
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);

}


/**
  * @brief  To be updated...
  * @param  None
  * @retval None
  */
void TIM2_IRQHandler(){ //TIM2 interrupt handler

    //stop timer
    TIM_Cmd(TIM2, DISABLE);
    //disable all external interrupts
    TOUCH_DisableIRQ();
    //reset timer value
    TIM_SetCounter(TIM2,0x00);
    //clear interrupt flags
    TIM2->SR = 0x00;
    //indicate measurements done
    measStatus = TOUCH_MEAS_DONE;
}

/**
  * @brief  To be updated...
  * @param  None
  * @retval None
  */
void EXTI_IRQHandler(){ //EXTI interrupt handler

    //store timer result
    TOUCH_results[curMeas] = TIM2->CNT;
    //get source channels
    TOUCH_resRegs[curMeas] = EXTI->PR;  //get all pending bits
    EXTI->PR = TOUCH_resRegs[curMeas]; //0x0000FFFF;              //clear all pending EXTI bits

    //increment measurement counter
    curMeas++;

}

//END OF TOUCH_drv.c
