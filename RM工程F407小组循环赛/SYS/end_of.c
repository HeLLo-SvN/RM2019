#include "main.h"

//extern int grab_baseline;

extern int32_t T_LIFT_POSITION_R;

extern int32_t T_GRAB_POSITION;

extern int32_t T_ROTATE_POSITION;

/******����׼����ҩ���־λ******/
extern int start_F_lock1;
extern int start_F_lock2;

extern int start_B_lock1;
extern int start_B_lock2;
extern int start_B_lock3;

/*****����׼��ȡ��ҩ���־λ*****/

extern int start_ON_lock1;
extern int start_ON_lock2;
extern int start_ON_lock3;

/***����ȡһ��ǰ�ŵ�ҩ���־λ***/
extern int un_O_F_lock1;
extern int un_O_F_lock2;
extern int un_O_F_lock3;
extern int un_O_F_lock4;
extern int un_O_F_lock5;
extern int un_O_F_lock6;
extern int un_O_F_lock7;
extern int un_O_F_lock8;
extern int un_O_F_lock9;
/***��������ȡ����ǰ�ŵ�ҩ���־λ***/
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
extern int un_T_F_lock19;//��׷����ţ�
extern int un_T_F_lock15;
extern int un_T_F_lock16;
extern int un_T_F_lock17;
extern int un_T_F_lock18;
/***����ȡһ�к��ŵ�ҩ���־λ***/
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
/***��������ȡ���к��ŵ�ҩ���־λ***/
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
extern int un_T_B_lock20;//��׷����ţ�
extern int un_T_B_lock16;
extern int un_T_B_lock17;
extern int un_T_B_lock18;
extern int un_T_B_lock19;
/*****����ȡһ�е�ҩ���־λ*****/	
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
/***��������ȡ���е�ҩ���־λ***/
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
	
/******����׼����ҩ���־λ******/	
	start_F_lock1=1;
    start_F_lock2=1;

    start_B_lock1=1;
    start_B_lock2=1;
    start_B_lock3=1;
/*****����׼��ȡ��ҩ���־λ*****/

    start_ON_lock1=1;
    start_ON_lock2=1;
    start_ON_lock3=1;
	
/***����ȡһ��ǰ�ŵ�ҩ���־λ***/
	un_O_F_lock1=1;
	un_O_F_lock2=1;
	un_O_F_lock3=1;
	un_O_F_lock4=1;
	un_O_F_lock5=1;
	un_O_F_lock6=1;
	un_O_F_lock7=1;
	un_O_F_lock8=1;
	un_O_F_lock9=1;
/**��������ȡ����ǰ�ŵ�ҩ���־λ**/
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
	un_T_F_lock19=1;//��׷����ţ�
	un_T_F_lock15=1;
	un_T_F_lock16=1;
	un_T_F_lock17=1;
	un_T_F_lock18=1;
/***����ȡһ�к��ŵ�ҩ���־λ***/
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
/***��������ȡ���к��ŵ�ҩ���־λ***/
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
	un_T_B_lock20=1;//��׷����ţ�
	un_T_B_lock16=1;
	un_T_B_lock17=1;
	un_T_B_lock18=1;
	un_T_B_lock19=1;
/*****����ȡһ�е�ҩ���־λ*****/	

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

/***��������ȡ���е�ҩ���־λ***/

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
	

/********�ж��ϳ�װ���Ƿ�λ********/
           if(fold_lock==1){
                Fold();
			  fold_lock=0;
			 }
/********�жϲ���˳�����θ�λ********/
			
/**********�жϲ����Ƿ�λ**********/
		  if(close_lock==1){
                Close();
			  close_lock=0;
			 }
/**********�жϵ����Ƿ�λ**********/
		  if(withdraw_lock==1){
               Withdraw();
			  withdraw_lock=0; 
			 }

/********�ж�ȡ��˳�����θ�λ********/	
/********�����ж�צ���Ƿ�λ********/
		  if(loosen_lock==1){
                Loosen();
			  loosen_lock=0;
			 }
/********�����ж������Ƿ�λ********/
		  if(contraction_lock==1){
              Contraction();
			 contraction_lock=0;
			 }
/********�жϵ���װ���Ƿ�λ********/        
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
				
///********�жϺ���װ���Ƿ�λ********/ 
//	    Toward_Right();
	   
/********�ж�ץȡװ���Ƿ�λ********/
	  if(T_GRAB_POSITION!=Grab_Value3){ 
       if(quit_lock==1){
         if(quit_time_count>50){
	    T_GRAB_POSITION=Grab_Value3;//grab_baseline;
			 
			 quit_time_count=0;
			 quit_lock=0;
		 }
	 }
   }
/************����װ�ø�λ************/ 
      if(T_LIFT_POSITION_R!=Lift_R_Value3){
		 if(quit_time_count>50){
		T_LIFT_POSITION_R=Lift_R_Value3;
/********�жϺ���װ���Ƿ�λ********/ 
	          Toward_Right();	
			 
			 quit_time_count=0;
			   quit_lock=1;
			  R_quit_flag=1;
			 
/************��־λ��ֹ��************/ 			 
			 
			fold_lock=1;
			close_lock=1;
			withdraw_lock=1;
			loosen_lock=1;
			contraction_lock=1;
			 
		 }
	 }
	 else{
/********�жϺ���װ���Ƿ�λ********/ 
	          Toward_Right();	
			 
			 quit_time_count=0;
			   quit_lock=1;
			  R_quit_flag=1;
			 
/************��־λ��ֹ��************/ 			 
			 
			fold_lock=1;
			close_lock=1;
			withdraw_lock=1;
			loosen_lock=1;
			contraction_lock=1;
	 }
   
}	
