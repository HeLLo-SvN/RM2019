#include "main.h"

//extern int grab_baseline;

extern int32_t T_LIFT_POSITION_R;

extern int32_t T_GRAB_POSITION;

extern int32_t T_ROTATE_POSITION;

/******启动准备弹药箱标志位******/
extern int start_F_lock1;
extern int start_F_lock2;

extern int start_B_lock1;
extern int start_B_lock2;
extern int start_B_lock3;

/*****岛上准备取弹药箱标志位*****/

extern int start_ON_lock1;
extern int start_ON_lock2;
extern int start_ON_lock3;

/***岛下取一盒前排弹药箱标志位***/
extern int un_O_F_lock1;
extern int un_O_F_lock2;
extern int un_O_F_lock3;
extern int un_O_F_lock4;
extern int un_O_F_lock5;
extern int un_O_F_lock6;
extern int un_O_F_lock7;
extern int un_O_F_lock8;
extern int un_O_F_lock9;
/***岛下连续取两盒前排弹药箱标志位***/
extern int un_T_F_lock1;
extern int un_T_F_lock2;
extern int un_T_F_lock3;
extern int un_T_F_lock4;
extern int un_T_F_lock5;
extern int un_T_F_lock6;
extern int un_T_F_lock7;
extern int un_T_F_lock8;
extern int un_T_F_lock9;
extern int un_T_F_lock10;
extern int un_T_F_lock11;
extern int un_T_F_lock12;
extern int un_T_F_lock13;
extern int un_T_F_lock14;
extern int un_T_F_lock19;//（追加序号）
extern int un_T_F_lock15;
extern int un_T_F_lock16;
extern int un_T_F_lock17;
extern int un_T_F_lock18;
/***岛下取一盒后排弹药箱标志位***/
extern int un_O_B_lock1;
extern int un_O_B_lock2;
extern int un_O_B_lock3;
extern int un_O_B_lock4;
extern int un_O_B_lock5;
extern int un_O_B_lock6;
extern int un_O_B_lock7;
extern int un_O_B_lock8;
extern int un_O_B_lock9;
extern int un_O_B_lock10;
/***岛下连续取两盒后排弹药箱标志位***/
extern int un_T_B_lock1;
extern int un_T_B_lock2;
extern int un_T_B_lock3;
extern int un_T_B_lock4;
extern int un_T_B_lock5;
extern int un_T_B_lock6;
extern int un_T_B_lock7;
extern int un_T_B_lock8;
extern int un_T_B_lock9;
extern int un_T_B_lock10;
extern int un_T_B_lock11;
extern int un_T_B_lock12;
extern int un_T_B_lock13;
extern int un_T_B_lock14;
extern int un_T_B_lock15;
extern int un_T_B_lock20;//（追加序号）
extern int un_T_B_lock16;
extern int un_T_B_lock17;
extern int un_T_B_lock18;
extern int un_T_B_lock19;
/*****岛上取一盒弹药箱标志位*****/	
extern int on_O_lock1;
extern int on_O_lock2;
extern int on_O_lock3;
extern int on_O_lock4;
extern int on_O_lock5;
extern int on_O_lock6;
extern int on_O_lock7;
extern int on_O_lock8;
extern int on_O_lock9;
extern int on_O_lock10;
/***岛上连续取两盒弹药箱标志位***/
extern int on_T_lock1;
extern int on_T_lock2;
extern int on_T_lock3;
extern int on_T_lock4;
extern int on_T_lock5;
extern int on_T_lock6;
extern int on_T_lock7;
extern int on_T_lock8;
extern int on_T_lock9;
extern int on_T_lock10;
extern int on_T_lock11;
extern int on_T_lock12;
extern int on_T_lock13;
extern int on_T_lock14;
extern int on_T_lock15;
extern int on_T_lock16;
extern int on_T_lock17;
extern int on_T_lock18;
extern int on_T_lock19;
extern int on_T_lock20;


extern int quit_time_count;

extern int R_quit_flag;

int quit_lock=1;

int fold_lock=1;
int close_lock=1;
int withdraw_lock=1;
int loosen_lock=1;
int contraction_lock=1;

void Action_Resetting(void)
{
	
/******启动准备弹药箱标志位******/	
	start_F_lock1=1;
    start_F_lock2=1;

    start_B_lock1=1;
    start_B_lock2=1;
    start_B_lock3=1;
/*****岛上准备取弹药箱标志位*****/

    start_ON_lock1=1;
    start_ON_lock2=1;
    start_ON_lock3=1;
	
/***岛下取一盒前排弹药箱标志位***/
	un_O_F_lock1=1;
	un_O_F_lock2=1;
	un_O_F_lock3=1;
	un_O_F_lock4=1;
	un_O_F_lock5=1;
	un_O_F_lock6=1;
	un_O_F_lock7=1;
	un_O_F_lock8=1;
	un_O_F_lock9=1;
/**岛下连续取两盒前排弹药箱标志位**/
	un_T_F_lock1=1;
	un_T_F_lock2=1;
	un_T_F_lock3=1;
	un_T_F_lock4=1;
	un_T_F_lock5=1;
	un_T_F_lock6=1;
	un_T_F_lock7=1;
	un_T_F_lock8=1;
	un_T_F_lock9=1;
	un_T_F_lock10=1;
	un_T_F_lock11=1;
	un_T_F_lock12=1;
	un_T_F_lock13=1;
	un_T_F_lock14=1;
	un_T_F_lock19=1;//（追加序号）
	un_T_F_lock15=1;
	un_T_F_lock16=1;
	un_T_F_lock17=1;
	un_T_F_lock18=1;
/***岛下取一盒后排弹药箱标志位***/
	un_O_B_lock1=1;
	un_O_B_lock2=1;
	un_O_B_lock3=1;
	un_O_B_lock4=1;
	un_O_B_lock5=1;
	un_O_B_lock6=1;
	un_O_B_lock7=1;
	un_O_B_lock8=1;
	un_O_B_lock9=1;
	un_O_B_lock10=1;
/***岛下连续取两盒后排弹药箱标志位***/
	un_T_B_lock1=1;
	un_T_B_lock2=1;
	un_T_B_lock3=1;
	un_T_B_lock4=1;
	un_T_B_lock5=1;
	un_T_B_lock6=1;
	un_T_B_lock7=1;
	un_T_B_lock8=1;
	un_T_B_lock9=1;
	un_T_B_lock10=1;
	un_T_B_lock11=1;
	un_T_B_lock12=1;
	un_T_B_lock13=1;
	un_T_B_lock14=1;
	un_T_B_lock15=1;
	un_T_B_lock20=1;//（追加序号）
	un_T_B_lock16=1;
	un_T_B_lock17=1;
	un_T_B_lock18=1;
	un_T_B_lock19=1;
/*****岛上取一盒弹药箱标志位*****/	

	on_O_lock1=1;
	on_O_lock2=1;
	on_O_lock3=1;
    on_O_lock4=1;
	on_O_lock5=1;
	on_O_lock6=1;
	on_O_lock7=1;
    on_O_lock8=1;
	on_O_lock9=1;
	on_O_lock10=1;

/***岛上连续取两盒弹药箱标志位***/

	on_T_lock1=1;
	on_T_lock2=1;
	on_T_lock3=1;
	on_T_lock4=1;
	on_T_lock5=1;
	on_T_lock6=1;
	on_T_lock7=1;
	on_T_lock8=1;
	on_T_lock9=1;
	on_T_lock10=1;
	on_T_lock11=1;
	on_T_lock12=1;
	on_T_lock13=1;
	on_T_lock14=1;
	on_T_lock15=1;
	on_T_lock16=1;
	on_T_lock17=1;
	on_T_lock18=1;
	on_T_lock19=1;
	on_T_lock20=1;	
	

/********判断拖车装置是否复位********/
           if(fold_lock==1){
                Fold();
			  fold_lock=0;
			 }
/********判断补弹顺序依次复位********/
			
/**********判断舱门是否复位**********/
		  if(close_lock==1){
                Close();
			  close_lock=0;
			 }
/**********判断弹舱是否复位**********/
		  if(withdraw_lock==1){
               Withdraw();
			  withdraw_lock=0; 
			 }

/********判断取弹顺序依次复位********/	
/********首先判断爪子是否复位********/
		  if(loosen_lock==1){
                Loosen();
			  loosen_lock=0;
			 }
/********首先判断悬臂是否复位********/
		  if(contraction_lock==1){
              Contraction();
			 contraction_lock=0;
			 }
/********判断弹射装置是否复位********/        
       if(T_ROTATE_POSITION==Rotate_Value1){
	     T_ROTATE_POSITION=Rotate_Value2;
	   }
	   if(T_ROTATE_POSITION==Rotate_Value2){
	     T_ROTATE_POSITION=Rotate_Value3;
	   }
	   if(T_ROTATE_POSITION==Rotate_Value3){
	     T_ROTATE_POSITION=Rotate_Value4;
	   }
	   if(T_ROTATE_POSITION==Rotate_Value4){
	     T_ROTATE_POSITION=Rotate_Value5;
	   }
	   if(T_ROTATE_POSITION==Rotate_Value5){
	     T_ROTATE_POSITION=Rotate_Value5;
	   }
				
///********判断横移装置是否复位********/ 
//	    Toward_Right();
	   
/********判断抓取装置是否复位********/
	  if(T_GRAB_POSITION!=Grab_Value3){ 
       if(quit_lock==1){
         if(quit_time_count>50){
	    T_GRAB_POSITION=Grab_Value3;//grab_baseline;
			 
			 quit_time_count=0;
			 quit_lock=0;
		 }
	 }
   }
/************升降装置复位************/ 
      if(T_LIFT_POSITION_R!=Lift_R_Value3){
		 if(quit_time_count>50){
		T_LIFT_POSITION_R=Lift_R_Value3;
/********判断横移装置是否复位********/ 
	          Toward_Right();	
			 
			 quit_time_count=0;
			   quit_lock=1;
			  R_quit_flag=1;
			 
/************标志位终止区************/ 			 
			 
			fold_lock=1;
			close_lock=1;
			withdraw_lock=1;
			loosen_lock=1;
			contraction_lock=1;
			 
		 }
	 }
	 else{
/********判断横移装置是否复位********/ 
	          Toward_Right();	
			 
			 quit_time_count=0;
			   quit_lock=1;
			  R_quit_flag=1;
			 
/************标志位终止区************/ 			 
			 
			fold_lock=1;
			close_lock=1;
			withdraw_lock=1;
			loosen_lock=1;
			contraction_lock=1;
	 }
   
}	
