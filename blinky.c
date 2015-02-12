#include "stm8l.h"
#include "blink.h"

void blink (){
	int d;
	PE_ODR ^= 0x80;
	for(d = 0; d < 29000; d++) { }
	PE_ODR ^= 0x80;
	for(d = 0; d < 29000; d++) { }
}


