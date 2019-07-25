#include "main.h"

extern RC_Ctl_t RC_Ctl;
extern int PRESS_R_lockplatform;
extern int PRESS_L_lockplatform;

/**********舵机测试变量**********/
//uint16_t x_servo_Test;
//uint16_t y_servo_Test;

//extern uint16_t x_servo_Position;
//extern uint16_t y_servo_Position;
/************舵机变量************/
uint16_t x_servo_Init=36;
uint16_t y_servo_Init=30;

void Send_Servo_Position(void){
/**********舵机角度速度测试**********/
//	x_servo_Test=x_servo_Position;
//	y_servo_Test=y_servo_Position;
//	
//	X_Servo_Configuration(x_servo_Test);
//	Y_Servo_Configuration(y_servo_Test);
/************舵机&遥控器************/	
		X_Servo_Configuration(x_servo_Init);
	    Y_Servo_Configuration(y_servo_Init);
/***************YAW轴***************/	
 if(PRESS_R_lockplatform==0){	
//	if(RC_Ctl.mouse.x>0){       //总决赛舵机右侧限位
//		if(x_servo_Init==0){
//	        x_servo_Init=0;
//		}
//		else{
//		    x_servo_Init-=2;
//		}
//	}
	
	if(RC_Ctl.mouse.x<0){
		if(x_servo_Init==92){
	        x_servo_Init=92;
		}
		else{
		    x_servo_Init+=2;
		}
	}
	
 }
 else{
	 if(PRESS_L_lockplatform==1){
      x_servo_Init=36;
	  
	 }	
     if(PRESS_L_lockplatform==0){
	  x_servo_Init=250;
	  y_servo_Init=34;
	 }	 
 }

/**************PITCH轴**************/	
   if(PRESS_L_lockplatform==1){			
	if(RC_Ctl.mouse.y<0){
	    if(y_servo_Init==0){
		    y_servo_Init=0;
		}
		else{
		    y_servo_Init-=1;
		}
	}
	
    if(RC_Ctl.mouse.y>0){
	    if(y_servo_Init==80){
		    y_servo_Init=80;
		}
		else{
		    y_servo_Init+=1;
		}
	}
  }
 
}

void X_Servo_Configuration(uint16_t x_Position){

      int x=0;
	  uint8_t x_sum = 0x00; 
	  uint8_t x_data[] = {0xFF,0xFF,0x07,0x07,0x03,0x1E,0,0,0,0,0xFF};
	  x_data[6]=(0x3FF/300*x_Position)&0xFF;
	  x_data[7]=(0x3FF/300*x_Position)>>8;
	  x_data[8]=1022&0xFF;
	  x_data[9]=1022>>8;
	  
	  for(x=2;x<10;x++)
     {
       x_sum+=x_data[x];                   
     } 
      x_data[10] = ~x_sum; 
	 
      for(x=0;x<11;x++)
     {
   	  USART2_SendChar(x_data[x]);
     }
}

void Y_Servo_Configuration(uint16_t y_Position){

      int y=0;	
	  uint8_t y_sum = 0x00; 
	  uint8_t y_data[] = {0xFF,0xFF,0x01,0x07,0x03,0x1E,0,0,0,0,0xFF};
	  y_data[6]=(0x3FF/300*y_Position)&0xFF;
	  y_data[7]=(0x3FF/300*y_Position)>>8;
	  y_data[8]=1022&0xFF;
	  y_data[9]=1022>>8;
	  
	  for(y=2;y<10;y++)
     {
       y_sum+=y_data[y];                   
     } 
      y_data[10] = ~y_sum; 
	 
      for(y=0;y<11;y++)
     {
   	  USART2_SendChar(y_data[y]);
     }
	  
}

//void Servo_Reset(void){

//      int reset=0;  
//	  uint8_t reset_sum = 0x00;
//	
//	  uint8_t Reset_data[] = {0xFF,0xFF,0x02,0x02,0x06,0xFF};
//	  
//	  for(reset=2;reset<5;reset++)
//     {
//       reset_sum+=Reset_data[reset];                   
//     } 
//      Reset_data[5] = ~reset_sum; 
//	  
//      for(reset=0;reset<6;reset++)
//     {
//   	  USART2_SendChar(Reset_data[reset]);
//     }

//}

