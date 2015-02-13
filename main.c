/*
 * main.c
 *
 *  Created on: Feb 12, 2015
 *      Author: tomv
 */
#include "stm8s_custom.h"
#include "blink.h"

/*
 *
 * pinout stm8s

input / output cap touch pairs

pd2 / pd3
pa1 / pa2
pb4 / pb5
pc3 / pc4

uart info / debugging

pd5
pd6

master interface (SPI)

pc5 / pc6 / pc7

toggle measurement

pa3
 *
 *
 *
 */

/*
 * master sets control pin high
 * masters waits Xms, satelites perform measurement
 * master sets control pin low (satelites store results)
 * master retreives results
 * repeat
 *
 */

typedef enum ret_t {

	EXIT_OK,


} ret_t;


int GPIO_touch_cycle(void)
{

    //set PORTA
    PA_DDR = 0b00000000;
    PA_ODR = 0b00000000;
    PE_CR1 = 0b00000000;



}


int main() {

	// Configure pins
	PE_DDR = 0x80;
	PE_CR1 = 0x80;
	// Loop
	while(1){
		blink();
	}

}
