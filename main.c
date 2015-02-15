/*
 * main.c
 *
 *  Created on: Feb 12, 2015
 *      Author: tomv
 */
#include "global.h"
#include "sys_time.h"

/*
 *
 * pinout stm8s

input / output cap touch pairs

pc3 / pc4
pc5 / pc6
pd2 / pd3

uart info / debugging

pd5
pd6

i2c bus interface

pb4
pb5

led outputs

pa1,pa2,pa3,pd1,pd4,pc7

*/

//need auto adressing protocol



//simple pin function macro's, use with caution
#define SET_HIGH(port,pins)         ((port->ODR) |= pins)
#define SET_LOW(port,pins)          ((port->ODR) &= ~(pins))
#define TOGGLE(port,pins)           ((port->ODR) ^= pins)

#define SET_OUTPUT(port,pins)       ((port->DDR) |= pins)
#define SET_INPUT(port,pins)        ((port->DDR) &= ~(pins))
#define ENABLE_PULLUP(port,pins)    ((port->CR1) |= pins)
#define DISABLE_PULLUP(port,pins)   ((port->CR1) &= ~(pins))
#define ENABLE_EXTI(port,pins)      ((port->CR2) |= pins)
#define DISABLE_EXTI(port,pins)     ((port->CR2) &= ~(pins))
#define READ(port,pins)             ((port->IDR) & pins)


//GPIO Pin number alias
#define P0 (0x01)
#define P1 (0x02)
#define P2 (0x04)
#define P3 (0x08)
#define P4 (0x10)
#define P5 (0x20)
#define P6 (0x40)
#define P7 (0x80)
#define ALL_PINS (0xFF)
#define NO_PINS (0x00)

//GPIO Touch pin definitions (grouped to reduce IO calls)
//TODO: check settings!!!
#define TOUCH_GPIOA_A_PINS (P1)
#define TOUCH_GPIOA_B_PINS (P2)

#define TOUCH_GPIOB_A_PINS (NO_PINS)
#define TOUCH_GPIOB_B_PINS (NO_PINS)

#define TOUCH_GPIOC_A_PINS (P3 | P5)
#define TOUCH_GPIOC_B_PINS (P4 | P6)

#define TOUCH_GPIOD_A_PINS (NO_PINS)
#define TOUCH_GPIOD_B_PINS (NO_PINS)

#define TOUCH_NR_KEYS (6)

#define TOUCH_TIMEOUT_TIMER (0)
#define TOUCH_TIMEOUT_MS    (3)

#define EXTI_ALL_FALLING_EDGE (0xAA) //0b10101010
#define EXTI_ALL_RISING_EDGE  (0x55) //0b01010101


//GPIO Led output pins
typedef struct touch_io_t {
    uint8_t io_pin;
    GPIO_TypeDef *io_port;
    uint8_t led_pin;
    GPIO_TypeDef *led_port;
} touch_io_t;


//storage for key administration
touch_io_t TOUCH_keys[6];


typedef enum ret_t {

	EXIT_OK,


} ret_t;


/** *****************************************************************
 * @brief  initialize touch GPIO settings, timers and interrupts
 * @retval EXIT_OK, unless init failed
 ***************************************************************** */
ret_t TOUCH_init(void) {

    uint8_t i;

    //(manually) set touch admin info
    //TODO: check settings!!
    TOUCH_keys[0].io_pin = P3;
    TOUCH_keys[0].io_port = GPIOC;
    TOUCH_keys[0].led_pin = P7;
    TOUCH_keys[0].led_port = GPIOC;

    TOUCH_keys[1].io_pin = P4;
    TOUCH_keys[1].io_port = GPIOC;
    TOUCH_keys[1].led_pin = P1;
    TOUCH_keys[1].led_port = GPIOD;

    TOUCH_keys[2].io_pin = P5;
    TOUCH_keys[2].io_port = GPIOC;
    TOUCH_keys[2].led_pin = P2;
    TOUCH_keys[2].led_port = GPIOD;

    TOUCH_keys[3].io_pin = P6;
    TOUCH_keys[3].io_port = GPIOC;
    TOUCH_keys[3].led_pin = P3;
    TOUCH_keys[3].led_port = GPIOD;

    TOUCH_keys[4].io_pin = P1;
    TOUCH_keys[4].io_port = GPIOA;
    TOUCH_keys[4].led_pin = P4;
    TOUCH_keys[4].led_port = GPIOD;

    TOUCH_keys[5].io_pin = P2;
    TOUCH_keys[5].io_port = GPIOA;
    TOUCH_keys[5].led_pin = P3;
    TOUCH_keys[5].led_port = GPIOA;

    //initialize touch pin settings
    for(i=0;i<TOUCH_NR_KEYS;i++){
        //set to output
        SET_OUTPUT(TOUCH_keys[i].led_port,TOUCH_keys[i].led_pin);
        SET_OUTPUT(TOUCH_keys[i].io_port,TOUCH_keys[i].io_pin);
        //disable pullup
        DISABLE_PULLUP(TOUCH_keys[i].led_port,TOUCH_keys[i].led_pin);
        DISABLE_PULLUP(TOUCH_keys[i].io_port,TOUCH_keys[i].io_pin);
        //set output to zero
        SET_LOW(TOUCH_keys[i].led_port,TOUCH_keys[i].led_pin);
        SET_LOW(TOUCH_keys[i].io_port,TOUCH_keys[i].io_pin);
    }

    //initialize timer
    TIM2->CR1 = 0x00;
    TIM2->CR1 |= TIM2_CR1_OPM; //stop counting when end is reached
    TIM2->IER = 0x00; //disable all interrupts from this timer
    TIM2->ARRH = 0x00;
    TIM2->ARRL = 0x00; //use auto update register for reset action
    TIM2->EGR |= TIM2_EGR_UG; //reset timer
    TIM2->PSCR = 0x00; //no prescaler

    //setup GPIO (EXTI) interrupts


    //TODO: remove, will always reach
    return EXIT_OK;

}


ret_t TOUCH_discharge_cycle(){


    //pseudo code

    //set all pins to high output
    SET_HIGH(GPIOA,TOUCH_GPIOA_A_PINS);
    SET_HIGH(GPIOB,TOUCH_GPIOB_A_PINS);
    SET_HIGH(GPIOC,TOUCH_GPIOC_A_PINS);
    SET_HIGH(GPIOD,TOUCH_GPIOD_A_PINS);

    SET_HIGH(GPIOA,TOUCH_GPIOA_B_PINS);
    SET_HIGH(GPIOB,TOUCH_GPIOB_B_PINS);
    SET_HIGH(GPIOC,TOUCH_GPIOC_B_PINS);
    SET_HIGH(GPIOD,TOUCH_GPIOD_B_PINS);

    //wait to settle (<1ms)
    SYSTIME_delay_us(100);

    //set meas side to input - no pullup - interrupt enabled
    SET_INPUT(GPIOA,TOUCH_GPIOA_A_PINS);
    SET_INPUT(GPIOB,TOUCH_GPIOB_A_PINS);
    SET_INPUT(GPIOC,TOUCH_GPIOC_A_PINS);
    SET_INPUT(GPIOD,TOUCH_GPIOD_A_PINS);

    ENABLE_EXTI(GPIOA,TOUCH_GPIOA_A_PINS);
    ENABLE_EXTI(GPIOB,TOUCH_GPIOB_A_PINS);
    ENABLE_EXTI(GPIOC,TOUCH_GPIOC_A_PINS);
    ENABLE_EXTI(GPIOD,TOUCH_GPIOD_A_PINS);

    //set interrupt to falling edge
    EXTI->CR1 = (EXTI_ALL_FALLING_EDGE);

    //enable GPIO interrupts , disable other interrupts

    //start measurement timeout (3ms)
    SYSTIME_set_timeout(TOUCH_TIMEOUT_TIMER, TOUCH_TIMEOUT_MS);
    //reset timer
    TIM2->CNTRH = 0x00;
    TIM2->CNTRL = 0x00;
    TIM2->EGR |= TIM2_EGR_UG;
    //start timer
    TIM2->CR1 |= TIM2_CR1_CEN;

    //set drive side low
    SET_LOW(GPIOA,TOUCH_GPIOA_B_PINS);
    SET_LOW(GPIOB,TOUCH_GPIOB_B_PINS);
    SET_LOW(GPIOC,TOUCH_GPIOC_B_PINS);
    SET_LOW(GPIOD,TOUCH_GPIOD_B_PINS);
    //wait on timeout
    while( (TIM2->CR1 & TIM2_CR1_CEN) != 0x00)
    {
        __asm__ ("nop\n"); //wait for finish
    }

    //stop timer
    TIM2->CR1 &= ~TIM2_CR1_CEN;

    //disable GPIO interrupts, enable other interrupts






    //TODO: remove, will always reach
    return EXIT_OK;


}


/** *****************************************************************
 * @brief  initialize default peripheral settings
 * @retval EXIT_OK, unless init failed
 ***************************************************************** */
ret_t init(void) {

    //set all GPIO pins to input with pull up enabled
    ENABLE_PULLUP(GPIOA,ALL_PINS);
    SET_INPUT(GPIOA,ALL_PINS);
    ENABLE_PULLUP(GPIOB,ALL_PINS);
    SET_INPUT(GPIOB,ALL_PINS);
    ENABLE_PULLUP(GPIOC,ALL_PINS);
    SET_INPUT(GPIOC,ALL_PINS);
    ENABLE_PULLUP(GPIOD,ALL_PINS);
    SET_INPUT(GPIOD,ALL_PINS);

    //initialize touch interface
    TOUCH_init();

    //TODO: remove, will always reach
    return EXIT_OK;

}







/** *****************************************************************
 * @brief  application entry point
 * @retval 0 error, this function should not return!
 ***************************************************************** */
int main() {

    //initialize peripherals
    init();

	// Loop
	while(1){}

}
