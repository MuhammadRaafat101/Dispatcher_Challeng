/*
 * TMU.c
 *
 *  Created on: Oct 12, 2019
 *      Author: Mina
 */

#include "TIMER.h"
#include "TIMER_Cnfg.h"
#include <stdlib.h>
#include "TMU.h"
#include "Std_Types.h"

uint8 start_counter = 0;
uint8 ISR_counter = 1;
uint8 Dispatcher_counter;

EnmTMUError_t TMU_Init (TMU_ConfigType *ConfigPtr, uint8 resolution)
{

	Timer_Init (ConfigPtr -> TIMER_ID);
	(ConfigPtr -> Timer_Resolution) = resolution;
	Timer_Start(ConfigPtr -> TIMER_ID);
	return OK;
}

void TMU_Start_Time(uint8 Time, void (*func_ptr)(void), TMU_Func_t func_type,TMU_ConfigType *ConfigPtr)
{
	Timer_Start(ConfigPtr -> TIMER_ID);
	(Buffer[start_counter]).func_ptr = func_ptr;
	(Buffer[start_counter]).Func_time = Dispatcher_counter + Time;
	(Buffer[start_counter]).func_type = func_type;
	(Buffer[start_counter]).func_status = ACTIVE;
}

void TMU_Dispatcher ()
{
	uint8 counter;
	for (counter = 0; counter < MAX_FUNC_NUMBER; counter++)
	{
		if (((Buffer[counter]).func_status) == ACTIVE)
		{
			if ((Buffer[counter]).Func_time == Dispatcher_counter)
			{
				(Buffer[counter]).func_ptr;
			}
		}
	}
}

void TMU_StopTimer (void (*func_ptr)(void))

{
	uint8 counter;
	if (((Buffer[counter]).func_status) == ACTIVE)
	{
		for (counter = 0; counter < MAX_FUNC_NUMBER; counter++)
		{
			if (((Buffer[counter]).func_ptr) == func_ptr)
			{
				((Buffer[counter]).func_status) = NOT_ACTIVE;
			}
		}
	}

}


ISR(TIMER0_OVF_vect)
{
	ISR_counter++;
	if ((ISR_counter%4) == 0)
	{
		Dispatcher_counter++;
		ISR_counter = 0;
	}
}

