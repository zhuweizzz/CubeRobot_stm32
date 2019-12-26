#ifndef __PWM1_H
#define __PWM1_H

//定时器2 通道1 PA5  


#include "stm32f4xx.h"

#define PWM1_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define PWM1_GPIO_CLK    RCC_AHB1Periph_GPIOA
#define PWM1_GPIO      	GPIOA
#define PWM1_GPIO_Pin  	GPIO_Pin_5
#define PWM1_GPIOSource 	GPIO_PinSource5
#define PWM1_GPIO_AF 			GPIO_AF_TIM2

#define PWM1_TIM_CLK_Cmd RCC_APB1PeriphClockCmd
#define PWM1_TIM_CLK 		RCC_APB1Periph_TIM2
#define PWM1_TIM 				TIM2

void PWM1_GPIO_Init(void);

void PWM1_TIM_Init(void);

void PWM1_Ctrl(u8 flag);

void PWM1_Initialization(void);

void PWM1_SetScale(uint16_t scale);

#endif


