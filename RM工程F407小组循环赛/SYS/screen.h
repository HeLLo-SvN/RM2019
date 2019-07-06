#ifndef __SCREEN_H__
#define __SCREEN_H__

#include "stm32f4xx.h"

void Vehicle_Backup_Camera_Configuration(void);

#define Switch_Camera1() GPIO_SetBits(GPIOD, GPIO_Pin_14)
#define Switch_Camera2() GPIO_ResetBits(GPIOD, GPIO_Pin_14)

#endif
