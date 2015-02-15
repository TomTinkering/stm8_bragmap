/*
 * main.c
 *
 *  Created on: Feb 12, 2015
 *      Author: tomv
 */
#include "stm8s.h"

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
#define READ(port,pins)             ((port->IDR) & pins)
#define SET_INPUT(port,pins)        ((port->DDR) &= ~(pins))
#define SET_OUTPUT(port,pins)       ((port->DDR) |= pins)
#define ENABLE_PULLUP(port,pins)    ((port->CR1) |= pins)
#define DISABLE_PULLUP(port,pins)   ((port->CR1) |= pins)

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

//GPIO Touch pin definitions (grouped to reduce IO calls)
#define TOUCH_GPIOC_A_PINS (P3 | P5)
#define TOUCH_GPIOC_B_PINS (P4 | P6)
#define TOUCH_GPIOA_A_PINS (P1)
#define TOUCH_GPIOA_B_PINS (P2)
#define TOUCH_NR_KEYS (6)

//GPIO Led output pins
typedef struct touch_io_t {
    uint8_t io_pin;
    GPIO_TypeDef *io_port;
    uint8_t led_pin;
    GPIO_TypeDef *led_port;
} touch_io_t;

//storage for key adminitration
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
