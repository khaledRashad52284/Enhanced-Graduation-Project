#ifndef SERVICE_H
#define SERVICE_H

extern volatile uint32 Rising_time,Falling_time,In_between_time,distance;
extern volatile uint8 count;
extern volatile uint8 degree;



void Timer1_OVFISR(void);
void Ultrasonic_Trigger(void);
uint32 u32Ultrasonic_calculations(void);
void Timer1_ICUISR(void);
void timer2_OVFISR(void);
void Servo_Degree(uint8 Turn,uint16 time);
void Go_back(uint16 time);
void Stop(uint16 time);
void Go_forward(uint16 time);













#endif
