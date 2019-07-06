#ifndef __TOUCH_SWITCH_H__
#define __TOUCH_SWITCH_H__

#include "stm32f4xx.h"

void Touch_Switch_Configuration(void);

#define Claw_Touch() GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12)
#define Lift_Touch() GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14)
#define Rotate_Touch() GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_10)

#endif
