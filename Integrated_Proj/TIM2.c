#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM2.h"
#include "TIM2_cfg.h"
#include "TIM2_priv.h"

pf  TIM2_pfOvfCallBack = NULL;
pf  TIM2_pfCmpCallBack = NULL;

void TIM2_voidInit(void)
{
#if   TIM2_MODE ==  TIM2_NORMAL 
	CLR_BIT(TCCR2 , TCCR2_WGM20);
	CLR_BIT(TCCR2 , TCCR2_WGM21);
#elif TIM2_MODE ==  TIM2_CTC   
	CLR_BIT(TCCR2 , TCCR2_WGM20);
	SET_BIT(TCCR2 , TCCR2_WGM21);
#elif TIM2_MODE ==  TIM2_PHASE_PWM 
    SET_BIT(TCCR2 , TCCR2_WGM20);
	CLR_BIT(TCCR2 , TCCR2_WGM21);
#elif TIM2_MODE == TIM2_FAST_PWM
	SET_BIT(TCCR2 , TCCR2_WGM20);
	SET_BIT(TCCR2 , TCCR2_WGM21);
#endif 

#if   TIM2_OUTFORM == TIM2_TOGL_OC2 
    SET_BIT(TCCR2 , TCCR2_COM20);
	CLR_BIT(TCCR2 , TCCR2_COM21);
#elif TIM2_OUTFORM == TIM2_SET_OC2 
    SET_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);     
#elif TIM2_OUTFORM == TIM2_CLR_OC2
    CLR_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);      
#elif TIM2_OUTFORM == TIM2_F_NON_INVERT
    CLR_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21); 
#elif TIM2_OUTFORM == TIM2_F_INVERT  
    SET_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);    
#elif TIM2_OUTFORM == TIM2_PH_NON_INVERT
    CLR_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21); 
#elif TIM2_OUTFORM == TIM2_PH_INVERT 
    SET_BIT(TCCR2 , TCCR2_COM20);
	SET_BIT(TCCR2 , TCCR2_COM21);    
#else
	CLR_BIT(TCCR2 , TCCR2_COM20);
	CLR_BIT(TCCR2 , TCCR2_COM21); 
#endif
  /*Disable timer*/
  TCCR2 &= 0b11111000;
  /*Disable Int OVF-CMP*/
  CLR_BIT(TIMSK , TIMSK_TOIE2  );
  CLR_BIT(TIMSK , TIMSK_OCIE2 );
  /*Clear Int OVF-CMP flags*/
  SET_BIT(TIFR , TIFR_TOV2 );
  SET_BIT(TIFR , TIFR_OCF2 );
  
  /*Clear TCNT*/
  TCNT2 = 0 ;
  OCR2  = 0 ;
  

}
void TIM2_voidEnable(uint8 u8PrescalValCpy)
{
	TCCR2 &= 0b11111000;
	TCCR2 |= u8PrescalValCpy & 0x07 ;
	
}
void TIM2_voidDisable(void)
{
	TCCR2 &= 0b11111000;
}
void TIM2_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK , TIMSK_TOIE2 );
}
void TIM2_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK , TIMSK_TOIE2 );
}
void TIM2_voidEnableCmpInt(void)
{
	SET_BIT(TIMSK , TIMSK_OCIE2);
}
void TIM2_voidDisableCmpInt(void)
{
	CLR_BIT(TIMSK , TIMSK_OCIE2 );
}
void TIM2_voidSetCallbackOvfInt(pf pfOvfCalbckCpy)
{
	TIM2_pfOvfCallBack = pfOvfCalbckCpy;
}
void TIM2_voidSetCallbackCmpInt(pf pfCmpCalbckCpy)
{
	TIM2_pfCmpCallBack = pfCmpCalbckCpy ;
}
void TIM2_voidSetTimerValue(uint8 u8TimValCpy)
{
	TCNT2 = u8TimValCpy ;
}
void TIM2_voidSetCmpRegValue(uint8 u8CmpValCpy)
{
	OCR2 = u8CmpValCpy ;
}
uint8 TIM2_u8ReadTimerValue(void)
{
	return TCNT2 ;
}
/*OVF ISR*/
void __vector_5 (void) __attribute__ ((signal,used));
void __vector_5 (void)
{
	if(TIM2_pfOvfCallBack != NULL )
	{
	   TIM2_pfOvfCallBack();
	}
	
}
/*CM ISR */
void __vector_4 (void) __attribute__ ((signal,used));
void __vector_4 (void)
{
	if(TIM2_pfCmpCallBack != NULL)
	{
	   TIM2_pfCmpCallBack();
	}
	
}
