#include "main.h"

/*----CAN2_TX-----PB6----*/
/*----CAN2_RX-----PB5----*/

int16_t B_P_LIFT_L=0;
int16_t B_P_LIFT_R=0;
int32_t LAST_VALUE_L;
int32_t LAST_VALUE_R;
int LiftRound_L = 0;
int LiftRound_R = 0;
int32_t LIFT_POSITION_L;
int32_t LIFT_POSITION_R;
int16_t B_V_LIFT_L=0;
int16_t B_V_LIFT_R=0;

int16_t B_P_GRAB=0;
int32_t LAST_VALUE_G;
int GrabRound = 0;
int32_t GRAB_POSITION;
int16_t B_V_GRAB=0;

int16_t B_P_ROTATE=0;
int32_t LAST_VALUE_RO;
int RotateRound = 0;
int32_t ROTATE_POSITION;
int16_t B_V_ROTATE=0;

void CAN2_Configuration(void)
{
    CAN_InitTypeDef        can;
    CAN_FilterInitTypeDef  can_filter;
    GPIO_InitTypeDef       gpio;
    NVIC_InitTypeDef       nvic;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN2, ENABLE);

    GPIO_PinAFConfig(GPIOB, GPIO_PinSource6, GPIO_AF_CAN2);
    GPIO_PinAFConfig(GPIOB, GPIO_PinSource5, GPIO_AF_CAN2); 

    gpio.GPIO_Pin = GPIO_Pin_6 | GPIO_Pin_5 ;
    gpio.GPIO_Mode = GPIO_Mode_AF;
    GPIO_Init(GPIOB, &gpio);

    nvic.NVIC_IRQChannel = CAN2_RX1_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 1;
    nvic.NVIC_IRQChannelSubPriority = 1;
    nvic.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic);

    nvic.NVIC_IRQChannel = CAN2_TX_IRQn;
    nvic.NVIC_IRQChannelPreemptionPriority = 0;
    nvic.NVIC_IRQChannelSubPriority = 1;
    nvic.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvic); 
		
    CAN_DeInit(CAN2);
    CAN_StructInit(&can);

    can.CAN_TTCM = DISABLE;
    can.CAN_ABOM = ENABLE;    
    can.CAN_AWUM = DISABLE;    
    can.CAN_NART = DISABLE;    
    can.CAN_RFLM = DISABLE;    
    can.CAN_TXFP = ENABLE;     
    can.CAN_Mode = CAN_Mode_Normal; 
    can.CAN_SJW  = CAN_SJW_1tq;
    can.CAN_BS1 = CAN_BS1_9tq;
    can.CAN_BS2 = CAN_BS2_4tq;
    can.CAN_Prescaler = 3;   //CAN BaudRate 42/(1+9+4)/3=1Mbps
    CAN_Init(CAN2, &can);
    
    can_filter.CAN_FilterNumber=14;//14
    can_filter.CAN_FilterMode=CAN_FilterMode_IdMask;
    can_filter.CAN_FilterScale=CAN_FilterScale_32bit;
    can_filter.CAN_FilterIdHigh=0x0000;
    can_filter.CAN_FilterIdLow=0x0000;
    can_filter.CAN_FilterMaskIdHigh=0x0000;
    can_filter.CAN_FilterMaskIdLow=0x0000;
    can_filter.CAN_FilterFIFOAssignment=1;
    can_filter.CAN_FilterActivation=ENABLE;
    CAN_FilterInit(&can_filter);
    
    CAN_ITConfig(CAN2,CAN_IT_FMP1,ENABLE);
		CAN_ITConfig(CAN2,CAN_IT_TME,ENABLE);
}

void CAN2_TX_IRQHandler(void)
{
  if(CAN_GetITStatus(CAN2,CAN_IT_TME)!=RESET) 
  {
    CAN_ClearITPendingBit(CAN2,CAN_IT_TME);
  }
}
void CAN2_RX1_IRQHandler(void)
{
    CanRxMsg rx_message;
    if (CAN_GetITStatus(CAN2,CAN_IT_FMP1)!= RESET) 
    {
		CAN_ClearITPendingBit(CAN2, CAN_IT_FMP1);
        CAN_Receive(CAN2, CAN_FIFO1, &rx_message);
	
/****************升降返回值****************/	
	  if(rx_message.StdId==0x201)
	  {
			LAST_VALUE_L=B_P_LIFT_L;
 		  B_P_LIFT_L=rx_message.Data[0]<<8 | rx_message.Data[1];
			
			if(B_P_LIFT_L - LAST_VALUE_L < -5000)
                 LiftRound_L++;
			else if(B_P_LIFT_L - LAST_VALUE_L > 5000)
				 LiftRound_L--;
			
			LIFT_POSITION_L = B_P_LIFT_L + 8191*LiftRound_L;
					
			B_V_LIFT_L=rx_message.Data[2]<<8 | rx_message.Data[3];
			
    }
	  if(rx_message.StdId==0x202)
 	  {
		  	LAST_VALUE_R=B_P_LIFT_R;
 		  B_P_LIFT_R=rx_message.Data[0]<<8 | rx_message.Data[1];
			
			if(B_P_LIFT_R - LAST_VALUE_R < -5000)
                 LiftRound_R++;
			else if(B_P_LIFT_R - LAST_VALUE_R > 5000)
				 LiftRound_R--;
			
			LIFT_POSITION_R = B_P_LIFT_R + 8191*LiftRound_R;
					
			B_V_LIFT_R=rx_message.Data[2]<<8 | rx_message.Data[3];
			
    }
			
/****************抓取返回值****************/
    if(rx_message.StdId==0x203)
	  {
			LAST_VALUE_G=B_P_GRAB;
 		  B_P_GRAB=rx_message.Data[0]<<8 | rx_message.Data[1];
			
			if(B_P_GRAB - LAST_VALUE_G < -5000)
                 GrabRound++;
			else if(B_P_GRAB - LAST_VALUE_G > 5000)
				 GrabRound--;
			
			GRAB_POSITION = B_P_GRAB + 8191*GrabRound;
					
			B_V_GRAB=rx_message.Data[2]<<8 | rx_message.Data[3];
			
    }
/****总决赛将翻转部分变量归并到抓取部分****/		
/****************翻转返回值****************/
    if(rx_message.StdId==0x204)
	  {
			LAST_VALUE_RO=B_P_ROTATE;
 		  B_P_ROTATE=rx_message.Data[0]<<8 | rx_message.Data[1];
			
			if(B_P_ROTATE - LAST_VALUE_RO < -5000)
         RotateRound++;
			else if(B_P_ROTATE - LAST_VALUE_RO > 5000)
				 RotateRound--;
			
			ROTATE_POSITION = B_P_ROTATE + 8191*RotateRound;
					
			B_V_ROTATE=rx_message.Data[2]<<8 | rx_message.Data[3];
			
    }		
				
		}
}
