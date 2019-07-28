#ifndef __ADC_H__
#define __ADC_H__

#include "stm32f4xx.h"

void Adc_Init(void); 				                    //ADC通道初始化
uint16_t  Get_Adc(uint8_t channel); 				            //获得某个通道值 
uint16_t Get_Adc_Average(uint8_t channel);//得到某个通道给定次数采样的平均值  

#endif
