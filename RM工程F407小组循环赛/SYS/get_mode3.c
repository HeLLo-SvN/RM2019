#include "main.h"

extern int32_t T_LIFT_POSITION_R;
extern int32_t T_GRAB_POSITION;
extern int32_t T_ROTATE_POSITION;

int auto_buffer3=1;//�Զ�������߻���
extern int auto_flag;//�Զ�ȡ����־λ

int on_s_time_count;//����ʿ�ж�֮ǰ��ʱ����������
int on_time_count;//����ʿ�ж�֮��ʱ����������
int on_N_time_count;//�ڶ��λ���ʿ�ж�֮��ʱ����������

/*****��һ�λ���ʿʶ�����־λ*****/

int on_Grab_Condition;

int on_First=0;
int on_Double=0;
int on_Triple=0;

int on_times=0;
int on_times_lock=1;
int on_times_lock1=1;
int on_times_lock2=1;
int on_times_lock3=1;
int on_last_value=0;
int on_last_value1=0;

int on_Start=1;

/*****�ڶ��λ���ʿʶ�����־λ*****/

int on_N_Grab_Condition;

int on_N_First=0;
int on_N_Double=0;
int on_N_Triple=0;

int on_N_times=0;
int on_N_times_lock=1;
int on_N_times_lock1=1;
int on_N_times_lock2=1;
int on_N_times_lock3=1;
int on_N_last_value=0;
int on_N_last_value1=0;

int on_N_Start=1;

/*****����׼��ȡ��ҩ���־λ*****/

	   int start_ON_lock1=1;
	   int start_ON_lock2=1;
	   int start_ON_lock3=1;

/***��������ȡ���е�ҩ���־λ***/

	   int on_T_lock1=1;
	   int on_T_lock2=1;
	   int on_T_lock3=1;
	   int on_T_lock4=1;
	   int on_T_lock5=1;
	   int on_T_lock6=1;
	   int on_T_lock7=1;
	   int on_T_lock8=1;
	   int on_T_lock9=1;
	   int on_T_lock10=1;
	   int on_T_lock11=1;
	   int on_T_lock12=1;
	   int on_T_lock13=1;
	   int on_T_lock14=1;
	   int on_T_lock15=1;
	   int on_T_lock16=1;
	   int on_T_lock17=1;
	   int on_T_lock18=1;
	   int on_T_lock19=1;
	   int on_T_lock20=1;

/*****����ȡһ�е�ҩ���־λ*****/	

	   int on_O_lock1=1;
	   int on_O_lock2=1;
	   int on_O_lock3=1;
       int on_O_lock4=1;
	   int on_O_lock5=1;
	   int on_O_lock6=1;
	   int on_O_lock7=1;
       int on_O_lock8=1;
	   int on_O_lock9=1;
	   int on_O_lock10=1;

/*********�����־λ*********/

/****��������ȡ���е�ҩ��****/

	   int on_buffer_lock20=1;
	   int on_buffer_lock21=1;
	   int on_buffer_lock22=1;
	   int on_buffer_lock23=1;
	   int on_buffer_lock24=1;

	   int on_buffer_lock25=1;
	   int on_buffer_lock26=1;
	   int on_buffer_lock27=1;
	   int on_buffer_lock28=1;
	   int on_buffer_lock29=1;
		
/******���ϵ�ҩ���־λ******/	

	   int on_buffer_lock15=1;
	   int on_buffer_lock16=1;
	   int on_buffer_lock17=1;
	   int on_buffer_lock18=1;
	   int on_buffer_lock19=1;
	   
/*********������־λ*********/
       int on_deadlock1=1;
	   int on_deadlock2=1;
	   int on_deadlock3=1;
	   int on_deadlock4=1;
	   int on_deadlock5=1;

/*********KILL��־λ*********/
       int on_KILL=1;
/********��Ϣ��������********/
	   int on_token1=0;
/****************************/

/*****��һ��ʶ�������Ա�־λ*****/
       int on_continuity1=1;
	   int on_continuity2=1;
	   int on_continuity3=1;
       int on_continuity4=1;
	   int on_continuity5=1;
	   int on_continuity6=1;
       int on_continuity7=1;
	   int on_continuity8=1;
	   int on_continuity9=1;		
       int on_continuity10=1;
	   int on_continuity11=1;
	   int on_continuity12=1;
	   int on_continuity13=1;
	   int on_continuity14=1;
	   int on_continuity15=1;
		
/*****�ڶ���ʶ�������Ա�־λ*****/		
       int on_continuity16=1;
	   int on_continuity17=1;
	   int on_continuity18=1;
   	   int on_continuity19=1;		
       int on_continuity20=1;
	   int on_continuity21=1;
	   int on_continuity22=1;
   	   int on_continuity23=1;

void Mode_On_Isle(void)
{
	if(on_deadlock1==1){
/*********����ʿ�ж�֮ǰ�ļ�ʱ*********/
          on_s_time_count++;
/**************************************/
		
/*************ON_ISLE_Start************/
	 if(on_KILL==1){
	start_ON_lock1=0;//��������̧��
	start_ON_lock2=0;//�������
	start_ON_lock3=0;//צ������
		 
		 on_KILL=0;
	 }
	
/************ON_ISLE_Start*************/
		
    if(start_ON_lock1==0){
	   T_LIFT_POSITION_R = Lift_R_Value1;//��������̧��
//	    Toward_Left();//׷��
	   start_ON_lock1=1;
    }
	

	if(start_ON_lock2==0){
	   if(on_s_time_count>80){
		   Extension();//�������
		   start_ON_lock2=1;
		   on_s_time_count=0;
		   on_token1=1; 
	    }
    }
  if(on_token1==1){	
	if(start_ON_lock3==0){
		if(on_s_time_count>50){

		 if(auto_buffer3==1){	
	       T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//צ������
			  auto_buffer3=0;
		 }
	    if(on_s_time_count>150){
			
			auto_flag=0;
			auto_buffer3=1;
			
		   on_token1=0;	
	       start_ON_lock3=1;
	       on_s_time_count=0;
			
		   on_deadlock1=0;
		   on_deadlock2=0;
		   on_Start=0;		  	
			
		 }
		}
	   }
      } 
     			
   }//on_deadlock1

/**************����ʿʶ��*************/ 	
  if(on_deadlock2==0){
	if(on_Start==0){
/**ͨ��Keyence����Ƿ���ȡ������**/	
	on_Grab_Condition=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);//Left_Limit();
/***********ֻ�ж�����***********/ 
   if(on_times==3){
		  on_times_lock=0;
	   }
	 if(on_times_lock==1){
		 
	   if(on_times_lock1==1){
        if(on_Grab_Condition==1){
 	         on_First=1;
		     on_times+=1;
		   on_times_lock1=0;
			on_last_value=1;			
          }
	     }
	   
	    if(on_times_lock2==1){
		 if(on_last_value==1){	
	     if(on_Grab_Condition==0){
		     on_Double=1;
		     on_times+=1;
			on_times_lock2=0;
			 on_last_value=0;
			 on_last_value1=1;
	       }
	      }
	     }
		
		if(on_times_lock3==1){
		 if(on_last_value1==1){
		  if(on_Grab_Condition==1){
			 on_Triple=1;
			 on_times+=1;
			on_times_lock3=0;
			 on_last_value1=0;
		    }
		   }
	      }
		
		}
	    
		 if(on_First*on_Double*on_Triple==1){

/**********���ƶ���־λ������Ч**********/
				auto_flag=1;//�Զ�ȡ����־λ
			 
/*************������Ӧ��־λ*************/	
			
/****************ON_Twobox***************/

			on_T_lock1=0;//צ�ӷ�תȡ��
			on_T_lock2=0;//��ס��ҩ��
			on_T_lock3=0;//����һ���߶�
			on_T_lock4=0;//����ҩ���뵯ҩ��
			on_T_lock5=0;//�����ƶ�����ȡ�ڶ�����ҩ��
			on_T_lock6=0;//�½�һ���߶�
			on_T_lock7=0;//צ���ɿ�
			on_T_lock8=0;//צ���ٴη�תȡ��
			on_T_lock9=0;//�ӳ���ҩ��
			on_T_lock10=0;//��ס��ҩ��
			on_T_lock11=0;//��λ
			on_T_lock12=0;//����һ���߶�
			on_T_lock13=0;//����ҩ���뵯ҩ��
			on_T_lock14=0;//�ڶ���ȡ�������Ҳ൯��
			on_T_lock15=0;//�ջ�����
			on_T_lock20=0;//צ���ɿ���׷����ţ�
			on_T_lock16=0;//צ������
			on_T_lock17=0;//�ӳ���ҩ��
			on_T_lock18=0;//�½�һ���߶�
			on_T_lock19=0;//��λ

/**********������־λ������Ч**********/		 
			    on_deadlock2=1;
			    on_deadlock3=0;
			 
                  on_First=0;
				  on_Double=0;
				  on_Triple=0;
				 				 		 		 
				  on_Start=1;
           }
		 
   }
  }//on_deadlock2	
  
  if(on_deadlock3==0){  
/*********����ʿ�ж�֮��ļ�ʱ*********/
          on_time_count++;
/**************************************/
	  
/**************************************/
    if(on_T_lock1==0){
       if(on_time_count>10){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//צ�ӷ�תȡ��
		   
		   on_continuity1=0;
		   
	       on_T_lock1=1;
	       on_time_count=0;
	   }
    }
	
    if(on_T_lock2==0){
	   if(on_continuity1==0){	
        if(on_time_count>30){
	       Clamp(); //��ס��ҩ��
			
		   on_continuity1=1;
		   on_continuity3=0;
			
	       on_T_lock2=1;
		   on_time_count=0;
	   }
      }
    }
	
	if(on_T_lock4==0){
	  if(on_continuity3==0){	
	   if(on_time_count>15){
	       T_GRAB_POSITION= Grab_Value3;// grab_baseline;//����ҩ���뵯ҩ��
		   
		   on_continuity3=1;
		   on_continuity4=0;
		   
	       on_T_lock4=1;
		   on_time_count=0;
	   }
      }
    }
	
    if(on_T_lock5==0){
	  if(on_continuity4==0){	
       if(on_time_count>100){
           T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//צ������
		   
		   on_continuity4=1;
		   on_continuity5=0;
		   
	       on_T_lock5=1;
	 	   on_time_count=0;
	   }
    }
   }
	 
	if(on_T_lock6==0){
	  if(on_continuity5==0){	
	   if(on_time_count>23){
		  Loosen();//צ���ɿ�
		   
		   on_continuity5=1;
		   on_continuity14=0;
		   
		   on_T_lock6=1;
		   on_time_count=0;
	   }
      }
    }	
	  	
	if(on_T_lock17==0){
	  if(on_continuity14==0){	
	    if(on_time_count>50){
			
            auto_flag=0;//�Զ�ȡ����־λ��Ч 
			
			on_continuity14=1;
			
	        on_T_lock17=1;
			on_time_count=0;
			
		    on_deadlock3=1;
		    on_deadlock4=0;
		    on_N_Start=0;
		}
	   }
	}
	  
 }//on_deadlock3 
/************����ʿ�ٴ�ʶ��***********/
 if(on_deadlock4==0){	
	if(on_N_Start==0){
/**ͨ��Keyence����Ƿ���ȡ������**/	
	on_N_Grab_Condition=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);//Left_Limit();
/***********ֻ�ж�����***********/ 
   if(on_N_times==3){
		  on_N_times_lock=0;
	   }
	 if(on_N_times_lock==1){
		 
	   if(on_N_times_lock1==1){
        if(on_N_Grab_Condition==1){
 	         on_N_First=1;
		     on_N_times+=1;
		   on_N_times_lock1=0;
			on_N_last_value=1;			
          }
	     }
	   
	    if(on_N_times_lock2==1){
		 if(on_N_last_value==1){	
	     if(on_N_Grab_Condition==0){
		     on_N_Double=1;
		     on_N_times+=1;
			on_N_times_lock2=0;
			 on_N_last_value=0;
			 on_N_last_value1=1;
	       }
	      }
	     }
		
		if(on_N_times_lock3==1){
		 if(on_N_last_value1==1){
		  if(on_N_Grab_Condition==1){
			 on_N_Triple=1;
			 on_N_times+=1;
			on_N_times_lock3=0;
			 on_N_last_value1=0;
		    }
		   }
	      }
		
		}
	    
		 if(on_N_First*on_N_Double*on_N_Triple==1){

/**********���ƶ���־λ������Ч**********/
				auto_flag=1;//�Զ�ȡ����־λ
			 
/*************������Ӧ��־λ*************/	
			
/***************ON_Onebox***************/

			on_O_lock1=0;//צ�ӷ�תȡ��
			on_O_lock2=0;//��ס��ҩ��
			on_O_lock3=0;//����һ���߶�
			on_O_lock4=0;//����ҩ���뵯ҩ��
			on_O_lock5=0;//�ջ�����
			on_O_lock6=0;//צ���ɿ�
			on_O_lock7=0;//צ������
			on_O_lock8=0;//�ӳ���ҩ��
			on_O_lock9=0;//�½�һ���߶�
			on_O_lock10=0;//��λ
			 
/**********������־λ������Ч**********/		 
			     on_deadlock4=1;  
			     on_deadlock5=0;
			 
                  on_N_First=0;
				  on_N_Double=0;
				  on_N_Triple=0;
				 				 		 		 
				  on_N_Start=1;
           }
		 
   }  	
  }//on_deadlock4   
 
 if(on_deadlock5==0){	
/******�ڶ��λ���ʿ�ж�֮��ļ�ʱ******/
          on_N_time_count++;
/**************************************/   
    if(on_O_lock1==0){
       if(on_N_time_count>10){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//צ�ӷ�תȡ��
		   
		   on_continuity16=0;
		   
	       on_O_lock1=1;
	       on_N_time_count=0;
	   }
    }
	
    if(on_O_lock2==0){
	   if(on_continuity16==0){	
        if(on_N_time_count>25){
	       Clamp(); //��ס��ҩ��
			
		   on_continuity16=1;
		   on_continuity18=0;
			
	       on_O_lock2=1;
		   on_N_time_count=0;
	   }
      }
    }
	
	if(on_O_lock4==0){
	  if(on_continuity18==0){	
	   if(on_N_time_count>15){
	       T_GRAB_POSITION= Grab_Value3;//grab_baseline;//����ҩ���뵯ҩ��
		   
		   on_continuity18=1;
		   on_continuity19=0;
		   
	       on_O_lock4=1;
		   on_N_time_count=0;
	   }
      }
    }
	
	if(on_O_lock5==0){
	  if(on_continuity19==0){
	   if(on_N_time_count>100){
		   T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//צ������
		   
		   on_continuity19=1;
		   on_continuity20=0;
		   
		   on_O_lock5=1;
		   on_N_time_count=0;
	   }
      }
    }		
	
	if(on_O_lock6==0){
	  if(on_continuity20==0){	
 	   if(on_N_time_count>23){
	       Loosen();//צ���ɿ�
		   
		   on_continuity20=1;
		   on_continuity21=0;
		   
 		   on_O_lock6=1;
		   on_N_time_count=0;
	   }
      }
	}
	
	if(on_O_lock7==0){
	  if(on_continuity21==0){	
	   if(on_N_time_count>15){
	       Contraction();//�ջ�����
		   
		   on_continuity21=1;
		   
	       on_O_lock7=1;
	       on_N_time_count=0;
		   
		   on_deadlock5=1;
		}
	  }
	}
	
  }	//on_deadlock5
 
  
  
}
