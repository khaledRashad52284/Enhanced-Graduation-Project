#ifndef TIM1_PRIV_H
#define TIM1_PRIV_H

#define TIM1_NORMAL            1
#define TIM1_CTC_OCR_TOP       2
#define TIM1_CTC_ICR_TOP       3

#define TIM1_PHASE_PWM_8bit    4
#define TIM1_PHASE_PWM_9bit    5
#define TIM1_PHASE_PWM_10bit   6

#define TIM1_FAST_PWM_8bit     7
#define TIM1_FAST_PWM_9bit     8
#define TIM1_FAST_PWM_10bit    9



#define TIM1_TOGL_OC1        1
#define TIM1_SET_OC1         2
#define TIM1_CLR_OC1         3
#define TIM1_F_NON_INVERT    4
#define TIM1_F_INVERT        5
#define TIM1_PH_NON_INVERT   6
#define TIM1_PH_INVERT       7
#define TIM1_DISCONNECT      8


#define TCCR1A   *((volatile uint8 *) 0x4F )
#define TCCR1A_WGM10     0
#define TCCR1A_WGM11     1
#define TCCR1A_COM1B0    4
#define TCCR1A_COM1B1    5
#define TCCR1A_COM1A0    6
#define TCCR1A_COM1A1    7




#define TCCR1B   *((volatile uint8 *) 0x4E )



#define TCCR1B_CS10      0
#define TCCR1B_CS11      1
#define TCCR1B_CS12      2
#define TCCR1B_WGM12     3
#define TCCR1B_WGM13     4
#define TCCR1B_ICES1     6
#define TCCR1B_ICNC1     7

#define TCNT1    *((volatile uint16 *) 0x4C )

#define OCR1A    *((volatile uint16 *) 0x4A )

#define OCR1B    *((volatile uint16 *) 0x48 )

#define ICR1     *((volatile uint16 *) 0x46 )



#define TIMSK   *((volatile uint8 *) 0x59 )
#define TIMSK_TOIE1   2
#define TIMSK_OCIE1B  3
#define TIMSK_OCIE1A  4
#define TIMSK_TICIE1  5

#define TIFR    *((volatile uint8 *) 0x58 )
#define TIFR_TOV1     2 
#define TIFR_OCF1B    3
#define TIFR_OCF1A    4
#define TIFR_ICF1     5

#endif
