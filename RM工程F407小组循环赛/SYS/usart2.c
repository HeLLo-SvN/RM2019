#include "main.h"

/*-----USART2_TX-----PA2-----*/

void USART2_Configuration(void){

  USART_InitTypeDef usart2;
  GPIO_InitTypeDef  gpio;
	NVIC_InitTypeDef  nvic;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART2);
		
	gpio.GPIO_Pin = GPIO_Pin_2;
	gpio.GPIO_Mode = GPIO_Mode_AF;
  gpio.GPIO_OType = GPIO_OType_PP;
  gpio.GPIO_Speed = GPIO_Speed_100MHz;
  gpio.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOA,&gpio);

	USART_DeInit(USART2);
	usart2.USART_BaudRate = 1000000;
	usart2.USART_WordLength = USART_WordLength_8b;
	usart2.USART_StopBits = USART_StopBits_1;
	usart2.USART_Parity = USART_Parity_No;
	usart2.USART_Mode = USART_Mode_Tx;
  usart2.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART2,&usart2);

  USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART2,ENABLE);
    
  nvic.NVIC_IRQChannel = USART2_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 3;
  nvic.NVIC_IRQChannelSubPriority = 3;
  nvic.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&nvic);
	
}

void USART2_SendChar(unsigned char b)
{
  while (USART_GetFlagStatus(USART2,USART_FLAG_TC) == RESET);
	USART_SendData(USART2,b);
}

