#ifndef _PWM8_H
#define _PWM8_H

//定时器3 通道2 PC7

#include "stm32f4xx.h"

#define PWM8_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define PWM8_GPIO_CLK    RCC_AHB1Periph_GPIOC
#define PWM8_GPIO      	GPIOC
#define PWM8_GPIO_Pin  	GPIO_Pin_7
#define PWM8_GPIOSource 	GPIO_PinSource7
#define PWM8_GPIO_AF 			GPIO_AF_TIM3

#define PWM8_TIM_CLK_Cmd RCC_APB1PeriphClockCmd
#define PWM8_TIM_CLK 		RCC_APB1Periph_TIM3
#define PWM8_TIM 				TIM3

void PWM8_GPIO_Init(void);

void PWM8_TIM_Init(void);

void PWM8_Ctrl(u8 flag);

void PWM8_Initialization(void);

void PWM8_SetScale(uint16_t scale);


#endif

