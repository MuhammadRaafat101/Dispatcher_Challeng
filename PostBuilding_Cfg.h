/*
 * PostBuilding_Cfg.h
 *
 *  Created on: Oct 12, 2019
 *      Author: Mina
 */

#include "PreCfg.h"


#ifndef POSTBUILDING_CFG_H_
#define POSTBUILDING_CFG_H_

#include "PreCfg.h"
#include "TIMER_Cnfg.h"
typedef enum {TMU_ERROR = -500, TMU_NOK = 0, TMU_OK} EnmTMUError_t;
typedef enum {PERIODIC, ONE_SHOT} TMU_Func_t;
typedef enum {NOT_ACTIVE, ACTIVE}Func_Status_t;


typedef struct TMU_C
{
	uint8 TIMER_ID;
	uint8 Timer_Resolution;
}TMU_ConfigType;

extern TMU_ConfigType TMU_Cfg;


#endif /* POSTBUILDING_CFG_H_ */
