#include "main.h"

extern int Z_trail_flag;

void Task_Rescue(void){

     if(Z_trail_flag==0){
		 
	        Trail();
		 Z_trail_flag=1;
	 }

}
