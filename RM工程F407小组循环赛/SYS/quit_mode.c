#include "main.h"

extern int s_time_count;//基恩士判断之前定时器计数变量
extern int un_time_count;//基恩士判断之后定时器计数变量
extern int N_time_count;//第二次基恩士判断之后定时器计数变量

extern int on_s_time_count;//基恩士判断之前定时器计数变量
extern int on_time_count;//基恩士判断之后定时器计数变量
extern int on_N_time_count;//第二次基恩士判断之后定时器计数变量

extern int on_DN_time_count;//第三次基恩士判断之后定时器计数变量（淘汰赛追加）

extern int DN_time_count;//第三次基恩士判断之后定时器计数变量（总决赛追加）

/********基恩士识别标志位********/
extern int times;
extern int times_lock;
extern int times_lock1;
extern int times_lock2;
extern int times_lock3;
extern int last_value;
extern int last_value1;

extern int First;
extern int Double;
extern int Triple;

extern int Start;

extern int N_First;
extern int N_Double;
extern int N_Triple;

extern int N_times;
extern int N_times_lock;
extern int N_times_lock1;
extern int N_times_lock2;
extern int N_times_lock3;
extern int N_last_value;
extern int N_last_value1;

extern int N_Start;

extern int on_Grab_Condition;

extern int on_First;
extern int on_Double;
extern int on_Triple;

extern int on_times;
extern int on_times_lock;
extern int on_times_lock1;
extern int on_times_lock2;
extern int on_times_lock3;
extern int on_last_value;
extern int on_last_value1;

extern int on_Start;

extern int on_N_Grab_Condition;

extern int on_N_First;
extern int on_N_Double;
extern int on_N_Triple;

extern int on_N_times;
extern int on_N_times_lock;
extern int on_N_times_lock1;
extern int on_N_times_lock2;
extern int on_N_times_lock3;
extern int on_N_last_value;
extern int on_N_last_value1;

extern int on_N_Start;

/*********（淘汰赛追加）*********/

extern int on_DN_Grab_Condition;

extern int on_DN_First;
extern int on_DN_Double;
extern int on_DN_Triple;

extern int on_DN_times;
extern int on_DN_times_lock;
extern int on_DN_times_lock1;
extern int on_DN_times_lock2;
extern int on_DN_times_lock3;
extern int on_DN_last_value;
extern int on_DN_last_value1;

extern int on_DN_Start;

/*********（总决赛追加）*********/

extern int DN_Grab_Condition;

extern int DN_First;
extern int DN_Double;
extern int DN_Triple;

extern int DN_times;
extern int DN_times_lock;
extern int DN_times_lock1;
extern int DN_times_lock2;
extern int DN_times_lock3;
extern int DN_last_value;
extern int DN_last_value1;

extern int DN_Start;

/********************************/

int quit_time_count;

extern int Lift_flag;
extern int pop_flag;

/***********缓冲标志位***********/
/******岛下前排弹药箱标志位******/
extern int buffer_lock;
extern int buffer_lock1;
extern int buffer_lock2;
extern int buffer_lock3;
extern int buffer_lock4;
/****岛下连续取两盒前排弹药箱****/
extern int buffer_lock5;
extern int buffer_lock6;
extern int buffer_lock7;
extern int buffer_lock8;
extern int buffer_lock9;

extern int buffer_lock10;
extern int buffer_lock11;
extern int buffer_lock12;
extern int buffer_lock13;
extern int buffer_lock14;
/******岛下后排弹药箱标志位******/
extern int buffer_lock15;
extern int buffer_lock16;
extern int buffer_lock17;
extern int buffer_lock18;
extern int buffer_lock19;
/*****岛下连续取两盒后排弹药*****/
extern int buffer_lock20;
extern int buffer_lock21;
extern int buffer_lock22;
extern int buffer_lock23;
extern int buffer_lock24;

extern int buffer_lock25;
extern int buffer_lock26;
extern int buffer_lock27;
extern int buffer_lock28;
extern int buffer_lock29;

/****岛上连续取两盒弹药箱****/

extern int on_buffer_lock20;
extern int on_buffer_lock21;
extern int on_buffer_lock22;
extern int on_buffer_lock23;
extern int on_buffer_lock24;

extern int on_buffer_lock25;
extern int on_buffer_lock26;
extern int on_buffer_lock27;
extern int on_buffer_lock28;
extern int on_buffer_lock29;
		
/******岛上弹药箱标志位******/	

extern int on_buffer_lock15;
extern int on_buffer_lock16;
extern int on_buffer_lock17;
extern int on_buffer_lock18;
extern int on_buffer_lock19;
/*******************************/

extern int R_quit_flag;//退出取弹环节标志位
extern int E_under_isle_flag;//岛下取后排弹药标志位
extern int E_lockchassis_flag;
extern int F_under_isle_flag;
extern int Z_trail_flag;
extern int X_supply_flag;
extern int C_open_permission;//开舱门权限
extern int C_open_flag;
extern int SHIFT_speed_switch_flag;
extern int CTRL_speed_switch_flag;
extern int SHIFT_command_flag;//Shift组合键标志位


extern int V_on_isle_flag;//岛上取弹药标志位

extern int auto_flag;//自动取弹标志位
extern int auto_buffer1;
extern int auto_buffer2;
extern int auto_buffer3;

extern int deadlock1;
extern int deadlock2;
extern int deadlock3;
extern int deadlock4;
extern int deadlock5;

extern int KILL;

extern int on_deadlock1;
extern int on_deadlock2;
extern int on_deadlock3;
extern int on_deadlock4;
extern int on_deadlock5;
extern int on_deadlock6;//（淘汰赛追加）
extern int on_deadlock7;//（淘汰赛追加）

extern int D_deadlock6;//（总决赛追加）
extern int D_deadlock7;//（总决赛追加）

extern int on_KILL;

/**********消息队列令牌**********/
	extern int token1;
	extern int on_token1;


/*****岛下连续取前排弹药模式*****/
/**********连续性标志位**********/
    extern int continuity1;
	extern int continuity2;
	extern int continuity3;
    extern int continuity4;
	extern int continuity5;
	extern int continuity6;
    extern int continuity7;
	extern int continuity8;
	extern int continuity9;		
    extern int continuity10;
	extern int continuity11;
	extern int continuity12;
	extern int continuity13;
	extern int continuity14;
	extern int continuity15;		
    extern int continuity16;
	extern int continuity17;
	extern int continuity18;
	extern int continuity19;
	extern int continuity20;		
    extern int continuity21;
	extern int continuity22;

/*****岛下连续取后排弹药模式*****/
/*****第一次识别连续性标志位*****/
    extern int B_continuity1;
	extern int B_continuity2;
	extern int B_continuity3;
    extern int B_continuity4;
	extern int B_continuity5;
	extern int B_continuity6;
    extern int B_continuity7;
	extern int B_continuity8;
	extern int B_continuity9;		
    extern int B_continuity10;
	extern int B_continuity11;
	extern int B_continuity12;
	extern int B_continuity13;
	extern int B_continuity14;
	extern int B_continuity15;
		
/*****第二次识别连续性标志位*****/		
    extern int B_continuity16;
	extern int B_continuity17;
	extern int B_continuity18;
	extern int B_continuity19;		
    extern int B_continuity20;
	extern int B_continuity21;
	extern int B_continuity22;
	extern int B_continuity23;
	
/******岛上连续取弹药箱模式******/
/*****第一次识别连续性标志位*****/
    extern int on_continuity1;
	extern int on_continuity2;
	extern int on_continuity3;
    extern int on_continuity4;
	extern int on_continuity5;
	extern int on_continuity6;
    extern int on_continuity7;
	extern int on_continuity8;
	extern int on_continuity9;		
    extern int on_continuity10;
	extern int on_continuity11;
	extern int on_continuity12;
	extern int on_continuity13;
	extern int on_continuity14;
	extern int on_continuity15;
		
/*****第二次识别连续性标志位*****/		
    extern int on_continuity16;
	extern int on_continuity17;
	extern int on_continuity18;
   	extern int on_continuity19;		
    extern int on_continuity20;
	extern int on_continuity21;
	extern int on_continuity22;
   	extern int on_continuity23;

/*****第三次识别连续性标志位*****/ ///（淘汰赛追加）	
    extern int on_D_continuity16;
	extern int on_D_continuity17;
	extern int on_D_continuity18;
   	extern int on_D_continuity19;		
    extern int on_D_continuity20;
	extern int on_D_continuity21;
	extern int on_D_continuity22;
   	extern int on_D_continuity23;

/*****第三次识别连续性标志位*****/ ///（总决赛追加）	
    extern int D_continuity16;
	extern int D_continuity17;
	extern int D_continuity18;
   	extern int D_continuity19;		
    extern int D_continuity20;
	extern int D_continuity21;
	extern int D_continuity22;
   	extern int D_continuity23;
	extern int D_continuity24;

	extern int PID_SWITCH;//总决赛新增取弹模式PID的切换

void Quit_Mode(void)
{
        if(R_quit_flag==0){
		
         PID_SWITCH=1;//总决赛新增取弹模式PID的切换
			
		 quit_time_count++;
		 
		 s_time_count=0;//基恩士判断之前定时器计数变量
		 un_time_count=0;//基恩士判断之后定时器计数变量
	     N_time_count=0;//第二次基恩士判断之后定时器计数变量	
					
		 on_s_time_count=0;
		 on_time_count=0;
         on_N_time_count=0;			
			
		 on_DN_time_count=0;//第三次基恩士判断之后定时器计数变量（淘汰赛追加）	
			
		 DN_time_count=0;//第三次基恩士判断之后定时器计数变量（总决赛追加）	
		 			
		 auto_flag=1;//自动取弹标志位
		 auto_buffer1=1;
		 auto_buffer2=1;
		 auto_buffer3=1;
		 
		 E_under_isle_flag=1;//杀死岛下取后排弹药标志位	
		 E_lockchassis_flag=1;
		 		 
		 F_under_isle_flag=1;
		 			 
		 X_supply_flag=1;
		 C_open_permission=1;
		 C_open_flag=1;
		 
		 SHIFT_speed_switch_flag=1;
		 CTRL_speed_switch_flag=1;
		 
		 SHIFT_command_flag=1;//组合键标志位
		 		 
		 V_on_isle_flag=1;//岛上取弹药标志位
		 
		 Z_trail_flag=1;
/********模式1连续性标志位*******/

        continuity1=1;
		continuity2=1;
		continuity3=1;
        continuity4=1;
		continuity5=1;
		continuity6=1;
        continuity7=1;
		continuity8=1;
		continuity9=1;		
        continuity10=1;
		continuity11=1;
		continuity12=1;
		continuity13=1;
		continuity14=1;
		continuity15=1;		
        continuity16=1;
		continuity17=1;
		continuity18=1;
		continuity19=1;		
        continuity20=1;
		continuity21=1;
		continuity22=1;

/********模式2连续性标志位*******/

/*****第一次识别连续性标志位*****/
        B_continuity1=1;
		B_continuity2=1;
		B_continuity3=1;
        B_continuity4=1;
		B_continuity5=1;
		B_continuity6=1;
        B_continuity7=1;
		B_continuity8=1;
		B_continuity9=1;		
        B_continuity10=1;
		B_continuity11=1;
		B_continuity12=1;
		B_continuity13=1;
		B_continuity14=1;
		B_continuity15=1;
		
/*****第二次识别连续性标志位*****/		
        B_continuity16=1;
	    B_continuity17=1;
	    B_continuity18=1;
		B_continuity19=1;		
        B_continuity20=1;
	    B_continuity21=1;
	    B_continuity22=1;
		B_continuity23=1;
		
/********模式3连续性标志位*******/

/*****第一次识别连续性标志位*****/
       on_continuity1=1;
	   on_continuity2=1;
	   on_continuity3=1;
       on_continuity4=1;
	   on_continuity5=1;
	   on_continuity6=1;
       on_continuity7=1;
	   on_continuity8=1;
	   on_continuity9=1;		
       on_continuity10=1;
	   on_continuity11=1;
	   on_continuity12=1;
	   on_continuity13=1;
	   on_continuity14=1;
	   on_continuity15=1;
		
/*****第二次识别连续性标志位*****/		
       on_continuity16=1;
	   on_continuity17=1;
	   on_continuity18=1;
   	   on_continuity19=1;		
       on_continuity20=1;
	   on_continuity21=1;
	   on_continuity22=1;
   	   on_continuity23=1;

/*****第三次识别连续性标志位*****/ ///（淘汰赛追加）	
       on_D_continuity16=1;
	   on_D_continuity17=1;
	   on_D_continuity18=1;
   	   on_D_continuity19=1;		
       on_D_continuity20=1;
	   on_D_continuity21=1;
	   on_D_continuity22=1;
   	   on_D_continuity23=1;	

/*****第三次识别连续性标志位*****/ ///（总决赛追加）	
       D_continuity16=1;
	   D_continuity17=1;
	   D_continuity18=1;
   	   D_continuity19=1;		
       D_continuity20=1;
	   D_continuity21=1;
	   D_continuity22=1;
   	   D_continuity23=1;
       D_continuity24=1;	   

/**********消息队列令牌**********/		 
	     token1=0;
         on_token1=0;		 
/********************************/			 
		 Lift_flag=1;
		 pop_flag=1;
/********基恩士识别标志位********/
         times=0;
		 times_lock=1;
		 times_lock1=1;
		 times_lock2=1;
		 times_lock3=1;
		 last_value=0;
         last_value1=0;
						
          First=0;
		  Double=0;
		  Triple=0;
				 				 		 		 
		  Start=1;

         N_First=0;
	     N_Double=0;
		 N_Triple=0;

		 N_times=0;
		 N_times_lock=1;
		 N_times_lock1=1;
		 N_times_lock2=1;
		 N_times_lock3=1;
		 N_last_value=0;
		 N_last_value1=0;

		  N_Start=1;
		  
		 on_First=0;
		 on_Double=0;
		 on_Triple=0;

		 on_times=0;
		 on_times_lock=1;
		 on_times_lock1=1;
		 on_times_lock2=1;
		 on_times_lock3=1;
		 on_last_value=0;
		 on_last_value1=0;

		  on_Start=1;
				
		 on_N_First=0;
		 on_N_Double=0;
		 on_N_Triple=0;

		 on_N_times=0;
		 on_N_times_lock=1;
		 on_N_times_lock1=1;
		 on_N_times_lock2=1;
	     on_N_times_lock3=1;
		 on_N_last_value=0;
		 on_N_last_value1=0;

		 on_N_Start=1;
		 
		 on_DN_First=0;
         on_DN_Double=0;
         on_DN_Triple=0;

         on_DN_times=0;
         on_DN_times_lock=1;
         on_DN_times_lock1=1;
         on_DN_times_lock2=1;
         on_DN_times_lock3=1;
         on_DN_last_value=0;
         on_DN_last_value1=0;

         on_DN_Start=1;		 
		 
		 DN_First=0;
         DN_Double=0;
         DN_Triple=0;

         DN_times=0;
         DN_times_lock=1;
         DN_times_lock1=1;
         DN_times_lock2=1;
         DN_times_lock3=1;
         DN_last_value=0;
         DN_last_value1=0;

         DN_Start=1;	
		 
/***********自锁标志位***********/
        deadlock1=1;
		deadlock2=1;
		deadlock3=1;
		deadlock4=1;
		deadlock5=1;
		
		KILL=1;
/*********上岛自锁标志位*********/
       on_deadlock1=1;
	   on_deadlock2=1;
	   on_deadlock3=1;
	   on_deadlock4=1;
	   on_deadlock5=1;
       on_deadlock6=1;//（淘汰赛追加）
	   on_deadlock7=1;//（淘汰赛追加）
	   
	   D_deadlock6=1;//（总决赛追加）
	   D_deadlock7=1;//（总决赛追加）
	   
       on_KILL=1;

/***********缓冲标志位***********/
/******岛下前排弹药箱标志位******/		 
		 buffer_lock=1;
         buffer_lock1=1;
         buffer_lock2=1;
         buffer_lock3=1;
         buffer_lock4=1;
/****岛下连续取两盒前排弹药箱****/
		 buffer_lock5=1;
		 buffer_lock6=1;
		 buffer_lock7=1;
		 buffer_lock8=1;
		 buffer_lock9=1;

		 buffer_lock10=1;
		 buffer_lock11=1;
		 buffer_lock12=1;
		 buffer_lock13=1;
		 buffer_lock14=1;
/******岛下后排弹药箱标志位******/
		 buffer_lock15=1;
		 buffer_lock16=1;
		 buffer_lock17=1;
		 buffer_lock18=1;
		 buffer_lock19=1;
/*****岛下连续取两盒后排弹药*****/
		 buffer_lock20=1;
		 buffer_lock21=1;
		 buffer_lock22=1;
		 buffer_lock23=1;
		 buffer_lock24=1;

		 buffer_lock25=1;
		 buffer_lock26=1;
		 buffer_lock27=1;
		 buffer_lock28=1;
		 buffer_lock29=1;
/****岛上连续取两盒弹药箱****/

	     on_buffer_lock20=1;
	     on_buffer_lock21=1;
	     on_buffer_lock22=1;
	     on_buffer_lock23=1;
	     on_buffer_lock24=1;

	     on_buffer_lock25=1;
	     on_buffer_lock26=1;
	     on_buffer_lock27=1;
	     on_buffer_lock28=1;
	     on_buffer_lock29=1;
		
/******岛上弹药箱标志位******/	

	     on_buffer_lock15=1;
	     on_buffer_lock16=1;
	     on_buffer_lock17=1;
	     on_buffer_lock18=1;
	     on_buffer_lock19=1;		 
/*******************************/

		 Action_Resetting();
		 
		 

	 }

}
