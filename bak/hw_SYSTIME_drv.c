/** ******************************************************************
   @file hw_SYSTIME_drv.c
   @brief  STM32 systime driver hardware layer
   @details

   Hardware level calls required by the SYSTIME Generic driver SYSTIME_drv.c
   This layer is mostly macro based although some more complex functions
   have an implementation here.

   @copyright

   Copyright(C) 2013 PowerbyProxi Ltd and PowerbyProxi, Inc.
   All rights reserved

   The content of this file  contains  intellectual property including
   copyright and confidential  information  owned  by PowerbyProxi Ltd
   and PowerbyProxi, Inc.  and is  only to  be used in accordance with
   the terms of the licence. The content of  this  file and/or its use
   may be covered  by  New Zealand,  US and/or  other foreign patents.
   The content of this  file remains  the property of PowerbyProxi Ltd
   and PowerbyProxi, Inc. Dissemination or reproduction of the content
   of this file or part  hereof is  strictly prohibited unless written
   permission is obtained  from PowerbyProxi Ltd or PowerbyProxi, Inc.

******************************************************************* */

//*******************************************************************
//Includes
#include "Global.h"
#include "hw_SYSTIME_drv.h"
//STM32 Lib dependencies
#include "stm32f0xx.h"
#include "stm32f0xx_misc.h"

//*******************************************************************
//#Defines

//*******************************************************************
//Variables

/** @brief pointer to higher level SYSTIME interrupt callback function */
void (*hw_SYSTIME_IRQCallback)(void);

//*******************************************************************
//Functions
//*******************************************************************


/** *******************************************************************
 * @brief   Configures and activates the SysTick timer peripheral hardware.
 * @details
 *
 * Setup a SysTick interrupt to occur every 1 ms based on current system
 * clock. This interrupt will handle the higher level callback functions
 * for the SYSTIME library
 *
***********************************************************************/
void hw_SYSTIME_Init(void (*SYSTIME_Callback)(void))
{

	//store callback function
	hw_SYSTIME_IRQCallback = SYSTIME_Callback;
	//INIT SYSTEM TICK COUNTER FOR MILLISECONDS
	SysTick->LOAD  = (SystemCoreClock / 8000) - 1;      /* set timer interval to 1ms*/
	NVIC_SetPriority (SysTick_IRQn, 2);  /* set Priority for Cortex-M0 System Interrupts */
	SysTick->VAL   = 0;                  /* Load the SysTick Counter Value */
	SysTick->CTRL  = 0x03; //tick interrupt on, timer enabled, clocks on system clock/2

	return;
}

/** *******************************************************************
 * @brief   Provides a rough delay of us microseconds, based on
 * 			looping a series of nop equivalent instructions.
***********************************************************************/
void hw_SYSTIME_DelayUS(uint16_t us)
{
  uint32_t iterations = us * 2;

  while(iterations--)
  {
	  __asm__ volatile ("mov r0, r0");
	  __asm__ volatile ("mov r0, r0");
	  __asm__ volatile ("mov r0, r0");
  }
	return;
}

/** *******************************************************************
  * @brief   STM32 SysTick interrupt. Calls IRQ callback every ms
***********************************************************************/
void SysTick_Handler(void) // Interrupt handler
{
	//perform higher level callback functions
	hw_SYSTIME_IRQCallback();
}

//END OF hw_SYSTIME_drv.c
