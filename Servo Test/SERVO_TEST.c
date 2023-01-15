
#include <stdio.h>

#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>
#include "DIO.h"
//#include "LCD.h"
#include "TIM2.h"
#include "GIE.h"
#include "main_priv.h"

volatile uint8 degree= STRAIGHT ;
void timer2_OVFISR(void)
{

    static uint16 OVFCount=0;
    TIM2_voidSetTimerValue(167);
    OVFCount++;
    if(OVFCount == 200)
    {
    	DIO_enuWritePin(DIO_PIN_NUM_24,DIO_HIGH);
        OVFCount=0;
    }
    switch(degree)
    {
    case LEFT_TURN:
    	if(OVFCount==13)
        	DIO_enuWritePin(DIO_PIN_NUM_24,DIO_LOW);
    	break;
    case STRAIGHT:
    	if(OVFCount==15)
        	DIO_enuWritePin(DIO_PIN_NUM_24,DIO_LOW);
    	break;
    case RIGHT_TURN:
    	if(OVFCount==17)
        	DIO_enuWritePin(DIO_PIN_NUM_24,DIO_LOW);
    	break;
    }

}

void main(void)
{
	DIO_voidInit();
	TIM2_voidInit();
	DIO_enuWritePin(DIO_PIN_NUM_24,DIO_HIGH);

	//prescalar =8
	TIM2_voidEnable(2);
	TIM2_voidSetCallbackOvfInt(timer2_OVFISR);
	//to start counting again
	TIM2_voidSetTimerValue(167);
	TIM2_voidEnableOvfInt();
	GIE_voidEnable();
	//degree= RIGHT_TURN;
	while(1)
	{

	}
}
