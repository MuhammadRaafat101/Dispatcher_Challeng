/*
 * TIMER.h
 *
 *  Created on: Sep 22, 2019
 *      Author: Rafaat
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Reg.h"
#include "Std_Types.h"
#include "TIMER_cnfg.h"


//typedef enum{NOK,OK}status;

status Timer_Init(uint8 Timer);
void Timer_Start(uint8 Timer);
status Timer_SetPrescaler(uint8 Timer);
void Timer_Stop(uint8 Timer);
//void delay(uint32 delay,uint8 Timer,void (*ptr)(void));


#endif /* TIMER_H_ */
