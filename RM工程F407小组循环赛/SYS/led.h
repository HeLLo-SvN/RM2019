#ifndef __LED_H__
#define __LED_H__

void Led_Configuration(void);

#define  LED_BLUE_ON()      GPIO_ResetBits(GPIOB, GPIO_Pin_9)
#define  LED_BLUE_OFF()     GPIO_SetBits(GPIOB, GPIO_Pin_9)
#define  LED_BLUE_TOGGLE()  GPIO_ToggleBits(GPIOB, GPIO_Pin_9)


#endif
