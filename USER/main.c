#include "stm32f4xx.h"
#include "systick.h"
#include "usart1.h"
//#include "motor.h"
#include "robotctrl.h"
//#include "robot.h"

/**********************
//调试用
int main()
{
	char sendstr[]="yes";
	
	Usart1_Initialization();
	SysTick_Initialization();
	LED_Initialization();
	
	while(1)
	{
		Delay_Ms(4000);
		
		Usart1_SendString(sendstr);
		LED_On();
		Delay_Ms(1000);
		LED_Off();
		
	}
	
}
******************************/
//调试用

//int main(void)
//{
//	SysTick_Initialization();
//	Robot_Initialization();
//	Robot_Bcatch();
//	Robot_Fcatch();
//	
//	u8 str[]="XrdJBDIXrJdJuZYHDIU";
//	
//	Robotctrl_solve(str);
//	
//	while(1);
//}



/****************************************/
//主函数完成 串口消息的接收和发送 
//解析接收到的消息  将对应的 操作命令 交给Robot

//USART1_RX_STA 接收状态字 前14为数据长度
//bit15 为接收完成标志位 
void getmsg(u16 len,char *str);

int main(void)
{
	SysTick_Initialization();  //系统定时器 初始化
 	Usart1_Initialization();   //串口1初始化
	Robotctrl_Initialization();
	 
	
	u16 msgLen=0;
	char rxbuf[50]={0};  //定义长度为50接收缓存区
	char cmd=0;
	
	while(1)
	{
		if(USART1_RX_STA & 0x8000 )  //接收到消息
		{
			msgLen= USART1_RX_STA & 0x3fff;  //取出数据长度
			cmd=USART1_RX_BUF[0];
			msgLen=msgLen-2;
			getmsg(msgLen,rxbuf);
			
			Robotctrl_cmd(cmd,rxbuf);  // 解析出的 命令 类型s
			
			USART1_RX_STA=0;
		}
	}
}

void getmsg(u16 len,char * str)
{
	int i;
	for(i=0;i<len;i++)
	{
		*str=USART1_RX_BUF[i+2];
		str++;
	}
	*str='\0';
}


