#include "main.h"

void Touch_Switch_Configuration(void)
{
	GPIO_InitTypeDef gpio;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);
	gpio.GPIO_Pin = GPIO_Pin_12|GPIO_Pin_14|GPIO_Pin_10;
	gpio.GPIO_Mode = GPIO_Mode_IN;
	gpio.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOB,&gpio);
}
