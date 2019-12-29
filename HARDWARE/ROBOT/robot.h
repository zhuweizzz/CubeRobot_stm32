#ifndef _ROBOT_H
#define _ROBOT_H

#include "stm32f4xx.h"
#include "systick.h"
#include "motor.h"

#define dlytime 800



#define T  1   //对应魔方的 U  U'  U2
#define T_ 2
#define T2 3



void Robot_Init(void);

void Robot_Initialization(void);




void Robot_Lcatch(void);

void Robot_Rcatch(void);

void Robot_Fcatch(void);

void Robot_Bcatch(void);






void Robot_Lback(void);

void Robot_Rback(void);

void Robot_Fback(void);

void Robot_Bback(void);





void Robot_Lturn(u8 turn);

void Robot_Fturn(u8 turn);

void Robot_Rturn(u8 turn);

void Robot_Bturn(u8 turn);

void Robot_Uturn(u8 turn);

void Robot_Dturn(u8 turn);


#endif


