#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM1.h"
#include "TIM1_cfg.h"
#include "TIM1_priv.h"

pf  TIM1_pfOvfCallBack = NULL;
pf  TIM1_pfCmpACallBack = NULL;
pf  TIM1_pfCmpBCallBack = NULL;
pf  TIM1_pfInputCapturefCallBack = NULL;


void TIM1_voidInit(void)
{
#if   TIM1_MODE ==  TIM1_NORMAL 
	CLR_BIT(TCCR1A , TCCR1A_WGM10);
	CLR_BIT(TCCR1A , TCCR1A_WGM11);
	CLR_BIT(TCCR1B , TCCR1B_WGM12);
	CLR_BIT(TCCR1B , TCCR1B_WGM13);

#elif TIM1_MODE ==  TIM1_CTC   
	CLR_BIT(TCCR1A , TCCR1A_WGM10);
	CLR_BIT(TCCR1A , TCCR1A_WGM11);
	SET_BIT(TCCR1B , TCCR1B_WGM12);
	CLR_BIT(TCCR1B , TCCR1B_WGM13);
#elif TIM1_MODE ==  TIM1_PHASE_PWM
    #if TIM_PHASE_PWM_MODE == TIM1_PHASE_PWM_8bit
	   SET_BIT(TCCR1A , TCCR1A_WGM10);
	   CLR_BIT(TCCR1A , TCCR1A_WGM11);
	   CLR_BIT(TCCR1B , TCCR1B_WGM12);
	   CLR_BIT(TCCR1B , TCCR1B_WGM13);
    #elif TIM_PHASE_PWM_MODE == TIM1_PHASE_PWM_9bit
	   CLR_BIT(TCCR1A , TCCR1A_WGM10);
	   SET_BIT(TCCR1A , TCCR1A_WGM11);
	   CLR_BIT(TCCR1B , TCCR1B_WGM12);
	   CLR_BIT(TCCR1B , TCCR1B_WGM13);
    #elif TIM_PHASE_PWM_MODE == TIM1_PHASE_PWM_10bit
       SET_BIT(TCCR1A , TCCR1A_WGM10);
       SET_BIT(TCCR1A , TCCR1A_WGM11);
       CLR_BIT(TCCR1B , TCCR1B_WGM12);
       CLR_BIT(TCCR1B , TCCR1B_WGM13);
	#endif
#elif TIM1_MODE == TIM1_FAST_PWM
    #if TIM_PHASE_PWM_MODE == TIM1_FAST_PWM_8bit
	   SET_BIT(TCCR1A , TCCR1A_WGM10);
	   CLR_BIT(TCCR1A , TCCR1A_WGM11);
	   SET_BIT(TCCR1B , TCCR1B_WGM12);
	   CLR_BIT(TCCR1B , TCCR1B_WGM13);
    #elif TIM_PHASE_PWM_MODE == TIM1_FAST_PWM_9bit
	   CLR_BIT(TCCR1A , TCCR1A_WGM10);
	   SET_BIT(TCCR1A , TCCR1A_WGM11);
	   SET_BIT(TCCR1B , TCCR1B_WGM12);
	   CLR_BIT(TCCR1B , TCCR1B_WGM13);
    #elif TIM_PHASE_PWM_MODE == TIM1_FAST_PWM_10bit
       SET_BIT(TCCR1A , TCCR1A_WGM10);
       SET_BIT(TCCR1A , TCCR1A_WGM11);
       SET_BIT(TCCR1B , TCCR1B_WGM12);
       CLR_BIT(TCCR1B , TCCR1B_WGM13);
	#elif TIM_PHASE_PWM_MODE == TIM1_FAST_PWM_ICR_TOP
       CLR_BIT(TCCR1A , TCCR1A_WGM10);
       SET_BIT(TCCR1A , TCCR1A_WGM11);
       SET_BIT(TCCR1B , TCCR1B_WGM12);
       SET_BIT(TCCR1B , TCCR1B_WGM13);
	#elif TIM_PHASE_PWM_MODE == TIM1_FAST_PWM_OCRA_TOP
       SET_BIT(TCCR1A , TCCR1A_WGM10);
       SET_BIT(TCCR1A , TCCR1A_WGM11);
       SET_BIT(TCCR1B , TCCR1B_WGM12);
       SET_BIT(TCCR1B , TCCR1B_WGM13);
	#endif

#endif 

#if   TIM1_OUTFORM == TIM1_TOGL_OC1
    SET_BIT(TCCR1A , TCCR1A_COM1A0);
    SET_BIT(TCCR1A , TCCR1A_COM1B0);
	CLR_BIT(TCCR1A , TCCR1A_COM1A1);
	CLR_BIT(TCCR1A , TCCR1A_COM1B1);

#elif TIM1_OUTFORM == TIM1_SET_OC1
    SET_BIT(TCCR1A , TCCR1A_COM1A0);
    SET_BIT(TCCR1A , TCCR1A_COM1B0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);
	SET_BIT(TCCR1A , TCCR1A_COM1B1);

#elif TIM1_OUTFORM == TIM1_CLR_OC1
    CLR_BIT(TCCR1A , TCCR1A_COM1A0);
    CLR_BIT(TCCR1A , TCCR1A_COM1B0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);
	SET_BIT(TCCR1A , TCCR1A_COM1B1);

#elif TIM1_OUTFORM == TIM1_F_NON_INVERT
    CLR_BIT(TCCR1A , TCCR1A_COM1A0);
    CLR_BIT(TCCR1A , TCCR1A_COM1B0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);
	SET_BIT(TCCR1A , TCCR1A_COM1B1);

#elif TIM1_OUTFORM == TIM1_F_INVERT  
    SET_BIT(TCCR1A , TCCR1A_COM1A0);
    SET_BIT(TCCR1A , TCCR1A_COM1B0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);
	SET_BIT(TCCR1A , TCCR1A_COM1B1);

#elif TIM1_OUTFORM == TIM1_PH_NON_INVERT
    CLR_BIT(TCCR1A , TCCR1A_COM1A0);
    CLR_BIT(TCCR1A , TCCR1A_COM1B0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);
	SET_BIT(TCCR1A , TCCR1A_COM1B1);

#elif TIM1_OUTFORM == TIM1_PH_INVERT 
    SET_BIT(TCCR1A , TCCR1A_COM1A0);
    SET_BIT(TCCR1A , TCCR1A_COM1B0);
	SET_BIT(TCCR1A , TCCR1A_COM1A1);
	SET_BIT(TCCR1A , TCCR1A_COM1B1);

#elif TIM1_DISCONNECT
	CLR_BIT(TCCR1A , TCCR1A_COM1A0);
	CLR_BIT(TCCR1A , TCCR1A_COM1B0);
	CLR_BIT(TCCR1A , TCCR1A_COM1A1); 
	CLR_BIT(TCCR1A , TCCR1A_COM1B1);

#endif
  /*Disable timer*/
  TCCR1A &= 0b11111000;
  /*Disable Int OVF-CMP*/
  CLR_BIT(TIMSK , TIMSK_TOIE1  );
  CLR_BIT(TIMSK , TIMSK_OCIE1A );
  CLR_BIT(TIMSK , TIMSK_OCIE1B );
  CLR_BIT(TIMSK ,TIMSK_TICIE1);
  /*Clear Int OVF-CMP flags*/
  SET_BIT(TIFR , TIFR_TOV1 );
  SET_BIT(TIFR , TIFR_OCF1A );
  SET_BIT(TIFR , TIFR_OCF1B );
  SET_BIT(TIFR , TIFR_ICF1 );

  /*Clear TCNT*/
  TCNT1 = 0 ;
  OCR1A  = 0 ;
  OCR1B  = 0 ;

}
void TIM1_voidEnable(uint8 u8PrescalValCpy)
{
	TCCR1B &= 0b11111000;
	TCCR1B |= u8PrescalValCpy & 0x07 ;
	
}
void TIM1_voidDisable(void)
{
	TCCR1B &= 0b11111000;
}


void TIM1_voidEnableOvfInt(void)
{
	SET_BIT(TIMSK , TIMSK_TOIE1 );
}
void TIM1_voidDisableOvfInt(void)
{
	CLR_BIT(TIMSK , TIMSK_TOIE1 );
}
void TIM1_voidEnableCmpIntA(void)
{
	SET_BIT(TIMSK , TIMSK_OCIE1A);
}
void TIM1_voidDisableCmpIntA(void)
{
	CLR_BIT(TIMSK , TIMSK_OCIE1A );
}
void TIM1_voidEnableCmpIntB(void)
{
	SET_BIT(TIMSK , TIMSK_OCIE1B);
}
void TIM1_voidDisableCmpIntB(void)
{
	CLR_BIT(TIMSK , TIMSK_OCIE1B);
}
void TIM1_voidEnableInputCaptureInt(void)
{
	SET_BIT(TIMSK , TIMSK_TICIE1);
}
void TIM1_voidDisableInputCaptureInt(void)
{
	CLR_BIT(TIMSK , TIMSK_TICIE1);
}





void TIM1_voidSetCallbackOvfInt(pf pfOvfCalbckCpy)
{
	TIM1_pfOvfCallBack = pfOvfCalbckCpy;
}
void TIM1_voidSetCallbackInputCaptureInt(pf pfInputCaptureCalbckCpy)
{
	TIM1_pfInputCapturefCallBack = pfInputCaptureCalbckCpy;
}

void TIM1_voidSetCallbackCmpIntA(pf pfCmpACalbckCpy)
{
	TIM1_pfCmpACallBack = pfCmpACalbckCpy ;
}
void TIM1_voidSetCallbackCmpIntB(pf pfCmpBCalbckCpy)
{
	TIM1_pfCmpBCallBack = pfCmpBCalbckCpy ;
}



void TIM1_voidSetTimerValue(uint16 u16TimValCpy)
{
	TCNT1 = u16TimValCpy ;
}

void TIM1_voidSetCmpARegValue(uint16 u16CmpAValCpy)
{
	OCR1A = u16CmpAValCpy ;
}
void TIM1_voidSetCmpBRegValue(uint16 u16CmpBValCpy)
{
	OCR1A = u16CmpBValCpy ;
}
uint16 TIM1_u16ReadTimerValue(void)
{
	return TCNT1 ;
}

TIM1_voidICUFallingEdgeSellect()
{
	CLR_BIT(TCCR1B , TCCR1B_ICES1);

}
TIM1_voidICURisingEdgeSellect()
{
	SET_BIT(TCCR1B , TCCR1B_ICES1);

}


/*OVF ISR*/
void __vector_9 (void) __attribute__ ((signal,used));
void __vector_9 (void)
{
	if(TIM1_pfOvfCallBack != NULL )
	{
	   TIM1_pfOvfCallBack();
	}
	
}
/*CM ISR */
void __vector_7 (void) __attribute__ ((signal,used));
void __vector_7 (void)
{
	if(TIM1_pfCmpACallBack != NULL)
	{
	   TIM1_pfCmpACallBack();
	}
	
}

void __vector_8 (void) __attribute__ ((signal,used));
void __vector_8 (void)
{
	if(TIM1_pfCmpBCallBack != NULL)
	{
	   TIM1_pfCmpBCallBack();
	}
	
}

void __vector_6 (void) __attribute__ ((signal,used));
void __vector_6 (void)
{
	if(TIM1_pfInputCapturefCallBack != NULL)
	{
	   TIM1_pfInputCapturefCallBack();
	}
	
}
