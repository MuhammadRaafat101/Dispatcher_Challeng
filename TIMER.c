/*
 * TIMER.c
 *
 *  Created on: Sep 22, 2019
 *      Author: Rafaat
 */
#include "TIMER.h"


status Timer_Init(uint8 Timer)
{
	uint8 Status=0;
	switch(Timer)
	{
	case TIMER_0 :
		if(Timer_arr[0].Mode == NORMAL)
		{
			if(Timer_arr[0].Prescaler >  CLK_FALING )
			{
				Status=NOK;
			}else
			{
				TCCR0 |= Timer_arr[0].Prescaler ;
			}
			if(Timer_arr[0].ISR == ISR_EN)
			{
				TIMSK |= 1<<TOIE0; // Interrupt when overflow
			}else
			{
				TIMSK &= ~(1<<TOIE0);
			}
		}
		break;

	case TIMER_1 :
		if(Timer_arr[1].Mode == NORMAL)
		{
			if(Timer_arr[1].Prescaler >  CLK_FALING )
			{
				Status =NOK;
			}else
			{

				TCCR1B |= Timer_arr[1].Prescaler ;
			}

			TCNT1 = Timer_arr[1].CounterLoad;
			if(Timer_arr[1].ISR == ISR_EN)
			{
				TIMSK |= 1<<TOIE1; // Interrupt when overflow
			}else
			{
				TIMSK &= ~(1<<TOIE1);
			}
		}
		break;
	case TIMER_2 :
		if(Timer_arr[2].Mode == NORMAL)
		{
			if(Timer_arr[2].Prescaler < CLK_FALING )
			{
				TCCR2 |= Timer_arr[2].Prescaler ;
			}else
			{
				Status =NOK;
			}

			TCNT2 = Timer_arr[2].CounterLoad;
			if(Timer_arr[2].ISR == ISR_EN)
			{
				TIMSK |= 1<<TOIE2; // Interrupt when overflow
			}else
			{
				TIMSK &= ~(1<<TOIE2);
			}
		}
		break;
	}
	return Status;
}

void Timer_Start(uint8 Timer)
{
	switch(Timer)
	{
	case TIMER_0 :
		TCCR0 |= Timer_arr[0].Prescaler ;
		break;
	case TIMER_1 :
		TCCR1B |= Timer_arr[1].Prescaler ;
		break;
	case TIMER_2 :
		TCCR2 |= Timer_arr[2].Prescaler ;
		break;
	}
}
void Timer_Stop(uint8 Timer)
{
	switch(Timer)
	{
	case TIMER_0 :
	TCCR0 &= ~(1<< CS00);
	TCCR0 &= ~(1<< CS01);
	TCCR0 &= ~(1<< CS02);
		break;
	case TIMER_1 :
		TCCR1B &= ~(1<< CS10);
		TCCR1B &= ~(1<< CS11);
		TCCR1B &= ~(1<< CS12);

		break;
	case TIMER_2 :
		TCCR2 &= ~(1<< CS20);
		TCCR2 &= ~(1<< CS21);
		TCCR2 &= ~(1<< CS22);
		break;
	}
}
