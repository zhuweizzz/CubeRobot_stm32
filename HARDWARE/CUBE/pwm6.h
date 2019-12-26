#ifndef _PWM6_H
#define _PWM6_H

//定时器5 通道3 PA2

#include "stm32f4xx.h"

#define PWM6_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define PWM6_GPIO_CLK    RCC_AHB1Periph_GPIOA
#define PWM6_GPIO      	GPIOA
#define PWM6_GPIO_Pin  	GPIO_Pin_2
#define PWM6_GPIOSource 	GPIO_PinSource2
#define PWM6_GPIO_AF 			GPIO_AF_TIM5

#define PWM6_TIM_CLK_Cmd RCC_APB1PeriphClockCmd
#define PWM6_TIM_CLK 		RCC_APB1Periph_TIM5
#define PWM6_TIM 				TIM5

void PWM6_GPIO_Init(void);

void PWM6_TIM_Init(void);

void PWM6_Ctrl(u8 flag);

void PWM6_Initialization(void);

void PWM6_SetScale(uint16_t scale);


#endif

