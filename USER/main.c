#include "stm32f4xx.h"
#include "systick.h"
#include "usart1.h"
//#include "motor.h"
#include "pwm1.h"
#include "robot.h"

#define a 40

//主函数完成 串口消息的接收和发送 
//解析接收到的消息  将对应的 操作命令 交给Robot

int main(void)
{
	SysTick_Initialization();  //系统定时器 初始化
 	Usart1_Initialization();   //串口1初始化
	
	
	while(1)
	{
		
		
	}
}
