/** ******************************************************************
   @file sys_time.c
   @brief  sys_time source
   @details

   This driver provides an interface to give the system it is used in
   a basic notion of time. It provides system ticks at a configurable
   rate and several timeout functions

******************************************************************* */

//*******************************************************************
//Includes
#include "global.h"
#include "sys_time.h"


//*******************************************************************
//Definitions

//*******************************************************************
//Variables
static systime_timeout_t g_timeouts[SYSTIME_NR_TIMEOUTS];

//*******************************************************************
//Helper Function Prototypes (declare static!)

//*******************************************************************

/** ******************************************************************
	@brief sys_time initialiser.
 	@details 

	sys_time initialiser. Call this function to prepare this module
	sets TIM1 to up-counting mode, 1ms tick, no interrupts
******************************************************************* */
void SYSTIME_init(void)
{
    //Disable timer, set direction up
    TIM1->CR1 = 0x00;
    //disable all timer 1 interrupts
    TIM1->IER = 0x00;
    //clear timer value
    TIM1->CNTRH = 0x00;
    TIM1->CNTRL = 0x00;
    //set timer prescaler
    TIM1->PSCRH = (uint8_t)(PRESCALER_VALUE >> 8);
    TIM1->PSCRL = (uint8_t)PRESCALER_VALUE;
    //set timer maximum value
    TIM1->ARRH = 0xFF;
    TIM1->ARRL = 0xFF;
    //enable timer
    TIM1->CR1 |= TIM1_CR1_CEN;
}

/** ******************************************************************
    @brief ms delay (active) function
    @details

    call this function with a scalar 'ms'. The function will exit
    approximately ms milliseconds after the call, based on TIM1
******************************************************************* */
void SYSTIME_delay_ms(uint16_t ms)
{
	uint32_t startTime = CUR_SYSTEM_TIME;

	//C standard guarantees correct operation on unsigned overflows in this case
	while(CUR_SYSTEM_TIME - startTime < (uint32_t)ms){
		//actively do nothing to avoid compiler optimizations
	    __asm__ ("nop\n");
	}
}

/** ******************************************************************
    @brief us delay (active) function
    @details

    very rough delay of us microseconds
******************************************************************* */
void SYSTIME_delay_us(uint16_t us) {
  uint32_t iterations = us * 2;

  while(iterations--)
  {
      __asm__ ("nop\n");
      __asm__ ("nop\n");
      __asm__ ("nop\n");
  }
    return;
}

/** ******************************************************************
    @brief get current state of timeout
    @details

    call this function to check the current timeout state, to see
    wether a timeout has expired
******************************************************************* */
systime_t SYSTIME_get_timeout_state(uint8_t timer)
{
	//get current state
	systime_t result = g_timeouts[timer].state;

	//if current state is active, check whether expired
	if(result == SYSTIME_TIMEOUT_ACTIVE)
	{
		//if expired, update state.
		if(CUR_SYSTEM_TIME - g_timeouts[timer].startTime >= g_timeouts[timer].ms)
		{
			result = SYSTIME_TIMEOUT_EXPIRED;
		}
	}

	//return result
	return result;
}

/** ******************************************************************
    @brief set / start timeout
    @details

    call this function to set a new timeout. get_timeout_state has
    to be called at least once before complete timer cycle (65s) for
    correct operation
******************************************************************* */
void SYSTIME_set_timeout(uint8_t timer, uint16_t ms)
{
	g_timeouts[timer].startTime = CUR_SYSTEM_TIME;
	g_timeouts[timer].ms = ms;
	g_timeouts[timer].state = SYSTIME_TIMEOUT_ACTIVE;
}

//END OF sys_time.c
