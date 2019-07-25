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
//Vehicle_Backup_Camera_Configuration();总决赛取消倒车影像	
Keyence_Configuration();
USART6_Configuration();
RC_Init();
USART2_Configuration();
Touch_Switch_Configuration();
Grabpid_Init();
Liftpid_Init();
//Rotatepid_Init();总决赛取消
	
TIM7_Configuration();
TIM6_Configuration();

CAN1_Configuration();
CAN2_Configuration();
	
TIM7_Start();
TIM6_Start();

while(1)
{   
//         delay_ms(300);//打印时所需系统延时
	        delay_ms(45);
/******************舵机初始化******************/				
		 Send_Servo_Position();	
	
          LED_BLUE_TOGGLE();
	
//	       Rc_Checking();//开场三分钟准备自检

//	       Servo_Reset();//舵机恢复出厂设置时使用
	
//           Testing();//手动测试

/***********************布尔值测试***********************/
//	touch_switch=Pop_Touch();//Claw_Touch()//Lift_Touch()
//	Keyence=Right_Limit();//Left_Limit()
 
//           Print_Test();//打印数据
	
 }

}
