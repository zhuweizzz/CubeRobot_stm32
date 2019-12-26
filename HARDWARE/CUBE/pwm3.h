#ifndef _PWM3_H
#define _PWM3_H

//定时器2 通道3 PB10

#include "stm32f4xx.h"

#define PWM3_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define PWM3_GPIO_CLK    RCC_AHB1Periph_GPIOB
#define PWM3_GPIO      	GPIOB
#define PWM3_GPIO_Pin  	GPIO_Pin_10
#define PWM3_GPIOSource 	GPIO_PinSource10
#define PWM3_GPIO_AF 			GPIO_AF_TIM2

#define PWM3_TIM_CLK_Cmd RCC_APB1PeriphClockCmd
#define PWM3_TIM_CLK 		RCC_APB1Periph_TIM2
#define PWM3_TIM 				TIM2

void PWM3_GPIO_Init(void);

void PWM3_TIM_Init(void);

void PWM3_Ctrl(u8 flag);

void PWM3_Initialization(void);

void PWM3_SetScale(uint16_t scale);


#endif


