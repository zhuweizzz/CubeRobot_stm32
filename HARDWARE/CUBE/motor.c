#include "motor.h"



void Motor_Init(void)
{
	PWM1_Initialization();
	PWM2_Initialization();
	PWM3_Initialization();
	PWM4_Initialization();
	PWM5_Initialization();
	PWM6_Initialization();
	PWM7_Initialization();
	PWM8_Initialization();  //完成基本定时器的初始化
}

void Motor_reset()
{
	PWM1_SetScale(F1_JD_90);
  PWM2_SetScale(F2_JD_90);
	PWM3_SetScale(B1_JD_90);
	PWM4_SetScale(B2_JD_90);
	PWM5_SetScale(L2_JD_0);
	PWM6_SetScale(R2_JD_0);
	PWM7_SetScale(L1_JD_90);
	PWM8_SetScale(R1_JD_90);
}


void Motor_ctrl(u8 flag)
{
	PWM1_Ctrl(flag);
	PWM2_Ctrl(flag);
	PWM3_Ctrl(flag);
	PWM3_Ctrl(flag);
	PWM4_Ctrl(flag);
	PWM5_Ctrl(flag);
	PWM6_Ctrl(flag);
	PWM7_Ctrl(flag);
	PWM8_Ctrl(flag);
}

void Motor_Initialization(void)
{
	Motor_Init();
	Motor_reset();
}

void Motor_L2_Turn(u16 angle)
{
	PWM5_SetScale(angle);
}


void Motor_R2_Turn(u16 angle)
{
	PWM6_SetScale(angle);
}


void Motor_B1_Turn(u16 angle)
{
	PWM3_SetScale(angle);
}


void Motor_B2_Turn(u16 angle)
{
	PWM4_SetScale(angle);
}


void Motor_F1_Turn(u16 angle)
{
	PWM1_SetScale(angle);
}

void Motor_F2_Turn(u16 angle)
{
	PWM2_SetScale(angle);
}


void Motor_L1_Turn(u16 angle)
{
	PWM7_SetScale(angle);
}

void Motor_R1_Turn(u16 angle)
{
	PWM8_SetScale(angle);
}
