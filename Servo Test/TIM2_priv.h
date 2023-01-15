#ifndef TIM2_PRIV_H
#define TIM2_PRIV_H

#define TIM2_NORMAL       1
#define TIM2_CTC          2
#define TIM2_PHASE_PWM    3
#define TIM2_FAST_PWM     4


#define TIM2_TOGL_OC2        1
#define TIM2_SET_OC2         2
#define TIM2_CLR_OC2        3
#define TIM2_F_NON_INVERT    4
#define TIM2_F_INVERT        5
#define TIM2_PH_NON_INVERT   6
#define TIM2_PH_INVERT       7
#define TIM2_DISCONNECT      8


#define TCCR2   *((volatile uint8 *) 0x45 )

#define TCCR2_CS20   0
#define TCCR2_CS21   1
#define TCCR2_CS22   2

#define TCCR2_WGM21  3
#define TCCR2_WGM20  6

#define TCCR2_COM20  4
#define TCCR2_COM21  5

#define TCNT2   *((volatile uint8 *) 0x44 )
#define OCR2    *((volatile uint8 *) 0x43 )
#define TIMSK   *((volatile uint8 *) 0x59 )
#define TIMSK_TOIE2  6
#define TIMSK_OCIE2  7

#define TIFR    *((volatile uint8 *) 0x58 )
#define TIFR_TOV2   6
#define TIFR_OCF2   7



#endif