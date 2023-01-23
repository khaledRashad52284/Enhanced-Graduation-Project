#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>

#include "DIO_priv.h"
#include "Service_priv.h"
#include "Service.h"
#include "TIM1_priv.h"
#include "TIM1.h"
#include "TIM2.h"
#include "DIO.h"
#include "GIE.h"
#include "LCD.h"

/*
extern volatile uint32 Rising_time,Falling_time,In_between_time,distance;
extern volatile uint8 count;
extern volatile uint8 degree;
*/
volatile uint32 Rising_time=0,Falling_time=0,In_between_time=0,distance=0 ;
volatile uint8 count=0;
volatile uint8 degree= STRAIGHT ;


void Timer1_OVFISR(void)
{
	count++;
}

void Ultrasonic_Trigger(void)
{
	TIM1_voidICURisingEdgeSellect();
	DIO_enuWritePin(31,DIO_HIGH);
	_delay_us(100);
	DIO_enuWritePin(31,DIO_LOW);
}

uint32 u32Ultrasonic_calculations(void)
{
	return (float32)((In_between_time*340)/20000);
}

void Timer1_ICUISR(void)
{
	static uint8 Rising=1;

	if(Rising==1)
	{
		count=0;

		Rising_time=ICR1+count*0xFFFF;

		TIM1_voidICUFallingEdgeSellect();
		Rising=0;

	}
	else if (Rising==0)
	{
		Falling_time=ICR1+(count*65527);
		TIM1_voidICURisingEdgeSellect();
		Rising=1;
		In_between_time=Falling_time-Rising_time;
		distance=u32Ultrasonic_calculations();

	}


}

void timer2_OVFISR(void)
{
    static uint16 OVFCount=0;
    TIM2_voidSetTimerValue(167);
    OVFCount++;
    if(OVFCount == 200)
    {
    	DIO_enuWritePin(DIO_PIN_NUM_19,DIO_HIGH);
        OVFCount=0;
    }
    switch(degree)
    {
    case LEFT_TURN:
    	if(OVFCount==13)
        	DIO_enuWritePin(DIO_PIN_NUM_19,DIO_LOW);
    	break;
    case STRAIGHT:
    	if(OVFCount==15)
        	DIO_enuWritePin(DIO_PIN_NUM_19,DIO_LOW);
    	break;
    case RIGHT_TURN:
    	if(OVFCount==17)
        	DIO_enuWritePin(DIO_PIN_NUM_19,DIO_LOW);
    	break;
    }

}

void Go_forward(uint16 time)
{
	DIO_enuWritePin(DIO_PIN_NUM_12,DIO_HIGH);
	DIO_enuWritePin(DIO_PIN_NUM_14,DIO_HIGH);

	DIO_enuWritePin(DIO_PIN_NUM_13,DIO_LOW);
	DIO_enuWritePin(DIO_PIN_NUM_15,DIO_LOW);
	_delay_ms(time);
}
void Stop(uint16 time)
{
	DIO_enuWritePin(DIO_PIN_NUM_12,DIO_LOW);
	DIO_enuWritePin(DIO_PIN_NUM_13,DIO_LOW);
	DIO_enuWritePin(DIO_PIN_NUM_14,DIO_LOW);
	DIO_enuWritePin(DIO_PIN_NUM_15,DIO_LOW);
	_delay_ms(time);

}
void Go_back(uint16 time)
{
	DIO_enuWritePin(DIO_PIN_NUM_12,DIO_LOW);
	DIO_enuWritePin(DIO_PIN_NUM_14,DIO_LOW);

	DIO_enuWritePin(DIO_PIN_NUM_13,DIO_HIGH);
	DIO_enuWritePin(DIO_PIN_NUM_15,DIO_HIGH);
	_delay_ms(time);

}
void Servo_Degree(uint8 Turn,uint16 time)
{
	degree = Turn;
	_delay_ms(time);
}
