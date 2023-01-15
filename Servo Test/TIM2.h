#ifndef TIM2_H
#define TIM2_H

void TIM2_voidInit(void);
void TIM2_voidEnable(uint8 u8PrescalValCpy);
void TIM2_voidDisable(void);
void TIM2_voidEnableOvfInt(void);
void TIM2_voidDisableOvfInt(void);
void TIM2_voidEnableCmpInt(void);
void TIM2_voidDisableCmpInt(void);
void TIM2_voidSetCallbackOvfInt(pf pfOvfCalbckCpy);
void TIM2_voidSetCallbackCmpInt(pf pfCmpCalbckCpy);
void TIM2_voidSetTimerValue(uint8 u8TimValCpy);
void TIM2_voidSetCmpRegValue(uint8 u8CmpValCpy);
uint8 TIM2_u8ReadTimerValue(void);


#endif