#ifndef __ADC_H__
#define __ADC_H__

#include "stm32f4xx.h"

void Adc_Init(void); 				                    //ADCͨ����ʼ��
uint16_t  Get_Adc(uint8_t channel); 				            //���ĳ��ͨ��ֵ 
uint16_t Get_Adc_Average(uint8_t channel);//�õ�ĳ��ͨ����������������ƽ��ֵ  

#endif
