/*
 * main.c
 *
 *  Created on: Feb 12, 2015
 *      Author: tomv
 */
#include "stm8l.h"
#include "blink.h"

int main() {

	// Configure pins
	PE_DDR = 0x80;
	PE_CR1 = 0x80;
	// Loop
	while(1){
		blink();
	}

}
