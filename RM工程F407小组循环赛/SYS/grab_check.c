#include "main.h"

extern int32_t T_GRAB_POSITION;
extern int32_t GRAB_POSITION;

int grab_baseline =0;
int check_lock=1;//ȡ���Լ�������־λ

void Grab_Self_Checking(void){
		
   if(check_lock==1){
	int claw_check=Claw_Touch();//��̬��ⴥ������״̬
	
	if(claw_check==1){
		if(T_GRAB_POSITION<GRAB_POSITION){
		T_GRAB_POSITION=GRAB_POSITION;//�ж��Ƿ񳬳����ڷ�Χ
		}
		grab_baseline=T_GRAB_POSITION;//ץȡ��׼λ��
		check_lock=0;
   	}
	
	if(claw_check==0){	
	    T_GRAB_POSITION-=300;
	}
		
	
  }
	
}
