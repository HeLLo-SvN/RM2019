#ifndef __SERVO_H__
#define __SERVO_H__

#include "stm32f4xx.h"

void Send_Servo_Position(void);
void X_Servo_Configuration(uint16_t x_Position);
void Y_Servo_Configuration(uint16_t y_Position);
//void Servo_Reset(void);

#endif
