#ifndef __CHASSISPID_H__
#define __CHASSISPID_H__

#include "stm32f4xx.h"

#define   Adjust       0

#define   ChassisP     6
#define   ChassisI     0.3
#define   ChassisD     0

void Chassispid_Init(void);
void Chassispid_Configuration(void);

#endif
