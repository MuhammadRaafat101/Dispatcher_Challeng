


#include "timer.h"
#include "dio.h"
#include "TMU.h"
#include <avr/interrupt.h>

uint8_t flag =0;
uint8_t counter=0;
void System_Init();
void Led1_Toggle();
void Led2_Toggle();
int main(void){

System_Init();

sei();
while(1)
{
TMU_Dispatcher();

}
	return 0;
}


void System_Init()
		{

		TMU_Init(&TMU_Cfg,1);

		TMU_Start_Time(5,Led1_Toggle, PERIODIC,&TMU_Cfg);
		TMU_Start_Time(10,Led2_Toggle, PERIODIC,&TMU_Cfg);
		Dio_init();
		}
void Led1_Toggle()
{
	PORTA ^=1<<PIN0;
}
void Led2_Toggle()
{
	PORTA ^=1<<PIN1;
}
