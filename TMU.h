/*
 * TMU.h
 *
 *  Created on: Oct 12, 2019
 *      Author: Mina
 */

#ifndef TMU_H_
#define TMU_H_

#include "PostBuilding_Cfg.h"

#define ISR_FREQ 4

typedef struct Func_pointer
{
	void (*func_ptr)(void);
	uint8 Func_time;
	TMU_Func_t func_type;
	Func_Status_t func_status;
	uint8 start_time;
}Func_Ptr;

Func_Ptr Buffer[MAX_FUNC_NUMBER];



EnmTMUError_t TMU_Init (TMU_ConfigType *ConfigPtr, uint8 resolution);
void TMU_Dispatcher(void);
void TMU_Start_Time (uint8 Time, void (*func_ptr)(void), TMU_Func_t func_type,TMU_ConfigType *ConfigPtr);
void TMU_StopTimer (void (*func_ptr)(void));



#endif /* TMU_H_ */
