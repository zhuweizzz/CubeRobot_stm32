#ifndef _PWM2_H
#define _PWM2_H

//定时器2 通道2 PB3

#include "stm32f4xx.h"

#define PWM2_GPIO_CLK_Cmd RCC_AHB1PeriphClockCmd
#define PWM2_GPIO_CLK    RCC_AHB1Periph_GPIOB
#define PWM2_GPIO      	GPIOB
#define PWM2_GPIO_Pin  	GPIO_Pin_3
#define PWM2_GPIOSource 	GPIO_PinSource3
#define PWM2_GPIO_AF 			GPIO_AF_TIM2

#define PWM2_TIM_CLK_Cmd RCC_APB1PeriphClockCmd
#define PWM2_TIM_CLK 		RCC_APB1Periph_TIM2
#define PWM2_TIM 				TIM2

void PWM2_GPIO_Init(void);

void PWM2_TIM_Init(void);

void PWM2_Ctrl(u8 flag);

void PWM2_Initialization(void);

void PWM2_SetScale(uint16_t scale);


#endif


