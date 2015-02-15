/** ******************************************************************
   @file hw_RS232_drv.h
   @brief  STM32 RS232 driver hardware layer
   @details

   Hardware level calls required by the RS232 Generic driver RS232_drv.c
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
#include "HardwareConfig.h"
#include "stm32f0xx.h"

#ifndef HW_SYSTIME_DRV_H_
	#define HW_SYSTIME_DRV_H_

//*******************************************************************
//#Defines

#define HW_SYSTIME_INIT(IRQ_HANDLER) 	(hw_SYSTIME_Init(IRQ_HANDLER))
#define HW_SYSTIME_DELAY_US(US)			(hw_SYSTIME_DelayUS(US))


//*******************************************************************
//Typedefs


//*******************************************************************
//External Variables

//*******************************************************************
//Function Prototypes

void hw_SYSTIME_Init(void (*SYSTIME_Callback)(void));
void hw_SYSTIME_DelayUS(uint16_t us);

#endif //HW_SYSTIME_DRV_H_

//END OF hw_SYSTIME_drv.h
