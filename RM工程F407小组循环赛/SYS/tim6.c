#include "main.h"

extern int F_under_isle_flag;
extern int E_under_isle_flag;
extern int V_on_isle_flag;
extern int SHIFT_command_flag;

void TIM6_Configuration(void)
{
  TIM_TimeBaseInitTypeDef  tim;
  NVIC_InitTypeDef         nvic;

  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);
    
  nvic.NVIC_IRQChannel                   = TIM6_DAC_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 2;
  nvic.NVIC_IRQChannelSubPriority        = 2;
  nvic.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&nvic);

  tim.TIM_Prescaler     = 42-1;//4MHz
  tim.TIM_CounterMode   = TIM_CounterMode_Up;
  tim.TIM_ClockDivision = TIM_CKD_DIV1;
  tim.TIM_Period        = 20000;//5ms
  TIM_TimeBaseInit(TIM6,&tim);
}

void TIM6_Start(void)
{
  TIM_Cmd(TIM6, ENABLE);	 
  TIM_ITConfig(TIM6, TIM_IT_Update,ENABLE);
  TIM_ClearFlag(TIM6, TIM_FLAG_Update);	
}
void TIM6_Close(void)
{
	TIM_ITConfig(TIM6, TIM_IT_Update,DISABLE);
  TIM_Cmd(TIM6, DISABLE);	 
}

void TIM6_DAC_IRQHandler(void)  
{
  if(TIM_GetITStatus(TIM6,TIM_IT_Update)!= RESET) 
  {
    TIM_ClearITPendingBit(TIM6,TIM_IT_Update);
    TIM_ClearFlag(TIM6, TIM_FLAG_Update);
	  
/********************具体任务********************/

           Value_Change();
	  
           Quit_Mode();
	   
// if(!(F_under_isle_flag||SHIFT_command_flag))
//	       {Mode_Front();}                     //分区赛岛下前排取弹按键逻辑
// if(!(E_under_isle_flag||SHIFT_command_flag)) 	   
//	       {Mode_Behind();}                    //分区赛岛下后排取弹按键逻辑
	  
         if(F_under_isle_flag==0)
	       {Mode_Front();}	                   //总决赛岛下取弹由F键位改为B
	     if(V_on_isle_flag==0)
		   {Mode_On_Isle();}                   //总决赛岛下后排及岛上取弹键位

		   
           Auto_Rotate180();		   
	   	   Task_Rescue();
		   Task_HeroInterface();
	       
		
	} 
}
