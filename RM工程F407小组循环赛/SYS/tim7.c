#include "main.h"

int Parameter=8;

extern int SHIFT_speed_switch_flag;


void TIM7_Configuration(void)
{
  TIM_TimeBaseInitTypeDef  tim;
  NVIC_InitTypeDef         nvic;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM7,ENABLE);
    
  nvic.NVIC_IRQChannel = TIM7_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 2;
  nvic.NVIC_IRQChannelSubPriority = 1;
  nvic.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&nvic);

  tim.TIM_Prescaler = 42-1;
  tim.TIM_CounterMode = TIM_CounterMode_Up;
  tim.TIM_ClockDivision = TIM_CKD_DIV1;
  tim.TIM_Period = 20000;
  TIM_TimeBaseInit(TIM7,&tim);
}

void TIM7_Start(void)
{
  TIM_Cmd(TIM7, ENABLE);	 
  TIM_ITConfig(TIM7, TIM_IT_Update,ENABLE);
  TIM_ClearFlag(TIM7, TIM_FLAG_Update);	
}

void TIM7_Close(void)
{
	TIM_ITConfig(TIM7, TIM_IT_Update,DISABLE);
  TIM_Cmd(TIM7, DISABLE);	 
}

void TIM7_IRQHandler(void)
{
 if(TIM_GetITStatus(TIM7,TIM_IT_Update)!= RESET) 
  {
    TIM_ClearITPendingBit(TIM7,TIM_IT_Update);
    TIM_ClearFlag(TIM7, TIM_FLAG_Update);

/******************系数初始化******************/
		   
	    if(SHIFT_speed_switch_flag==0){
		      Parameter=17;
		}
		else{
		      Parameter=8;
		}
			
			
/******************PID初始化******************/	
        			
		Wheel_Direction();

		Chassispid_Configuration();

		Actionpid_Configuration();

	}
}

