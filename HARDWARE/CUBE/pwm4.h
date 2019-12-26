#ifndef _PWM4_H
#define _PWM4_H

//定时器5 通道1 PA0

#include "stm32f4xx.h"

#define PWM4_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define PWM4_GPIO_CLK    RCC_AHB1Periph_GPIOA
#define PWM4_GPIO      	GPIOA
#define PWM4_GPIO_Pin  	GPIO_Pin_0
#define PWM4_GPIOSource 	GPIO_PinSource0
#define PWM4_GPIO_AF 			GPIO_AF_TIM5

#define PWM4_TIM_CLK_Cmd RCC_APB1PeriphClockCmd
#define PWM4_TIM_CLK 		RCC_APB1Periph_TIM5
#define PWM4_TIM 				TIM5

void PWM4_GPIO_Init(void);

void PWM4_TIM_Init(void);

void PWM4_Ctrl(u8 flag);

void PWM4_Initialization(void);

void PWM4_SetScale(uint16_t scale);


#endif
