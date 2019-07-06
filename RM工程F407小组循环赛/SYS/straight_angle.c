#include "main.h"

extern int interrupt;//中断标志位

extern int Q_straight_angle_flag;

void Auto_Rotate180(void)
{
	if(Q_straight_angle_flag==0){
	interrupt=0;//中断目标值同步
/**********陀螺仪初始化**********/
	Gyropid_Configuration();
		
	}
	
}
