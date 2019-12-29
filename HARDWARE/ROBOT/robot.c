#include "robot.h"

//完成从舵机转动到魔方动作的影射  
//几个基本动作：
//catch  将卡扣抓住魔方
//back   放开魔方
//turn   旋转魔方的对应面


void Robot_Init()
{
	Motor_Initialization();
	Motor_ctrl(1);
}

void Robot_Initialization()
{
	Robot_Init();
}



void Robot_Lcatch()
{
	Motor_L2_Turn(L2_JD_0);
}

void Robot_Fcatch()
{
	Motor_F2_Turn(F2_JD_0);
}

void Robot_Rcatch()
{
	Motor_R2_Turn(R2_JD_0);
}

void Robot_Bcatch()
{
	Motor_B2_Turn(B2_JD_0);
}




void Robot_Lback()
{
	Motor_L2_Turn(L2_JD_90);
}

void Robot_Fback()
{
	Motor_F2_Turn(F2_JD_90);
}

void Robot_Rback()
{
	Motor_R2_Turn(R2_JD_90);
}

void Robot_Bback()
{
	Motor_B2_Turn(B2_JD_90);
}



void Robot_Lturn(u8 turn)
{
	if(turn==T)
	{
		Delay_Ms(dlytime);
		Motor_L1_Turn(L1_JD_180);
		Delay_Ms(dlytime);
		
	}
	else if (turn==T_)
	{
		Delay_Ms(dlytime);
		Motor_L1_Turn(L1_JD_0);
		Delay_Ms(dlytime);
		
	}
	else if(turn==T2)
	{
		Delay_Ms(dlytime);
		Robot_Lback();
		Delay_Ms(dlytime);
		Motor_L1_Turn(L1_JD_0);
		Delay_Ms(dlytime);
		Robot_Lcatch();
		Delay_Ms(dlytime);
		Motor_L1_Turn(L1_JD_180);
	}	
	
	
	//完成旋转后的复位
		Delay_Ms(dlytime);
		Robot_Lback();
		Delay_Ms(dlytime);
		Motor_L1_Turn(L1_JD_90);
		Delay_Ms(dlytime);
		Robot_Lcatch();
}

void Robot_Fturn(u8 turn)
{
		if(turn==T)
	{
		Delay_Ms(dlytime);
		Motor_F1_Turn(F1_JD_180);
		Delay_Ms(dlytime);
		
	}
	else if (turn==T_)
	{
		Delay_Ms(dlytime);
		Motor_F1_Turn(F1_JD_0);
		Delay_Ms(dlytime);
	}
	else if(turn==T2)
	{
		Delay_Ms(dlytime);
		Robot_Fback();
		Delay_Ms(dlytime);
		Motor_F1_Turn(F1_JD_0);
		Delay_Ms(dlytime);
		Robot_Fcatch();
		Delay_Ms(dlytime);
		Motor_F1_Turn(F1_JD_180);
	}	
	
	//旋转后的复位
		Delay_Ms(dlytime);
		Robot_Fback();
		Delay_Ms(dlytime);
		Motor_F1_Turn(F1_JD_90);
		Delay_Ms(dlytime);
		Robot_Fcatch();
}

void Robot_Rturn(u8 turn)
{
		if(turn==T)
	{
		Delay_Ms(dlytime);
		Motor_R1_Turn(R1_JD_180);
		Delay_Ms(dlytime);
	}
	else if (turn==T_)
	{
		Delay_Ms(dlytime);
		Motor_R1_Turn(R1_JD_0);
		Delay_Ms(dlytime);
	}
	else if(turn==T2)
	{
		Delay_Ms(dlytime);
		Robot_Rback();
		Delay_Ms(dlytime);
		Motor_R1_Turn(R1_JD_0);
		Delay_Ms(dlytime);
		Robot_Rcatch();
		Delay_Ms(dlytime);
		Motor_R1_Turn(R1_JD_180);
	}	
	
	
	//旋转后的复位
		Delay_Ms(dlytime);
		Robot_Rback();
		Delay_Ms(dlytime);
		Motor_R1_Turn(R1_JD_90);
	  Delay_Ms(dlytime);
		Robot_Rcatch();
}

void Robot_Bturn(u8 turn)
{
		if(turn==T)
	{
		Delay_Ms(dlytime);
		Motor_B1_Turn(B1_JD_180);
		Delay_Ms(dlytime);
	}
	else if (turn==T_)
	{
		Delay_Ms(dlytime);
		Motor_B1_Turn(B1_JD_0);
		Delay_Ms(dlytime);
	}
	else if(turn==T2)
	{
		Delay_Ms(dlytime);
		Robot_Bback();
		Delay_Ms(dlytime);
		Motor_B1_Turn(B1_JD_0);
		Delay_Ms(dlytime);
		Robot_Bcatch();
		Delay_Ms(dlytime);
		Motor_B1_Turn(B1_JD_180);
	}		
	
	
	//旋转后的复位
  	Delay_Ms(dlytime);
		Robot_Bback();
		Delay_Ms(dlytime);
		Motor_B1_Turn(B1_JD_90);
 	  Delay_Ms(dlytime);
		Robot_Bcatch();
}

void Robot_getUDface()  //姿态调整 将U D面 换到BF 面
{
	Delay_Ms(dlytime);
	Robot_Bback();
	Robot_Fback();
	Delay_Ms(dlytime);
	Motor_L1_Turn(L1_JD_180);
	Motor_R1_Turn(R1_JD_0);
	Delay_Ms(dlytime);
	Robot_Bcatch();
	Robot_Fcatch();
	Delay_Ms(dlytime);
	Robot_Lback();
	Robot_Rback();
  Delay_Ms(dlytime);
	Motor_L1_Turn(L1_JD_90);
	Motor_R1_Turn(R1_JD_90);
	Delay_Ms(dlytime);
	Robot_Lcatch();
	Robot_Rcatch();
}

void  Robot_reUDface()  //姿态调整   还原 U D 面
{
	Delay_Ms(dlytime);
	Robot_Bback();
	Robot_Fback();
	Delay_Ms(dlytime);
	Motor_L1_Turn(L1_JD_0);
	Motor_R1_Turn(R1_JD_180);
	Delay_Ms(dlytime);
	Robot_Bcatch();
	Robot_Fcatch();
	Delay_Ms(dlytime);
	Robot_Lback();
	Robot_Rback();
  Delay_Ms(dlytime);
	Motor_L1_Turn(L1_JD_90);
	Motor_R1_Turn(R1_JD_90);
	Delay_Ms(dlytime);
	Robot_Lcatch();
	Robot_Rcatch();
	
}

void Robot_Uturn(u8 turn)
{

	Robot_getUDface();

	Robot_Fturn(turn);  //将U面转到F后  按照F面旋转U面
	
	Robot_reUDface();
	
}

void Robot_Dturn(u8 turn)  //将
{
	
	Robot_getUDface();
	
	Robot_Bturn(turn); //将D面旋转到B面后  按照B面旋转D面
	
	Robot_reUDface();
	
	
}
	








