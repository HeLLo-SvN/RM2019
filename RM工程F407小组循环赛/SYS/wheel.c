#include "main.h"

extern RC_Ctl_t RC_Ctl;

extern double TV1;
extern double TV2;
extern double TV3;

int16_t T_TOP_L=0;
int16_t T_TOP_R=0;
int16_t T_DOWN_L=0;
int16_t T_DOWN_R=0;
int16_t T_MID_L=0;
int16_t T_MID_R=0;

extern float F_GYRO_ANGLE;

/*********ģ����*********/
int F_simulation1=1000;
int F_simulation2=1000;
int F_simulation3=1000;
int F_simulation4=1000;

int W_count=1;
int W_count_lock=1;
int S_count=1;
int S_count_lock=1;
int A_count=1;
int A_count_lock=1;
int D_count=1;
int D_count_lock=1;

int W_start=1;
int W_end=1;
int S_start=1;
int S_end=1;
int A_start=1;
int A_end=1;
int D_start=1;
int D_end=1;

int auto_flag=1;//�Զ�ȡ����־λ

extern int Parameter;
extern int PRESS_R_lockplatform;
extern int PRESS_L_lockplatform;

extern int E_lockchassis_flag;//ȡ����������

int solenoid_valve_lock=1;//�ϵ���ŷ�����
int solenoid_valve_lock1=1;//�µ���ŷ�����


void Wheel_Direction(void)
{
 #if !Adjust
	
/******ң����******/
	int x=0;
	int y=0;
	int z=0;
/*****�������*****/	
	int f_w=0;
	int b_s=0;
	int l_a=0;
	int r_d=0;
	int l_m=0;
	int r_m=0;
/***�㶨�ٶ��ϵ�***/
    int constant_upstair=0;
/***�ϵ����ֲ���***/
	int delta_upstair=0;
/***�㶨�ٶ��µ�***/
//    int constant_downstair=0;
/***�µ����ֲ���***/
//	int delta_downstair=0;
/***�㶨�ٶ�ȡ��***/
    int constant_grab=0;
//  int constant_grab_w=0;//���̽���y�������	
//	int constant_grab_d=0;//���̽���x�������

	
        x=(RC_Ctl.rc.ch3-1024)*13;
        y=(RC_Ctl.rc.ch1-1024)*13;
        z=(RC_Ctl.rc.ch2-1024)*13;
		
if(E_lockchassis_flag==1){	//ȡ����������
/***************W(ǰ��)���߼�***************/
   if(PRESS_L_lockplatform==1){	
	if(RC_Ctl.key.v&KEY_W)
    {   W_start=0;
		if(W_count_lock==1){
		F_simulation1+=10; //������
			W_count++;
		}
		if(W_count<=50){
			f_w=(F_simulation1-1000)*Parameter;
		}
		else{
			W_count_lock=0;
			f_w=(F_simulation1-1000)*Parameter;
		}			

	}
	else
	{ 
	   if(W_start^W_end){
		   W_count_lock=1;
		if(F_simulation1>1000){
        F_simulation1-=10;  //�ƶ�����
			W_count--;
        f_w=(F_simulation1-1000)*Parameter;		
		}
		else{
		F_simulation1=1000;
		f_w=(F_simulation1-1000)*Parameter;
			W_start=1;
			W_count=0;
		}
	 }
   }
 }
/***************W(����)���߼�***************/

   if(PRESS_L_lockplatform==0){
	if(RC_Ctl.key.v&KEY_W)
    {   S_start=0;
		if(S_count_lock==1){
		F_simulation2+=10; //������
			S_count++;
		}
		if(S_count<=50){
			b_s=(F_simulation2-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)
		}
		else{
			S_count_lock=0;
			b_s=(F_simulation2-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)
		}			

	}
	else
	{ 
	   if(S_start^S_end){
		   S_count_lock=1;
		if(F_simulation2>1000){
        F_simulation2-=10;  //�ƶ�����
			S_count--;
        b_s=(F_simulation2-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)		
		}
		else{
		F_simulation2=1000;
		b_s=(F_simulation2-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)	
			S_start=1;
			S_count=0;
		}
	 }
    }
  }	 
  
/***************S(����)���߼�***************/	
   if(PRESS_L_lockplatform==1){
	if(RC_Ctl.key.v&KEY_S)
    {   S_start=0;
		if(S_count_lock==1){
		F_simulation2+=10; //������
			S_count++;
		}
		if(S_count<=50){
			b_s=(F_simulation2-1000)*Parameter;
		}
		else{
			S_count_lock=0;
			b_s=(F_simulation2-1000)*Parameter;
		}			

	}
	else
	{ 
	   if(S_start^S_end){
		   S_count_lock=1;
		if(F_simulation2>1000){
        F_simulation2-=10;  //�ƶ�����
			S_count--;
        b_s=(F_simulation2-1000)*Parameter;		
		}
		else{
		F_simulation2=1000;
		b_s=(F_simulation2-1000)*Parameter;	
			S_start=1;
			S_count=0;
		}
	 }
    }
  }
/***************S(����)���߼�***************/
 
   if(PRESS_L_lockplatform==0){	
	if(RC_Ctl.key.v&KEY_S)
    {   W_start=0;
		if(W_count_lock==1){
		F_simulation1+=10; //������
			W_count++;
		}
		if(W_count<=50){
			f_w=(F_simulation1-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)
		}
		else{
			W_count_lock=0;
			f_w=(F_simulation1-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)
		}			

	}
	else
	{ 
	   if(W_start^W_end){
		   W_count_lock=1;
		if(F_simulation1>1000){
        F_simulation1-=10;  //�ƶ�����
			W_count--;
        f_w=(F_simulation1-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)	
		}
		else{
		F_simulation1=1000;
		f_w=(F_simulation1-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)
			W_start=1;
			W_count=0;
		}
	 }
   }
  }
  
/***************A(��ƽ��)���߼�***************/ 
   if(PRESS_L_lockplatform==1){
	if(RC_Ctl.key.v&KEY_A)
    {   A_start=0;
		if(A_count_lock==1){
		F_simulation3+=10; //������
			A_count++;
		}
		if(A_count<=50){
			l_a=(F_simulation3-1000)*Parameter;
		}
		else{
			A_count_lock=0;
			l_a=(F_simulation3-1000)*Parameter;
		}			

	}
	else
	{ 
	   if(A_start^A_end){
		   A_count_lock=1;
		if(F_simulation3>1000){
        F_simulation3-=10;  //�ƶ�����
			A_count--;
        l_a=(F_simulation3-1000)*Parameter;		
		}
		else{
		F_simulation3=1000;
		l_a=(F_simulation3-1000)*Parameter;	
			A_start=1;
			A_count=0;
		}
	 }
   } 
 }	
/****************A(����)���߼�****************/

   if(PRESS_L_lockplatform==0){
    if(RC_Ctl.key.v&KEY_A)
    {   D_start=0;
		if(D_count_lock==1){
		F_simulation4+=10; //������
			D_count++;
		}
		if(D_count<=50){
			r_d=(F_simulation4-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)
		}
		else{
			D_count_lock=0;
			r_d=(F_simulation4-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)
		}			

	}
	else
	{ 
	   if(D_start^D_end){
		   D_count_lock=1;
		if(F_simulation4>1000){
        F_simulation4-=10;  //�ƶ�����
			D_count--;
        r_d=(F_simulation4-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)	
		}
		else{
		F_simulation4=1000;
		r_d=(F_simulation4-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)	
			D_start=1;
			D_count=0;
		}
	 }
   }
  }	
  
/***************D(��ƽ��)���߼�***************/  
  if(PRESS_L_lockplatform==1){
    if(RC_Ctl.key.v&KEY_D)
    {   D_start=0;
		if(D_count_lock==1){
		F_simulation4+=10; //������
			D_count++;
		}
		if(D_count<=50){
			r_d=(F_simulation4-1000)*Parameter;
		}
		else{
			D_count_lock=0;
			r_d=(F_simulation4-1000)*Parameter;
		}			

	}
	else
	{ 
	   if(D_start^D_end){
		   D_count_lock=1;
		if(F_simulation4>1000){
        F_simulation4-=10;  //�ƶ�����
			D_count--;
        r_d=(F_simulation4-1000)*Parameter;	
		}
		else{
		F_simulation4=1000;
		r_d=(F_simulation4-1000)*Parameter;	
			D_start=1;
			D_count=0;
		}
	 }
   }
 }
/****************D(����)���߼�****************/

   if(PRESS_L_lockplatform==0){
	if(RC_Ctl.key.v&KEY_D)
    {   A_start=0;
		if(A_count_lock==1){
		F_simulation3+=10; //������
			A_count++;
		}
		if(A_count<=50){
			l_a=(F_simulation3-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)
		}
		else{
			A_count_lock=0;
			l_a=(F_simulation3-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)
		}			

	}
	else
	{ 
	   if(A_start^A_end){
		   A_count_lock=1;
		if(F_simulation3>1000){
        F_simulation3-=10;  //�ƶ�����
			A_count--;
        l_a=(F_simulation3-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)		
		}
		else{
		F_simulation3=1000;
		l_a=(F_simulation3-1000)*Parameter;//4;(�ܾ�����Ϊ�����ٶȲ���Ӱ��)	
			A_start=1;
			A_count=0;
		}
	 }
   } 
  }	 

/***************L_mouse(����ת)�߼�***************/ 

    if(RC_Ctl.mouse.x<0)
    {   
	  if(PRESS_R_lockplatform==1){
	 l_m=RC_Ctl.mouse.x*Rotate_Parameter;
	   }
	}

	  
/***************R_mouse(����ת)�߼�***************/ 

    if(RC_Ctl.mouse.x>0)
    {  
	  if(PRESS_R_lockplatform==1){
     r_m=RC_Ctl.mouse.x*Rotate_Parameter;
	   }
	}
}
else
{
/*************��E(ȡ��Wǰ��)���߼�*************/   
	if(RC_Ctl.key.v&KEY_W)
    {   W_start=0;
		if(W_count_lock==1){
		F_simulation1+=10; //������
			W_count++;
		}
		if(W_count<=50){
			f_w=(F_simulation1-1000)*Parameter;
		}
		else{
			W_count_lock=0;
			f_w=(F_simulation1-1000)*Parameter;
		}			

	}
	else
	{ 
	   if(W_start^W_end){
		   W_count_lock=1;
		if(F_simulation1>1000){
        F_simulation1-=10;  //�ƶ�����
			W_count--;
        f_w=(F_simulation1-1000)*Parameter;		
		}
		else{
		F_simulation1=1000;
		f_w=(F_simulation1-1000)*Parameter;
			W_start=1;
			W_count=0;
		}
	 }
   }
/*************��E(ȡ��S����)���߼�*************/
    if(RC_Ctl.key.v&KEY_S)
    {   S_start=0;
		if(S_count_lock==1){
		F_simulation2+=10; //������
			S_count++;
		}
		if(S_count<=50){
			b_s=(F_simulation2-1000)*Parameter;
		}
		else{
			S_count_lock=0;
			b_s=(F_simulation2-1000)*Parameter;
		}			

	}
	else
	{ 
	   if(S_start^S_end){
		   S_count_lock=1;
		if(F_simulation2>1000){
        F_simulation2-=10;  //�ƶ�����
			S_count--;
        b_s=(F_simulation2-1000)*Parameter;		
		}
		else{
		F_simulation2=1000;
		b_s=(F_simulation2-1000)*Parameter;	
			S_start=1;
			S_count=0;
		}
	 }
    } 
/*************��E(ȡ��A����)���߼�*************/
	if(RC_Ctl.key.v&KEY_A)
    {   A_start=0;
		if(A_count_lock==1){
		F_simulation3+=10; //������
			A_count++;
		}
		if(A_count<=50){
			l_a=(F_simulation3-1000)*Parameter;
		}
		else{
			A_count_lock=0;
			l_a=(F_simulation3-1000)*Parameter;
		}			

	}
	else
	{ 
	   if(A_start^A_end){
		   A_count_lock=1;
		if(F_simulation3>1000){
        F_simulation3-=10;  //�ƶ�����
			A_count--;
        l_a=(F_simulation3-1000)*Parameter;		
		}
		else{
		F_simulation3=1000;
		l_a=(F_simulation3-1000)*Parameter;	
			A_start=1;
			A_count=0;
		}
	 }
   }
/*************��E(ȡ��D����)���߼�*************/
   if(RC_Ctl.key.v&KEY_D)
    {   D_start=0;
		if(D_count_lock==1){
		F_simulation4+=10; //������
			D_count++;
		}
		if(D_count<=50){
			r_d=(F_simulation4-1000)*Parameter;
		}
		else{
			D_count_lock=0;
			r_d=(F_simulation4-1000)*Parameter;
		}			

	}
	else
	{ 
	   if(D_start^D_end){
		   D_count_lock=1;
		if(F_simulation4>1000){
        F_simulation4-=10;  //�ƶ�����
			D_count--;
        r_d=(F_simulation4-1000)*Parameter;	
		}
		else{
		F_simulation4=1000;
		r_d=(F_simulation4-1000)*Parameter;	
			D_start=1;
			D_count=0;
		}
	 }
   }
}
/*****************�㶨�ٶ��ϵ��߼�*****************/ 
	if(RC_Ctl.key.v&KEY_G)
    {
	  constant_upstair=3600;
		
		delta_upstair=2000;
			   	
		//Toward_Left();
	   	   
	   solenoid_valve_lock=0;
	   
	}
	else{
	  if(solenoid_valve_lock==0){
	  
	    //Toward_Right();
		solenoid_valve_lock=1;
	   
      }
	}
/*****************�㶨�ٶ��µ��߼�*****************/ 
//	if(RC_Ctl.key.v&KEY_B)
//    {
//	  constant_downstair=2500;
//		
//		delta_downstair=2000;
//			   	
//		//Toward_Left();
//	   	   
//	   solenoid_valve_lock1=0;
//	   
//	}
//	else{
//	  if(solenoid_valve_lock1==0){
//	  
//	    //Toward_Right();
//		solenoid_valve_lock1=1;
//	   
//      }
//	}	
/*****************�㶨�ٶ�ȡ���߼�*****************/
    if(auto_flag==0)                                                              
    {
	  constant_grab=1000;
//	  constant_grab_w=1000;//���̽���y�������	
//	  constant_grab_d=1500;//���̽���x�������
		
	}  
	
 #endif
 
 #if Adjust
	
	int x;
	int y;
	int z;
	
	x=TV1;
	y=TV2;
	z=TV3;
	
 #endif
	
 T_TOP_L=x+y+z+f_w-b_s-l_a+r_d+l_m+r_m+constant_upstair+constant_grab-F_GYRO_ANGLE;//-constant_downstair+constant_grab_w+constant_grab_d
 T_TOP_R=x-y+z-f_w+b_s-l_a+r_d+l_m+r_m-constant_upstair+constant_grab-F_GYRO_ANGLE;//+constant_downstair-constant_grab_w+constant_grab_d
 T_DOWN_L=-x+y+z+f_w-b_s+l_a-r_d+l_m+r_m+constant_upstair-constant_grab-F_GYRO_ANGLE;//-constant_downstair+constant_grab_w-constant_grab_d
 T_DOWN_R=-x-y+z-f_w+b_s+l_a-r_d+l_m+r_m-constant_upstair-constant_grab-F_GYRO_ANGLE;//+constant_downstair-constant_grab_w-constant_grab_d
 T_MID_L=y+z+f_w-b_s+l_m+r_m+constant_upstair+delta_upstair-F_GYRO_ANGLE;//-constant_downstair-delta_downstair
 T_MID_R=-y+z-f_w+b_s+l_m+r_m-constant_upstair-delta_upstair-F_GYRO_ANGLE;//+constant_downstair+delta_downstair
 
 
}
