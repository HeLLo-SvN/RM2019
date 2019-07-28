#include "main.h"

extern RC_Ctl_t RC_Ctl;

extern int32_t T_LIFT_POSITION_R;
extern int32_t T_GRAB_POSITION;
extern int32_t T_ROTATE_POSITION;

int Rc_Start=1;

extern int grab_baseline;//建立抓取机构的基准位置

void Rc_Checking(void)
{
  if((RC_Ctl.rc.s1==DOWN)&&(RC_Ctl.rc.s2==DOWN))
  {
  Rc_Start=0;
  }
	
  if(Rc_Start==1)
  {
  
	  if((RC_Ctl.rc.s1==UP)&&(RC_Ctl.rc.s2==MID))
      {
	              Clamp();
		        Extension();
		            
		           Open();
		          Trail();
		         
	  }
	  
	  if((RC_Ctl.rc.s1==UP)&&(RC_Ctl.rc.s2==DOWN))
      {
	              Loosen();
		        Contraction();
		          
		           Close();
		            Fold();
	  }
	  
	  if((RC_Ctl.rc.s1==MID)&&(RC_Ctl.rc.s2==DOWN))
      {
	       
		  T_GRAB_POSITION=Grab_Value1+grab_baseline;
	  }
	  
	  if((RC_Ctl.rc.s1==MID)&&(RC_Ctl.rc.s2==MID))
      {
		  
            T_LIFT_POSITION_R=Lift_R_Value1;
		                 Pop();
	  }
	  
	  if((RC_Ctl.rc.s1==MID)&&(RC_Ctl.rc.s2==UP))
      {
           
		               Withdraw();
	  }
	  
	  if((RC_Ctl.rc.s1==DOWN)&&(RC_Ctl.rc.s2==UP))
      {
           T_GRAB_POSITION=Grab_Value3+grab_baseline;
	  }
	  
	  if((RC_Ctl.rc.s1==DOWN)&&(RC_Ctl.rc.s2==MID))
      {
           T_LIFT_POSITION_R=Lift_R_Value2;
	  }
	  
  }
		
}
