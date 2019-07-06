#ifndef __ROTATEPID_H__
#define __ROTATEPID_H__

#include "stm32f4xx.h"

//#define   D_ExRotateP     0.1
//#define   D_ExRotateI     0
//#define   D_ExRotateD     0
//#define   D_InRotateP     5
//#define   D_InRotateI     0.1
//#define   D_InRotateD     0

#define   U_ExRotateP     0.45
#define   U_ExRotateI     0
#define   U_ExRotateD     0
#define   U_InRotateP     10
#define   U_InRotateI     0.4
#define   U_InRotateD     0

void Rotatepid_Init(void);
void Rotatepid_Configuration(void);

#endif
