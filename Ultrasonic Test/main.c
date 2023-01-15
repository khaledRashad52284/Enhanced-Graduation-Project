#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>

#include "TIM1_priv.h"
#include "TIM1.h"
#include "DIO.h"
#include "GIE.h"
#include "LCD.h"

volatile uint32 Rising_time=0,Falling_time=0,In_between_time=0;
volatile uint8 count=0;
void Timer1_OVFISR(void)
{
	count++;
}
void Ultrasonic_Trigger(void)
{
	TIM1_voidICURisingEdgeSellect();
	TIM1_voidSetTimerValue(0);
	DIO_enuWritePin(31,DIO_HIGH);
	_delay_us(100);
	DIO_enuWritePin(31,DIO_LOW);
}
float32 u32Ultrasonic_calculations(void)
{
	return (float32)((In_between_time*340)/2000000);
}
void Timer1_ICUISR(void)
{
	static uint8 Rising=1;

	if(Rising==1)
	{
		Rising_time=ICR1;
		TIM1_voidICUFallingEdgeSellect();
		Rising=0;
		count=0;
	}
	else if (Rising==0)
	{
		Falling_time=ICR1+count*0xFFFF;
		//TIM1_voidICURisingEdgeSellect();
		Rising=1;
		In_between_time=Falling_time-Rising_time;
	}


}
int main()
{
	float32 distance=0;
	DIO_voidInit();
	LCD_voidInit();
	TIM1_voidInit();
	TIM1_voidEnable(2);
	TIM1_voidICURisingEdgeSellect();
	TIM1_voidEnableInputCaptureInt();
	TIM1_voidSetCallbackInputCaptureInt(Timer1_ICUISR);
	TIM1_voidSetCallbackOvfInt(Timer1_OVFISR);
	GIE_voidEnable();
	while(1)
	{
		Ultrasonic_Trigger();
		_delay_ms(100);

		distance=u32Ultrasonic_calculations();

		LCD_voidDisplayChar(0,'((distance)/100)');
		LCD_voidDisplayChar(0,'((distance)%100)/10');
		LCD_voidDisplayChar(0,'(((distance)%100)%10)');
		_delay_ms(10000);
	}

}



