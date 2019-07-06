#include "main.h"

extern int32_t T_GRAB_POSITION;
extern int32_t T_ROTATE_POSITION;

int check_time_count;

int check_deadlock=1;

int check_lock1=1;
int check_lock2=1;

int check_token=0;

void Rotate_Self_Checking(void)
{ 
  if(check_deadlock==1){
   check_time_count++;
	
   if(check_lock1==1)
   {
    if(check_time_count>5)
    {
	   T_GRAB_POSITION = Grab_Value1;
		
		    check_lock1=0;
		 check_time_count=0;
		
		    check_token=1;
	}
   }
   
   if(check_token==1)
   {
    if(check_lock2==1)
    {
	 if(check_time_count>30)
     {
	     T_ROTATE_POSITION=Rotate_Value1;
		 
		       check_lock2=0;
		    check_time_count=0;
		 
		       check_token=0;
		      check_deadlock=0;
		 
	 }
	}
   }
  }	
}
