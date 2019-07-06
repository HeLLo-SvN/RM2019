#include "main.h"

extern int32_t T_GRAB_POSITION;
extern int32_t GRAB_POSITION;

int grab_baseline =0;
//int claw_check;//触碰开关出发识别
int check_lock=1;//自检锁定标志位

void Grab_Self_Checking(void){
   if(check_lock==1){
	int claw_check=Claw_Touch();
	
	if(claw_check==1){
		if(T_GRAB_POSITION<GRAB_POSITION){
		T_GRAB_POSITION=GRAB_POSITION;//判断是否超出调节范围
		}
		grab_baseline=T_GRAB_POSITION;
		check_lock=0;
   	}
	
	if(claw_check==0){	
	    T_GRAB_POSITION-=100;
	}
		
	
  }
	
}
