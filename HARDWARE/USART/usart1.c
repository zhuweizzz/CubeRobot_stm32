#include "usart1.h"
#include "systick.h"
#include "led.h"



void Usart1_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	USART1_GPIO_CLK_Cmd(USART1_GPIO_CLK, ENABLE);
	
	GPIO_PinAFConfig(USART1_GPIO, USART1_TX_GPIO_PinSource, USART1_GPIO_AF);
	GPIO_PinAFConfig(USART1_GPIO, USART1_RX_GPIO_PinSource, USART1_GPIO_AF);
	
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	
	GPIO_InitStructure.GPIO_Pin = USART1_TX_GPIO_Pin | USART1_RX_GPIO_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	
	GPIO_Init(USART1_GPIO, &GPIO_InitStructure);	
	
}

void Usart1_Config(void)
{
	USART_InitTypeDef USART_InitStructure;
	
	USART1_CLK_Cmd(USART1_CLK, ENABLE);
	
	USART_InitStructure.USART_BaudRate = 115200;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	
	USART_Init(USART1, &USART_InitStructure);
	
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	
	USART_Cmd(USART1, ENABLE);
}


void Usart1_NVIC_Config(void)
{
	NVIC_InitTypeDef NVIC_InitStructure;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
	
	NVIC_Init(&NVIC_InitStructure);
}

void Usart1_Initialization(void)
{
	Usart1_GPIO_Init();
	
	Usart1_Config();
	
	Usart1_NVIC_Config();
}



void Usart1_SendByte(uint8_t ch)
{
	USART_SendData(USART1, ch);
	while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
}

void Usart1_SendString(char *str)
{
	uint16_t i;
	for (i = 0; *(str + i) != '\0'; i++)
	{
		Usart1_SendByte(*(str + i));
	}
}

void Usart1_SendNumber(int num)
{
		if (num < 0)
		{
			Usart1_SendByte('-');
			num = -num;
		}
		else if (num > 0)
			Usart1_SendByte('+');
		Usart1_SendByte(num % 1000000 / 100000 + '0');
		Usart1_SendByte(num % 100000 / 10000 + '0');
		Usart1_SendByte(num % 10000 / 1000 + '0');
		Usart1_SendByte(num % 1000 / 100 + '0');
		Usart1_SendByte(num % 100 / 10 + '0');
		Usart1_SendByte(num % 10 + '0');
}



u8 USART1_RX_BUF[USART_REC_LEN]={0};
u16 USART1_RX_STA=0;
//bit15 接收完成标志
//bit14 接收到0x0d
//bit13~0	 接收到的有效字符



void USART1_IRQHandler(void)
{
	u8 Res;
	if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET)
	{
		Res=USART_ReceiveData(USART1);
		if((USART1_RX_STA & 0X8000)==0)  //接收数据未完成
		{
			if(USART1_RX_STA & 0X4000 ) //接收到了 0x0a
			{
				if( Res != 0x0a) USART1_RX_STA =0 ;
				else USART1_RX_STA|=0X8000; //接收完成
			}
			else
			{
				if( Res == 0x0d)
					USART1_RX_STA|=0X4000; //接收到了0x0d
				else
				{
					USART1_RX_BUF[USART1_RX_STA&0x3FFF]=Res;
					USART1_RX_STA++;
					if(USART1_RX_STA>(USART_REC_LEN-1))
						USART1_RX_STA=0;
				}
			}
		}
		USART_ClearITPendingBit(USART1, USART_IT_RXNE);
	}
}
