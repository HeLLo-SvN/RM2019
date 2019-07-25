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

/*********模拟量*********/
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

int auto_flag=1;//自动取弹标志位

extern int Parameter;
extern int PRESS_R_lockplatform;
extern int PRESS_L_lockplatform;

extern int E_lockchassis_flag;//取弹底盘锁定

int solenoid_valve_lock=1;//上岛电磁阀锁定
int solenoid_valve_lock1=1;//下岛电磁阀锁定


void Wheel_Direction(void)
{
 #if !Adjust
	
/******遥控器******/
	int x=0;
	int y=0;
	int z=0;
/*****键盘鼠标*****/	
	int f_w=0;
	int b_s=0;
	int l_a=0;
	int r_d=0;
	int l_m=0;
	int r_m=0;
/***恒定速度上岛***/
    int constant_upstair=0;
/***上岛后轮补偿***/
	int delta_upstair=0;
/***恒定速度下岛***/
//    int constant_downstair=0;
/***下岛后轮补偿***/
//	int delta_downstair=0;
/***恒定速度取弹***/
    int constant_grab=0;
//  int constant_grab_w=0;//底盘解算y方向分量	
//	int constant_grab_d=0;//底盘解算x方向分量

	
        x=(RC_Ctl.rc.ch3-1024)*13;
        y=(RC_Ctl.rc.ch1-1024)*13;
        z=(RC_Ctl.rc.ch2-1024)*13;
		
if(E_lockchassis_flag==1){	//取弹底盘限制
/***************W(前进)键逻辑***************/
   if(PRESS_L_lockplatform==1){	
	if(RC_Ctl.key.v&KEY_W)
    {   W_start=0;
		if(W_count_lock==1){
		F_simulation1+=10; //慢启动
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
        F_simulation1-=10;  //制动缓冲
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
/***************W(倒车)键逻辑***************/

   if(PRESS_L_lockplatform==0){
	if(RC_Ctl.key.v&KEY_W)
    {   S_start=0;
		if(S_count_lock==1){
		F_simulation2+=10; //慢启动
			S_count++;
		}
		if(S_count<=50){
			b_s=(F_simulation2-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)
		}
		else{
			S_count_lock=0;
			b_s=(F_simulation2-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)
		}			

	}
	else
	{ 
	   if(S_start^S_end){
		   S_count_lock=1;
		if(F_simulation2>1000){
        F_simulation2-=10;  //制动缓冲
			S_count--;
        b_s=(F_simulation2-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)		
		}
		else{
		F_simulation2=1000;
		b_s=(F_simulation2-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)	
			S_start=1;
			S_count=0;
		}
	 }
    }
  }	 
  
/***************S(后退)键逻辑***************/	
   if(PRESS_L_lockplatform==1){
	if(RC_Ctl.key.v&KEY_S)
    {   S_start=0;
		if(S_count_lock==1){
		F_simulation2+=10; //慢启动
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
        F_simulation2-=10;  //制动缓冲
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
/***************S(倒车)键逻辑***************/
 
   if(PRESS_L_lockplatform==0){	
	if(RC_Ctl.key.v&KEY_S)
    {   W_start=0;
		if(W_count_lock==1){
		F_simulation1+=10; //慢启动
			W_count++;
		}
		if(W_count<=50){
			f_w=(F_simulation1-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)
		}
		else{
			W_count_lock=0;
			f_w=(F_simulation1-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)
		}			

	}
	else
	{ 
	   if(W_start^W_end){
		   W_count_lock=1;
		if(F_simulation1>1000){
        F_simulation1-=10;  //制动缓冲
			W_count--;
        f_w=(F_simulation1-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)	
		}
		else{
		F_simulation1=1000;
		f_w=(F_simulation1-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)
			W_start=1;
			W_count=0;
		}
	 }
   }
  }
  
/***************A(左平移)键逻辑***************/ 
   if(PRESS_L_lockplatform==1){
	if(RC_Ctl.key.v&KEY_A)
    {   A_start=0;
		if(A_count_lock==1){
		F_simulation3+=10; //慢启动
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
        F_simulation3-=10;  //制动缓冲
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
/****************A(倒车)键逻辑****************/

   if(PRESS_L_lockplatform==0){
    if(RC_Ctl.key.v&KEY_A)
    {   D_start=0;
		if(D_count_lock==1){
		F_simulation4+=10; //慢启动
			D_count++;
		}
		if(D_count<=50){
			r_d=(F_simulation4-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)
		}
		else{
			D_count_lock=0;
			r_d=(F_simulation4-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)
		}			

	}
	else
	{ 
	   if(D_start^D_end){
		   D_count_lock=1;
		if(F_simulation4>1000){
        F_simulation4-=10;  //制动缓冲
			D_count--;
        r_d=(F_simulation4-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)	
		}
		else{
		F_simulation4=1000;
		r_d=(F_simulation4-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)	
			D_start=1;
			D_count=0;
		}
	 }
   }
  }	
  
/***************D(右平移)键逻辑***************/  
  if(PRESS_L_lockplatform==1){
    if(RC_Ctl.key.v&KEY_D)
    {   D_start=0;
		if(D_count_lock==1){
		F_simulation4+=10; //慢启动
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
        F_simulation4-=10;  //制动缓冲
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
/****************D(倒车)键逻辑****************/

   if(PRESS_L_lockplatform==0){
	if(RC_Ctl.key.v&KEY_D)
    {   A_start=0;
		if(A_count_lock==1){
		F_simulation3+=10; //慢启动
			A_count++;
		}
		if(A_count<=50){
			l_a=(F_simulation3-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)
		}
		else{
			A_count_lock=0;
			l_a=(F_simulation3-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)
		}			

	}
	else
	{ 
	   if(A_start^A_end){
		   A_count_lock=1;
		if(F_simulation3>1000){
        F_simulation3-=10;  //制动缓冲
			A_count--;
        l_a=(F_simulation3-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)		
		}
		else{
		F_simulation3=1000;
		l_a=(F_simulation3-1000)*Parameter;//4;(总决赛改为倒车速度不受影响)	
			A_start=1;
			A_count=0;
		}
	 }
   } 
  }	 

/***************L_mouse(左旋转)逻辑***************/ 

    if(RC_Ctl.mouse.x<0)
    {   
	  if(PRESS_R_lockplatform==1){
	 l_m=RC_Ctl.mouse.x*Rotate_Parameter;
	   }
	}

	  
/***************R_mouse(右旋转)逻辑***************/ 

    if(RC_Ctl.mouse.x>0)
    {  
	  if(PRESS_R_lockplatform==1){
     r_m=RC_Ctl.mouse.x*Rotate_Parameter;
	   }
	}
}
else
{
/*************按E(取弹W前进)键逻辑*************/   
	if(RC_Ctl.key.v&KEY_W)
    {   W_start=0;
		if(W_count_lock==1){
		F_simulation1+=10; //慢启动
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
        F_simulation1-=10;  //制动缓冲
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
/*************按E(取弹S后退)键逻辑*************/
    if(RC_Ctl.key.v&KEY_S)
    {   S_start=0;
		if(S_count_lock==1){
		F_simulation2+=10; //慢启动
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
        F_simulation2-=10;  //制动缓冲
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
/*************按E(取弹A左移)键逻辑*************/
	if(RC_Ctl.key.v&KEY_A)
    {   A_start=0;
		if(A_count_lock==1){
		F_simulation3+=10; //慢启动
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
        F_simulation3-=10;  //制动缓冲
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
/*************按E(取弹D右移)键逻辑*************/
   if(RC_Ctl.key.v&KEY_D)
    {   D_start=0;
		if(D_count_lock==1){
		F_simulation4+=10; //慢启动
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
        F_simulation4-=10;  //制动缓冲
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
/*****************恒定速度上岛逻辑*****************/ 
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
/*****************恒定速度下岛逻辑*****************/ 
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
/*****************恒定速度取弹逻辑*****************/
    if(auto_flag==0)                                                              
    {
	  constant_grab=1000;
//	  constant_grab_w=1000;//底盘解算y方向分量	
//	  constant_grab_d=1500;//底盘解算x方向分量
		
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
