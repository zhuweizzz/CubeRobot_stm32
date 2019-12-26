#ifndef _PWM7_H
#define _PWM7_H

//定时器3 通道1 PC6

#include "stm32f4xx.h"

#define PWM7_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define PWM7_GPIO_CLK    RCC_AHB1Periph_GPIOC
#define PWM7_GPIO      	GPIOC
#define PWM7_GPIO_Pin  	GPIO_Pin_6
#define PWM7_GPIOSource 	GPIO_PinSource6
#define PWM7_GPIO_AF 			GPIO_AF_TIM3

#define PWM7_TIM_CLK_Cmd RCC_APB1PeriphClockCmd
#define PWM7_TIM_CLK 		RCC_APB1Periph_TIM3
#define PWM7_TIM 				TIM3

void PWM7_GPIO_Init(void);

void PWM7_TIM_Init(void);

void PWM7_Ctrl(u8 flag);

void PWM7_Initialization(void);

void PWM7_SetScale(uint16_t scale);


#endif

