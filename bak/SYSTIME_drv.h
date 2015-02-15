/** ******************************************************************
   @file SYSTIME_drv.h
   @brief  SYSTIME_drv Header
   @details

   ...

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

#ifndef SYSTIME_DRV_H_
	#define SYSTIME_DRV_H_

//*******************************************************************
//Definitions
#define SYSTIME_NR_TIMEOUTS	(4)

//*******************************************************************
//Type Definitions
typedef enum systime_t
{
	SYSTIME_TIMEOUT_ACTIVE = 0x01,
	SYSTIME_TIMEOUT_EXPIRED = 0x02,
	SYSTIME_TIMEOUT_HANDLED,
} systime_t;

typedef struct systime_timeout_t
{
	uint32_t startTime;
	uint32_t ms;
	systime_t state;
} systime_timeout_t;


//*******************************************************************
//External Variables

//*******************************************************************
//Function zPrototypes

/*! @brief SYSTIME_drv initialiser */
void SYSTIME_Init(void);
/*! @brief blocking delay in ms */
void SYSTIME_DelayMS(uint16_t ms);
/*! @brief blocking delay in roughly us */
void SYSTIME_DelayUS(uint16_t us);
/*! @brief get current state of timeout, to be used when checking for expiry */
systime_t SYSTIME_GetTimeoutState(uint8_t timer);
/*! @brief start a timeout which will expire after ms milliseconds */
void SYSTIME_SetTimeout(uint8_t timer, uint16_t ms);


#endif //SYSTIME_DRV_H_

//END OF SYSTIME_drv.h
