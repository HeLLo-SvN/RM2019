#include "main.h"

extern int32_t T_LIFT_POSITION_R;

int interface_time_count;

int Lift_flag=1;
int pop_flag=1;

extern int X_supply_flag;
extern int C_open_permission;//开舱门权限
extern int C_open_flag;

void Task_HeroInterface(void){
   if(X_supply_flag==0){ 
	   
	interface_time_count++;
	
	   if(Lift_flag==1){
	T_LIFT_POSITION_R=Lift_R_Value2;
		   Lift_flag=0;
	   }
	   if(pop_flag==1){
	if(interface_time_count>100){
	         Pop();
		   pop_flag=0;
	  interface_time_count=0;
		  X_supply_flag=1;
		    Lift_flag=1;
	   }
      }
     }
  if(C_open_permission==0){   
   if(C_open_flag==0){
            Open();
	     C_open_flag=1;
	   C_open_permission=1;
   }
  }
		
}
