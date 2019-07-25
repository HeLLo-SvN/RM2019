#ifndef __AIR_CYLINDER_H__
#define __AIR_CYLINDER_H__

#include "stm32f4xx.h"

void Air_Cylinder1_Configuration(void);
void Air_Cylinder2_Configuration(void);
void Air_Cylinder3_Configuration(void);
void Air_Cylinder4_Configuration(void);

#define Clamp() GPIO_SetBits(GPIOE, GPIO_Pin_8)
#define Loosen() GPIO_ResetBits(GPIOE, GPIO_Pin_8)
#define Extension() GPIO_SetBits(GPIOA, GPIO_Pin_6)
#define Contraction() GPIO_ResetBits(GPIOA, GPIO_Pin_6)
#define Pop() GPIO_SetBits(GPIOC, GPIO_Pin_14)
#define Withdraw() GPIO_ResetBits(GPIOC, GPIO_Pin_14)
#define Open() GPIO_SetBits(GPIOA, GPIO_Pin_1)
#define Close() GPIO_ResetBits(GPIOA, GPIO_Pin_1)
#define Trail() GPIO_SetBits(GPIOB, GPIO_Pin_0)
#define Fold()  GPIO_ResetBits(GPIOB, GPIO_Pin_0)
/*****总决赛结构取消左右横移功能*****/
//#define Toward_Left() GPIO_SetBits(GPIOE, GPIO_Pin_4)
//#define Toward_Right() GPIO_ResetBits(GPIOE, GPIO_Pin_4)

#endif
