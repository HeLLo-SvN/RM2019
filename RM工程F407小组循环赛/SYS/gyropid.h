#ifndef __GYROPID_H__
#define __GYROPID_H__

#include "stm32f4xx.h"

typedef union
{
    uint8_t angle_data[4];
	float angle;
	
}Gyro_Angle;

typedef union
{
    uint8_t angle_data_pitch[4];
	float angle_pitch;
	
}Gyro_Angle_Pitch;

#define   GYROP     10
#define   GYROI     0.2
#define   GYROD     0

void Gyropid_Init(void);
void Gyropid_Configuration(void);

#endif
