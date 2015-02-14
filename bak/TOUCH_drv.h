/** ******************************************************************
   @file TOUCH_drv.h
   @brief  TOUCH_drv Header
   @details

   ...
******************************************************************* */

//*******************************************************************
//Includes
#include "Global.h"

#ifndef TOUCH_DRV_H_
	#define TOUCH_DRV_H_

//*******************************************************************
//Definitions

//define GPIO port to use, at the moment the library only supports one port
#define TOUCH_GPIO_PORT (GPIOA)
//define EXTI port source to use (should match GPIO_PORT above
#define TOUCH_EXTI_SOURCE (EXTI_PortSourceGPIOA)
//define clock source for GPIO peripheral
#define TOUCH_PERIPHERAL_CLOCK (RCC_AHBPeriph_GPIOA)
//set pins to use per IO group, for side A
#define TOUCH_SIDE_A_PINS (GPIO_Pin_6)
//set pins to use per IO group, for side B
#define TOUCH_SIDE_B_PINS (GPIO_Pin_5)


//macro's
#define IS_SIDE_A_PIN(n) ( (1 << n) && TOUCH_SIDE_A_PINS )
#define IS_SIDE_B_PIN(n) ( (1 << n) && TOUCH_SIDE_B_PINS )
#define IS_TOUCH_PIN(n)  ( IS_SIDE_A_PIN(n) || IS_SIDE_A_PIN(n) )
#define TOUCH_ALL_PINS   (TOUCH_SIDE_A_PINS | TOUCH_SIDE_B_PINS)

//*******************************************************************
//Type Definitions
typedef enum TOUCH_t
{
	TOUCH_TIMEOUT_ACTIVE = 0x01,
	TOUCH_TIMEOUT_EXPIRED = 0x02,
	TOUCH_MEAS_ACTIVE,
	TOUCH_MEAS_DONE,
	TOUCH_TIMEOUT_HANDLED,

} TOUCH_t;

typedef enum TOUCH_irq_t
{
    IRQ_RISING,
    IRQ_FALLING,
    IRQ_DISABLE,
} TOUCH_irq_t;

typedef enum TOUCH_side_t
{
    SIDE_A,
    SIDE_B,
} TOUCH_side_t;

typedef enum TOUCH_pin_t
{
    HIGH,
    LOW,
    HIGH_Z,
} TOUCH_pin_t;

typedef enum TOUCH_dir_t
{
    UP,
    DOWN,
} TOUCH_dir_t;

typedef uint32_t TOUCH_gpio_t;


//*******************************************************************
//External Variables

extern uint32_t                TOUCH_results[32];
extern uint32_t                TOUCH_resRegs[32];
extern uint32_t                curMeas;
extern TOUCH_t                 measStatus;


//*******************************************************************
//Function Prototypes

void TOUCH_SetSide (TOUCH_side_t side, TOUCH_pin_t value);
void TOUCH_DisableIRQ();
void TOUCH_SetInterrupts(TOUCH_side_t side, TOUCH_irq_t irqEdge);
void TOUCH_StartTimer();
void TOUCH_StartMeasurement (TOUCH_dir_t dir, TOUCH_side_t send, TOUCH_side_t recv);
void TOUCH_Init(void);

#endif //TOUCH_DRV_H_

//END OF TOUCH_drv.h

