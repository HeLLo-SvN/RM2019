#include "main.h"
#include "stm32f4xx_adc.h"

int sick_time_count=0;//ADCÿ5ms������������������20�Σ�

int Superposition_Sampling;
int Sampling;

int B_Sick_Distance;
int Sick_Distance;

int Sick_lock=1;
int Sample_lock=1;
int Zero_Clearing=1;

void Get_Sick_Distance(void){
	
     int Sampling_Container=0;
	
	 if(Sick_lock==1){
		 if(Sample_lock==1){
	 sick_time_count++;
		 }
	 }
	
	 if(sick_time_count<=20){  //��ȡͨ��11��ת��ֵ��20��ȡƽ��
		 if(Sample_lock==1){
	 Sampling_Container = Get_Adc_Average(ADC_Channel_11);
	 Superposition_Sampling += Sampling_Container;
		 }
	 }
	 else{
	   Sick_lock=0;
	 }
	 
	 if(Sick_lock==0){
	  Sampling = Superposition_Sampling/20;
	  B_Sick_Distance = (float)Sampling*(3.3/4096); //��ȡ�����Ĵ�С����ʵ�ʵ�ѹֵ
	  Sick_Distance = B_Sick_Distance;
		 
	  Sample_lock=0;
	  Sick_lock=1;
	  Zero_Clearing=0;
	 }		 
   
	 if(Sick_lock==1){
	   if(Zero_Clearing==0){
		 sick_time_count=0;   
	     Superposition_Sampling=0;
		 Zero_Clearing=1;
		 Sample_lock=1;
	   }
	 }
	
}
