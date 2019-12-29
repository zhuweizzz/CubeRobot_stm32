#ifndef _ROBOTCTRL_H
#define _ROBOTCTRL_H

#include "stm32f4xx.h"
#include "robot.h"
#include "motor.h"
#include "systick.h"
#include "usart1.h"


void Robotctrl_Init(void);

void Robotctrl_Initialization(void);

void Robotctrl_solve(char* str); //按照解法 解魔方

void Robotctrl_Turnface(void);  //将对应面朝上 以截图 每次转换完成后需要

void rcvturn(void);

void Robotctrl_cmd(char cmd, char* str);


#endif

