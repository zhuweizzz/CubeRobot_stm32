#ifndef _PWM5_H
#define _PWM5_H

//定时器5 通道2 PA1

#include "stm32f4xx.h"

#define PWM5_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define PWM5_GPIO_CLK    RCC_AHB1Periph_GPIOA
#define PWM5_GPIO      	GPIOA
#define PWM5_GPIO_Pin  	GPIO_Pin_1
#define PWM5_GPIOSource 	GPIO_PinSource1
#define PWM5_GPIO_AF 			GPIO_AF_TIM5

#define PWM5_TIM_CLK_Cmd RCC_APB1PeriphClockCmd
#define PWM5_TIM_CLK 		RCC_APB1Periph_TIM5
#define PWM5_TIM 				TIM5

void PWM5_GPIO_Init(void);

void PWM5_TIM_Init(void);

void PWM5_Ctrl(u8 flag);

void PWM5_Initialization(void);

void PWM5_SetScale(uint16_t scale);


#endif
