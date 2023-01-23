#include "STD_Types.h"
#include "BIT_Math.h"
#include <util/delay.h>

#include "DIO_priv.h"
#include "Service_priv.h"
#include "Service.h"
#include "TIM2.h"
#include "TIM1.h"
#include "DIO.h"
#include "GIE.h"
#include "LCD.h"

/*
volatile uint32 Rising_time=0,Falling_time=0,In_between_time=0,distance=25;
volatile uint8 count=0;
volatile uint8 degree= STRAIGHT ;
*/

int main()
{
	DIO_voidInit();
	LCD_voidInit();

	TIM1_voidInit();
	TIM2_voidInit();

	TIM1_voidEnable(2);
	TIM2_voidEnable(2);

	TIM1_voidEnableOvfInt();
	TIM1_voidEnableInputCaptureInt();


	TIM1_voidSetCallbackInputCaptureInt(Timer1_ICUISR);
	TIM1_voidSetCallbackOvfInt(Timer1_OVFISR);

	TIM2_voidEnableOvfInt();
	TIM2_voidSetCallbackOvfInt(timer2_OVFISR);
    TIM2_voidSetTimerValue(167);




	GIE_voidEnable();

	while(1)
	{
		degree=STRAIGHT;
		Go_forward(0);


		Ultrasonic_Trigger();

		_delay_ms(20);

		LCD_voidWriteCmd(0,0x01);
		LCD_voidWriteCmd(0,0x80);
		LCD_voidDisplayChar(0,'D');
		LCD_voidDisplayChar(0,'i');
		LCD_voidDisplayChar(0,'s');
		LCD_voidDisplayChar(0,'t');
		LCD_voidDisplayChar(0,'a');
		LCD_voidDisplayChar(0,'n');
		LCD_voidDisplayChar(0,'c');
		LCD_voidDisplayChar(0,'e');
		LCD_voidDisplayChar(0,'=');


		if((distance/100)!=0)
		{
		LCD_voidDisplayChar(0,((distance)/100)+48);
		}
		LCD_voidDisplayChar(0,(((distance)%100)/10)+48);
		LCD_voidDisplayChar(0,(((distance)%10))+48);



		if( ( GET_BIT(IDRC,DIO_PIN_NUM_0)==1) && (GET_BIT(IDRC,DIO_PIN_NUM_1)==1) && (distance >= 20) )
				{
					Stop(50);

					LCD_voidWriteCmd(0,0x01);
					LCD_voidWriteCmd(0,0x80);
					LCD_voidDisplayChar(0,'P');
					LCD_voidDisplayChar(0,'a');
					LCD_voidDisplayChar(0,'r');
					LCD_voidDisplayChar(0,'k');
					LCD_voidDisplayChar(0,'i');
					LCD_voidDisplayChar(0,'n');
					LCD_voidDisplayChar(0,'g');
					LCD_voidDisplayChar(0,' ');
					LCD_voidDisplayChar(0,'M');
					LCD_voidDisplayChar(0,'o');
					LCD_voidDisplayChar(0,'d');
					LCD_voidDisplayChar(0,'e');

					_delay_ms(500);

					Servo_Degree(STRAIGHT,500);
					Go_forward(2000);
					Stop(50);

					Servo_Degree(RIGHT_TURN,500);
					Go_back(2000);
					Stop(50);

					Servo_Degree(LEFT_TURN,500);
					Go_back(1000);
					Stop(50);


					Servo_Degree(STRAIGHT,500);
					Go_forward(500);
					Stop(50);



					LCD_voidWriteCmd(0,0x01);
					LCD_voidWriteCmd(0,0x80);
					LCD_voidDisplayChar(0,'P');
					LCD_voidDisplayChar(0,'a');
					LCD_voidDisplayChar(0,'r');
					LCD_voidDisplayChar(0,'k');
					LCD_voidDisplayChar(0,'e');
					LCD_voidDisplayChar(0,'d');

					while(1)
					{

					}
				}




	}


	return 0;
}
