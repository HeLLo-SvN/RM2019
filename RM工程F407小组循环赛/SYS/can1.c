#include "main.h"

/*----CAN1_TX-----PA12----*/
/*----CAN1_RX-----PA11----*/

int16_t B_TOP_L=0;
int16_t B_TOP_R=0;
int16_t B_DOWN_L=0;
int16_t B_DOWN_R=0;
int16_t B_MID_L=0;
int16_t B_MID_R=0;

Gyro_Angle B_ANGLE_DATA;
float B_GYRO_ANGLE=0.0f;
float LAST_GYRO_ANGLE=0.0f;
float INSTANTANEOUS;
int interrupt=1;//中断标志位

Gyro_Angle_Pitch B_ANGLE_DATA_PITCH;
float B_GYRO_ANGLE_PITCH=0.0f;
float T_GYRO_ANGLE_PITCH=0.0f;
int interrupt_P=1;//中断标志位

void CAN1_Configuration(void)
{
  CAN_InitTypeDef        can;
  CAN_FilterInitTypeDef  can_filter;
  GPIO_InitTypeDef       gpio;
  NVIC_InitTypeDef       nvic;
	
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_CAN1, ENABLE);

  GPIO_PinAFConfig(GPIOA, GPIO_PinSource12, GPIO_AF_CAN1);
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource11, GPIO_AF_CAN1);

  gpio.GPIO_Pin  = GPIO_Pin_12 | GPIO_Pin_11;
  gpio.GPIO_Mode = GPIO_Mode_AF;
  GPIO_Init(GPIOA, &gpio);
    
  nvic.NVIC_IRQChannel                   = CAN1_RX0_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 1;
  nvic.NVIC_IRQChannelSubPriority        = 0;
  nvic.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&nvic);
    
  nvic.NVIC_IRQChannel                   = CAN1_TX_IRQn;
  nvic.NVIC_IRQChannelPreemptionPriority = 0;
  nvic.NVIC_IRQChannelSubPriority        = 0;
  nvic.NVIC_IRQChannelCmd                = ENABLE;
  NVIC_Init(&nvic);    
    
  CAN_DeInit(CAN1);
  CAN_StructInit(&can);
    
  can.CAN_TTCM      = DISABLE;
  can.CAN_ABOM      = ENABLE;
  can.CAN_AWUM      = DISABLE;
  can.CAN_NART      = DISABLE;
  can.CAN_RFLM      = DISABLE;
  can.CAN_TXFP      = ENABLE;
  can.CAN_Mode      = CAN_Mode_Normal;
  can.CAN_SJW       = CAN_SJW_1tq;
  can.CAN_BS1       = CAN_BS1_9tq;
  can.CAN_BS2       = CAN_BS2_4tq;
  can.CAN_Prescaler = 3;   //CAN BaudRate 42/(1+9+4)/3=1Mbps
  CAN_Init(CAN1, &can);

	can_filter.CAN_FilterNumber        =0;
	can_filter.CAN_FilterMode          =CAN_FilterMode_IdMask;
	can_filter.CAN_FilterScale         =CAN_FilterScale_32bit;
	can_filter.CAN_FilterIdHigh        =0x0000;
	can_filter.CAN_FilterIdLow         =0x0000;
	can_filter.CAN_FilterMaskIdHigh    =0x0000;
	can_filter.CAN_FilterMaskIdLow     =0x0000;
	can_filter.CAN_FilterFIFOAssignment=0;
	can_filter.CAN_FilterActivation    =ENABLE;
	CAN_FilterInit(&can_filter);
    
  CAN_ITConfig(CAN1,CAN_IT_FMP0,ENABLE);
  CAN_ITConfig(CAN1,CAN_IT_TME,ENABLE); 
}

void CAN1_TX_IRQHandler(void)
{
  if (CAN_GetITStatus(CAN1,CAN_IT_TME)!= RESET) 
	{
    CAN_ClearITPendingBit(CAN1,CAN_IT_TME);
  }
}

void CAN1_RX0_IRQHandler(void)
{
  CanRxMsg rx_message;
  if (CAN_GetITStatus(CAN1,CAN_IT_FMP0)!= RESET)
  {
    CAN_ClearITPendingBit(CAN1, CAN_IT_FMP0);
    CAN_Receive(CAN1, CAN_FIFO0, &rx_message);
		
/****************底盘返回值****************/
	  
    if(rx_message.StdId==0x201)
	  {
 		  B_TOP_L=rx_message.Data[2]<<8 | rx_message.Data[3];
			
    }
	  if(rx_message.StdId==0x202)
 	  {
	  	B_TOP_R=rx_message.Data[2]<<8 | rx_message.Data[3];

    }
	  if(rx_message.StdId==0x203)
	  {
 	  	B_DOWN_L=rx_message.Data[2]<<8 | rx_message.Data[3];

    }
	
	  if(rx_message.StdId==0x204)
	  {
		  B_DOWN_R=rx_message.Data[2]<<8 | rx_message.Data[3];

    }
		
		if(rx_message.StdId==0x205)
	  {
 	  	B_MID_L=rx_message.Data[2]<<8 | rx_message.Data[3];

    }
	
	  if(rx_message.StdId==0x206)
	  {
		  B_MID_R=rx_message.Data[2]<<8 | rx_message.Data[3];
			
	}
/***************陀螺仪返回值***************/
	  
	  if(rx_message.StdId==0x401)         //陀螺仪YAW轴（绕Z轴旋转）
      {
		  LAST_GYRO_ANGLE=B_GYRO_ANGLE;
		  
	      B_ANGLE_DATA.angle_data[0]=rx_message.Data[4];
		  B_ANGLE_DATA.angle_data[1]=rx_message.Data[5];
		  B_ANGLE_DATA.angle_data[2]=rx_message.Data[6];
		  B_ANGLE_DATA.angle_data[3]=rx_message.Data[7];
		  
		  B_GYRO_ANGLE=B_ANGLE_DATA.angle;//顺时针为- 逆时针为+
		  
		  if(interrupt==1){
          INSTANTANEOUS=B_GYRO_ANGLE+180.0f;//瞬时逆时针旋转180度
		  }
		  		  
			  
	}
	  
	  if(rx_message.StdId==0x402)         //陀螺仪PITCH轴（绕Y轴旋转）
      {
		   
	      B_ANGLE_DATA_PITCH.angle_data_pitch[0]=rx_message.Data[0];
		  B_ANGLE_DATA_PITCH.angle_data_pitch[1]=rx_message.Data[1];
		  B_ANGLE_DATA_PITCH.angle_data_pitch[2]=rx_message.Data[2];
		  B_ANGLE_DATA_PITCH.angle_data_pitch[3]=rx_message.Data[3];
		  
		  B_GYRO_ANGLE_PITCH=B_ANGLE_DATA_PITCH.angle_pitch;
		   
          if(interrupt_P==1){
		  T_GYRO_ANGLE_PITCH=B_GYRO_ANGLE_PITCH;//动态设定基准值
		  }
         		  
	}
		
  }
}	






