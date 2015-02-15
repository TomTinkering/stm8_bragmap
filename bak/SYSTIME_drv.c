/** ******************************************************************
   @file SYSTIME_drv.c
   @brief  SYSTIME_drv Source
   @details

   This driver provides an interface to give the system it is used in
   a basic notion of time. It provides system ticks at a configurable
   rate and several timeout functions

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
#include "SYSTIME_drv.h"
#include "hw_SYSTIME_drv.h"

//*******************************************************************
//Definitions

//*******************************************************************
//Variables
static systime_timeout_t g_timeouts[SYSTIME_NR_TIMEOUTS];
static volatile uint32_t g_sys_time = 0;

//*******************************************************************
//Helper Function Prototypes (declare static!)

//*******************************************************************
//Function Implementations
void SYSTIME_IRQHandler(void);

/** ******************************************************************
	@brief SYSTIME_drv initialiser. 
 	@details 

	SYSTIME_drv initialiser. Call this function to prepare this module
	for use

	@param [name] [description]

 	@retval [val] [information about return value]

 	@return [information about return state]
******************************************************************* */
void SYSTIME_Init(void)
{
	//reset global system time
	g_sys_time = 0;
	//initialize hardware layer
	HW_SYSTIME_INIT(&SYSTIME_IRQHandler);

}


void SYSTIME_DelayMS(uint16_t ms)
{
	uint32_t startTime = g_sys_time;

	//C standard guarantees correct operation on unsigned overflows in this case
	while(g_sys_time - startTime < (uint32_t)ms){
		//actively do nothing to avoid compiler optimizations
		__asm__ volatile ("mov r0, r0");
	}
}

void SYSTIME_DelayUS(uint16_t us)
{
	HW_SYSTIME_DELAY_US(us);
}

systime_t SYSTIME_GetTimeoutState(uint8_t timer)
{
	//get current state
	systime_t result = g_timeouts[timer].state;

	//if current state is active, check whether expired
	if(result == SYSTIME_TIMEOUT_ACTIVE)
	{
		//if expired, update state.
		if(g_sys_time - g_timeouts[timer].startTime >= g_timeouts[timer].ms)
		{
			result = SYSTIME_TIMEOUT_EXPIRED;
		}
	}

	//return result
	return result;
}

void SYSTIME_SetTimeout(uint8_t timer, uint16_t ms)
{
	g_timeouts[timer].startTime = g_sys_time;
	g_timeouts[timer].ms = ms;
	g_timeouts[timer].state = SYSTIME_TIMEOUT_ACTIVE;
}

void SYSTIME_IRQHandler(void)
{
	g_sys_time++; //increment system tick counter

	//TODO: Implement period tasks?
	return;
}

//END OF SYSTIME_drv.c
