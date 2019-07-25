#include "main.h"

extern int32_t T_LIFT_POSITION_R;
extern int32_t LIFT_POSITION_R;

int lift_baseline =0;
int check_lock1=1;//升降自检锁定标志位

void Lift_Self_Checking(void){

   if(check_lock1==1){
	int lift_check=Lift_Touch();//动态监测触碰开关状态
	
	if(lift_check==1){
		if(T_LIFT_POSITION_R>LIFT_POSITION_R){
		T_LIFT_POSITION_R=LIFT_POSITION_R;//判断是否超出调节范围
		}
		lift_baseline=T_LIFT_POSITION_R;//升降基准位置
		check_lock1=0;
   	}
	
	if(lift_check==0){	
	    T_LIFT_POSITION_R+=100;
	}
		
	
  }	
	
}
