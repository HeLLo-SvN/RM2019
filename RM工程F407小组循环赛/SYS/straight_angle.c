#include "main.h"

extern int interrupt;//�жϱ�־λ

extern int Q_straight_angle_flag;

void Auto_Rotate180(void)
{
	if(Q_straight_angle_flag==0){
	interrupt=0;//�ж�Ŀ��ֵͬ��
/**********�����ǳ�ʼ��**********/
	Gyropid_Configuration();
		
	}
	
}
