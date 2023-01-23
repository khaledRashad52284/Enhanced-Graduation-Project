################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../GIE.c \
../LCD.c \
../LCD_cfg.c \
../Service.c \
../TIM1.c \
../TIM2.c \
../main.c 

OBJS += \
./DIO.o \
./GIE.o \
./LCD.o \
./LCD_cfg.o \
./Service.o \
./TIM1.o \
./TIM2.o \
./main.o 

C_DEPS += \
./DIO.d \
./GIE.d \
./LCD.d \
./LCD_cfg.d \
./Service.d \
./TIM1.d \
./TIM2.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


