#ifndef _MOTOR_H
#define _MOTOR_H

#include "stm32f4xx.h"
#include "pwm1.h"
#include "pwm2.h"
#include "pwm3.h"
#include "pwm4.h"
#include "pwm5.h"
#include "pwm6.h"
#include "pwm7.h"
#include "pwm8.h"


#define F1_JD_0 		460			  //0¶È
#define F1_JD_90 	1110        //90¶È
#define F1_JD_180  1793 				//180¶È

#define R1_JD_0    	500	  
#define R1_JD_90    1166
#define R1_JD_180   1866

#define B1_JD_0    500
#define B1_JD_90   1120
#define B1_JD_180  1810

#define L1_JD_0			500
#define L1_JD_90		1110
#define L1_JD_180		1788




#define F2_JD_0     500
#define F2_JD_90 		1166
#define F2_JD_180 	1833

#define R2_JD_0    	500		  
#define R2_JD_90   1166
#define R2_JD_180  1833

#define B2_JD_0    500
#define B2_JD_90   1430
#define B2_JD_180  2400

#define L2_JD_0			500
#define L2_JD_90		1166
#define L2_JD_180		1833



void Motor_Init(void);

void Motor_ctrl(u8 flag);

void Motor_Initialization(void);

void Motor_L1_Turn(u16 angle);
void Motor_L2_Turn(u16 angle);

void Motor_R1_Turn(u16 angle);
void Motor_R2_Turn(u16 angle);

void Motor_B1_Turn(u16 angle);
void Motor_B2_Turn(u16 angle);

void Motor_F1_Turn(u16 angle);
void Motor_F2_Turn(u16 angle);

#endif
