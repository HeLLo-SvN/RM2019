#ifndef __CHASSISPID_H__
#define __CHASSISPID_H__

#include "stm32f4xx.h"

#define   Adjust       0

#define   ChassisP     6
#define   ChassisI     0.3
#define   ChassisD     0
/***总决赛取弹模式PID数值***/
#define   ChassisP_N   10
#define   ChassisI_N   3
#define   ChassisD_N   0

void Chassispid_Init(void);
void Chassispid_Configuration(void);

#endif
