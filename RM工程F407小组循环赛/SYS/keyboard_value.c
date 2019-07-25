#include "main.h"

extern RC_Ctl_t RC_Ctl;

int keyboard_time_count;

int R_quit_flag=1;//�˳�ȡ�����ڱ�־λ
int E_under_isle_flag=1;//����ȡ���ŵ�ҩ��־λ
int E_lockchassis_flag=1;//ȡ��ʱ����������־λ
int F_under_isle_flag=1;//����ȡǰ�ŵ�ҩ��־λ(�ܾ�����F��λ��ΪB)
int V_on_isle_flag=1;//����ȡ��ҩ��־λ
int Z_trail_flag=1;//�ϳ���־λ
int X_supply_flag=1;//������־λ
int C_open_permission=1;//������Ȩ��
int C_open_flag=1;//�����ű�־λ
int PRESS_R_lockplatform=1;//��̨������־λ
int PRESS_L_lockplatform=1;//������̨������־λ
int SHIFT_speed_switch_flag=1;//���ٶ��л���־λ
int SHIFT_command_flag=1;//Shift��ϼ���־λ
int Q_straight_angle_flag=1;//�Զ���ת180�ȱ�־λ
int CTRL_rotate_check_flag=1;//������ҩ���Լ��־λ
int CTRL_speed_switch_flag=1;//���ٶ��л���־λ

extern int interrupt;//�жϱ�־λ
extern float F_GYRO_ANGLE;
extern PID_AbsoluteType  gyro_Angle;

extern int PID_SWITCH;//�ܾ�������ȡ��ģʽPID���л�

void Value_Change(void){
    
	if(RC_Ctl.key.v&KEY_R){
		R_quit_flag=0;
		
		E_lockchassis_flag=1;//�˳�ȡ����������
	}
	
//	if(RC_Ctl.key.v&KEY_E){
//		
//	  if(F_under_isle_flag==1){	
//		E_under_isle_flag=0;
//	  }
//				
//		
//		E_lockchassis_flag=0;//ȡ��ʱ������/����/����
//		PRESS_L_lockplatform=0;//���ת�򵹳�Ӱ��
//	}
	
    if(RC_Ctl.key.v&KEY_Q){    //�����ǿ���180�ȵ���ת
		 Q_straight_angle_flag=0;
				
	}
	else{
	     Q_straight_angle_flag=1;
		 interrupt=1;
		 F_GYRO_ANGLE=0.0f;
		gyro_Angle.errNow=0.0f;
		gyro_Angle.ctrOut=0.0f;
	}
	
	if(RC_Ctl.key.v&KEY_B){  //�ܾ�����F��λ��ΪB
		
//	  if(E_under_isle_flag==1){
		F_under_isle_flag=0;
//	  }
		PID_SWITCH=0;//�ܾ�������ȡ��ģʽPID���л�
		
		E_lockchassis_flag=0;//ȡ��ʱ������/����/����
//		PRESS_L_lockplatform=0;//���ת�򵹳�Ӱ��
		
	}
	
	if(RC_Ctl.key.v&KEY_V){
 		V_on_isle_flag=0;//����ȡ��ҩ��־λ
		
		PID_SWITCH=0;//�ܾ�������ȡ��ģʽPID���л�
		
		E_lockchassis_flag=0;//ȡ��ʱ������/����/����
//		PRESS_L_lockplatform=0;//���ת�򵹳�Ӱ��
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

	}
	else{
	    PRESS_R_lockplatform=1;
	}
	
	if(RC_Ctl.mouse.press_l==1){
	    PRESS_L_lockplatform=0;
	}
	
	if(RC_Ctl.key.v&KEY_SHIFT){
  	    SHIFT_speed_switch_flag=0;
					
	}
	else{
	    SHIFT_speed_switch_flag=1;
				
	}
	
	if(RC_Ctl.key.v&KEY_CTRL){
	
//	    if(E_under_isle_flag==0){
//		SHIFT_command_flag=0;
//		}
		
//		if(F_under_isle_flag==0){
//		SHIFT_command_flag=0;
//		}
		
//		if(V_on_isle_flag==0){
//		SHIFT_command_flag=0;
//		}  
		
		CTRL_speed_switch_flag=0;
	}
	else{
	
	    CTRL_speed_switch_flag=1;
	}
     
}

