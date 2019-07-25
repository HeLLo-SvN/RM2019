#include "main.h"

int touch_switch;

int Keyence;

int main(void)
{
delay_init(168);
Remote_Init();
Chassispid_Init();
Gyropid_Init();
Led_Configuration();
Air_Cylinder1_Configuration();
Air_Cylinder2_Configuration();
Air_Cylinder3_Configuration();
Air_Cylinder4_Configuration();
//Vehicle_Backup_Camera_Configuration();�ܾ���ȡ������Ӱ��	
Keyence_Configuration();
USART6_Configuration();
RC_Init();
USART2_Configuration();
Touch_Switch_Configuration();
Grabpid_Init();
Liftpid_Init();
//Rotatepid_Init();�ܾ���ȡ��
	
TIM7_Configuration();
TIM6_Configuration();

CAN1_Configuration();
CAN2_Configuration();
	
TIM7_Start();
TIM6_Start();

while(1)
{   
//         delay_ms(300);//��ӡʱ����ϵͳ��ʱ
	        delay_ms(45);
/******************�����ʼ��******************/				
		 Send_Servo_Position();	
	
          LED_BLUE_TOGGLE();
	
//	       Rc_Checking();//����������׼���Լ�

//	       Servo_Reset();//����ָ���������ʱʹ��
	
//           Testing();//�ֶ�����

/***********************����ֵ����***********************/
//	touch_switch=Pop_Touch();//Claw_Touch()//Lift_Touch()
//	Keyence=Right_Limit();//Left_Limit()
 
//           Print_Test();//��ӡ����
	
 }

}
