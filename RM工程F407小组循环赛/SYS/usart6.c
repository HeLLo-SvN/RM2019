#include "main.h"

/*-----USART6_TX-----PC6-----*/
/*-----USART6_RX-----PC7-----*/

void USART6_Configuration(void)
{
  USART_InitTypeDef usart6;
  GPIO_InitTypeDef  gpio;
	NVIC_InitTypeDef  nvic;
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART6,ENABLE);
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource6,GPIO_AF_USART6);
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource7,GPIO_AF_USART6); 
	
	gpio.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_7;
	gpio.GPIO_Mode = GPIO_Mode_AF;
  gpio.GPIO_OType = GPIO_OType_PP;
  gpio.GPIO_Speed = GPIO_Speed_100MHz;
  gpio.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC,&gpio);

	usart6.USART_BaudRate = 115200;
	usart6.USART_WordLength = USART_WordLength_8b;
	usart6.USART_StopBits = USART_StopBits_1;
	usart6.USART_Parity = USART_Parity_No;
	usart6.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;
  usart6.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART6,&usart6);

  USART_ITConfig(USART6,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART6,ENABLE);
    
  nvic.NVIC_IRQChannel = USART6_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 3;
  nvic.NVIC_IRQChannelSubPriority = 2;
  nvic.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&nvic);
}

void USART6_SendChar(unsigned char b)
{
  while (USART_GetFlagStatus(USART6,USART_FLAG_TC) == RESET);
	USART_SendData(USART6,b);
}

int fputc(int ch, FILE *f)
{
  while (USART_GetFlagStatus(USART6,USART_FLAG_TC) == RESET);
  USART_SendData(USART6, (uint8_t)ch);
  return ch;
}

char Rx_data = 0;

void USART6_IRQHandler(void)
{
	if(USART_GetITStatus(USART6, USART_IT_RXNE) != RESET)
  {
    USART_ClearITPendingBit(USART6,USART_IT_RXNE);
    Rx_data  = USART6->DR;
		Dealdata(Rx_data);
  }
}



