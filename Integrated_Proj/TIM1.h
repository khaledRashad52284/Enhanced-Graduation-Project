#ifndef TIM1_H
#define TIM1_H

void TIM1_voidInit(void);
void TIM1_voidEnable(uint8 u8PrescalValCpy);
void TIM1_voidDisable(void);

TIM1_voidICUFallingEdgeSellect();
TIM1_voidICURisingEdgeSellect();


void TIM1_voidEnableOvfInt(void);
void TIM1_voidDisableOvfInt(void);
void TIM1_voidEnableCmpIntA(void);
void TIM1_voidDisableCmpIntA(void);
void TIM1_voidEnableCmpIntB(void);
void TIM1_voidDisableCmpIntB(void);
void TIM1_voidEnableInputCaptureInt(void);
void TIM1_voidDisableInputCaptureInt(void);

void TIM1_voidSetCallbackOvfInt(pf pfOvfCalbckCpy);
void TIM1_voidSetCallbackInputCaptureInt(pf pfInputCaptureCalbckCpy);
void TIM1_voidSetCallbackCmpIntA(pf pfCmpACalbckCpy);
void TIM1_voidSetCallbackCmpIntB(pf pfCmpBCalbckCpy);

void TIM1_voidSetTimerValue(uint16 u16TimValCpy);
void TIM1_voidSetCmpARegValue(uint16 u16CmpAValCpy);
void TIM1_voidSetCmpBRegValue(uint16 u16CmpBValCpy);
uint16 TIM1_u16ReadTimerValue(void);

#endif
