#include "main.h"

extern int32_t T_LIFT_POSITION_R;
extern int32_t LIFT_POSITION_R;

int lift_baseline =0;
int check_lock1=1;//�����Լ�������־λ

void Lift_Self_Checking(void){

   if(check_lock1==1){
	int lift_check=Lift_Touch();//��̬��ⴥ������״̬
	
	if(lift_check==1){
		if(T_LIFT_POSITION_R>LIFT_POSITION_R){
		T_LIFT_POSITION_R=LIFT_POSITION_R;//�ж��Ƿ񳬳����ڷ�Χ
		}
		lift_baseline=T_LIFT_POSITION_R;//������׼λ��
		check_lock1=0;
   	}
	
	if(lift_check==0){	
	    T_LIFT_POSITION_R+=100;
	}
		
	
  }	
	
}
