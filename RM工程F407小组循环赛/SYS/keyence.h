#ifndef __KEYENCE_H__
#define __KEYENCE_H__

#include "stm32f4xx.h"

void Keyence_Configuration(void);

#define Left_Limit() GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13)
#define Right_Limit() GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_15)

#endif
