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

/* GPIO input / output pairs
pa1 / pa2
pb4 / pb5
pc3 / pc4
pd2 / pd3 */

//input output pins definitions
#define GPIOA_SIDEA_PINS (P1)
#define GPIOB_SIDEA_PINS (P4)
#define GPIOC_SIDEA_PINS (P3)
#define GPIOD_SIDEA_PINS (P2)
//SIDEB
#define GPIOA_SIDEB_PINS (P2)
#define GPIOB_SIDEB_PINS (P5)
#define GPIOC_SIDEB_PINS (P4)
#define GPIOD_SIDEB_PINS (P3)

typedef enum ret_t {

	EXIT_OK,


} ret_t;


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
