#include "main.h"

extern RC_Ctl_t RC_Ctl;

extern int32_t T_LIFT_POSITION_R;
extern int32_t T_GRAB_POSITION;
extern int32_t T_ROTATE_POSITION;

int Rc_Start=1;

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
		       Toward_Left();
		        Extension();
		           //Pop();
		           Open();
		          Trail();
		         
	  }
	  
	  if((RC_Ctl.rc.s1==UP)&&(RC_Ctl.rc.s2==DOWN))
      {
	              Loosen();
		       Toward_Right();
		        Contraction();
		          //Withdraw();
		           Close();
		            Fold();
	  }
	  
	  if((RC_Ctl.rc.s1==MID)&&(RC_Ctl.rc.s2==DOWN))
      {
	       T_LIFT_POSITION_R=Lift_R_Value2;
		     T_GRAB_POSITION=Grab_Value1;
	  }
	  
	  if((RC_Ctl.rc.s1==MID)&&(RC_Ctl.rc.s2==MID))
      {
	            T_ROTATE_POSITION=Rotate_Value1;
	  }
	  
	  if((RC_Ctl.rc.s1==MID)&&(RC_Ctl.rc.s2==UP))
      {
	            T_ROTATE_POSITION=Rotate_Value3;
	  }
	  
	  if((RC_Ctl.rc.s1==DOWN)&&(RC_Ctl.rc.s2==UP))
      {
	            T_ROTATE_POSITION=Rotate_Value5;
	  }
	  
	  if((RC_Ctl.rc.s1==DOWN)&&(RC_Ctl.rc.s2==MID))
      {
	       T_LIFT_POSITION_R=Lift_R_Value3 ;
		     T_GRAB_POSITION=Grab_Value3;
	  }
	  
  }
		
}
