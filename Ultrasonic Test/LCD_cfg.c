/***************************************/
/* Description : LCD config header File*/
/* Author      : kpit                  */
/* Version     : 0.1V                  */
/* Date        : 13:45:20  03 Dec 2022 */
/* History     : 0.1V Initial Creation */
/***************************************/
#include "STD_Types.h"

#include "DIO.h"
#include "LCD_cfg.h"
#include "LCD_priv.h"


tstrLcdConfigset  LCD_astrConfigSet[LCD_MAX_NUM]=
{
	/* Configuration for LCD 0     */
	{
		/* Hw config configuration */
		{
			LCD_8BIT_MODE  ,  LCD_TWO_LINES  , LCD_FONT_5X7 ,
			LCD_DISPLAY_ON ,  LCD_CURSOR_OFF , LCD_CURSOR_BLINK_OFF ,
			LCD_RTL        ,  LCD_SHIFT_OFF
		}
		,
		/* connection configuration */
		{
				/* Rs             Rw                En      */
				DIO_PIN_NUM_10 , DIO_PIN_NUM_9 , DIO_PIN_NUM_8   ,
				
				/*Data array*/
				{
					/* D0             D1            D2            D3          */
					DIO_PIN_NUM_0 , DIO_PIN_NUM_1 ,DIO_PIN_NUM_2,DIO_PIN_NUM_3,
					
					/* D4             D5               D6             D7         */
					DIO_PIN_NUM_4, DIO_PIN_NUM_5,DIO_PIN_NUM_6,DIO_PIN_NUM_7
				}
			
			
		}
	}
	
};















