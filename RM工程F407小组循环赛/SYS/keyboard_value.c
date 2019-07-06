#include "main.h"

extern RC_Ctl_t RC_Ctl;

int keyboard_time_count;

int R_quit_flag=1;//退出取弹环节标志位
int E_under_isle_flag=1;//岛下取后排弹药标志位
int E_lockchassis_flag=1;//取弹时底盘锁定标志位
int F_under_isle_flag=1;//岛下取前排弹药标志位
int V_on_isle_flag=1;//岛上取弹药标志位
int Z_trail_flag=1;//拖车标志位
int X_supply_flag=1;//补弹标志位
int C_open_permission=1;//开舱门权限
int C_open_flag=1;//开舱门标志位
int PRESS_R_lockplatform=1;//云台锁定标志位
int PRESS_L_lockplatform=1;//倒车云台锁定标志位
int SHIFT_speed_switch_flag=1;//速度切换标志位
int SHIFT_command_flag=1;//Shift组合键标志位
int Q_straight_angle_flag=1;//自动旋转180度标志位
int CTRL_rotate_check_flag=1;//弹出弹药箱自检标志位

extern int interrupt;//中断标志位
extern float F_GYRO_ANGLE;
extern PID_AbsoluteType  gyro_Angle;

void Value_Change(void){
    
	if(RC_Ctl.key.v&KEY_R){
		R_quit_flag=0;
		
		E_lockchassis_flag=1;//退出取弹底盘限制
	}
	
	if(RC_Ctl.key.v&KEY_E){
		
	  if(F_under_isle_flag==1){	
		E_under_isle_flag=0;
	  }
				
		Switch_Camera1();
		
		E_lockchassis_flag=0;//取弹时锁定左/右旋/反向
		PRESS_L_lockplatform=0;//舵机转向倒车影像
	}
	
    if(RC_Ctl.key.v&KEY_Q){
		 Q_straight_angle_flag=0;
				
	}
	else{
	     Q_straight_angle_flag=1;
		 interrupt=1;
		 F_GYRO_ANGLE=0.0f;
		gyro_Angle.errNow=0.0f;
		gyro_Angle.ctrOut=0.0f;
	}
	
	if(RC_Ctl.key.v&KEY_F){
		
	  if(E_under_isle_flag==1){
		F_under_isle_flag=0;
	  }
		
		Switch_Camera1();
		
		E_lockchassis_flag=0;//取弹时锁定左/右旋/反向
		PRESS_L_lockplatform=0;//舵机转向倒车影像
		
	}
	
	if(RC_Ctl.key.v&KEY_V){
 		V_on_isle_flag=0;//岛上取弹药标志位
		
		Switch_Camera1();
		
		E_lockchassis_flag=0;//取弹时锁定左/右旋/反向
		PRESS_L_lockplatform=0;//舵机转向倒车影像
	}
		
	if(RC_Ctl.key.v&KEY_Z){
  	    Z_trail_flag=0;
		
	}	
	
	if(RC_Ctl.key.v&KEY_X){
  	    X_supply_flag=0;
		C_open_permission=0;
	}
		 
	if(RC_Ctl.key.v&KEY_C){
  	    C_open_flag=0;
	}
	else{
	    C_open_flag=1;
	}
		
	if(RC_Ctl.mouse.press_r==1){
	    PRESS_R_lockplatform=0;
		PRESS_L_lockplatform=1;
		
		Switch_Camera2();
		
	}
	else{
	    PRESS_R_lockplatform=1;
	}
	
	if(RC_Ctl.mouse.press_l==1){
	    PRESS_L_lockplatform=0;
	}
	
	if(RC_Ctl.key.v&KEY_SHIFT){
  	    SHIFT_speed_switch_flag=0;
		
		if(E_under_isle_flag==0){
		SHIFT_command_flag=0;
		}
		
		if(F_under_isle_flag==0){
		SHIFT_command_flag=0;
		}
		
		if(V_on_isle_flag==0){
		SHIFT_command_flag=0;
		}
		
	}
	else{
	    SHIFT_speed_switch_flag=1;
				
	}
	
//	if(RC_Ctl.key.v&KEY_CTRL){
//	
//	    CTRL_rotate_check_flag=0;  
//		
//	}
     
}

