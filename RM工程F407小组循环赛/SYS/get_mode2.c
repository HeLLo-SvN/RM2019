#include "main.h"

extern int32_t T_LIFT_POSITION_R;
extern int32_t T_GRAB_POSITION;
extern int32_t T_ROTATE_POSITION;

int auto_buffer2=1;//�Զ�������߻���
extern int auto_flag;//�Զ�ȡ����־λ

extern int s_time_count;//����ʿ�ж�֮ǰ��ʱ����������
extern int un_time_count;//����ʿ�ж�֮��ʱ����������
extern int N_time_count;//�ڶ��λ���ʿ�ж�֮��ʱ����������

/*****��һ�λ���ʿʶ�����־λ*****/

extern int Grab_Condition;

extern int First;
extern int Double;
extern int Triple;

extern int times;
extern int times_lock;
extern int times_lock1;
extern int times_lock2;
extern int times_lock3;
extern int last_value;
extern int last_value1;

extern int Start;

/*****�ڶ��λ���ʿʶ�����־λ*****/
extern int N_Grab_Condition;

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

/*****����׼��ȡ���ŵ�ҩ���־λ*****/

		int start_B_lock1=1;
		int start_B_lock2=1;
		int start_B_lock3=1;

/***��������ȡ���к��ŵ�ҩ���־λ***/

		int un_T_B_lock1=1;
		int un_T_B_lock2=1;
		int un_T_B_lock3=1;
		int un_T_B_lock4=1;
		int un_T_B_lock5=1;
		int un_T_B_lock6=1;
		int un_T_B_lock7=1;
		int un_T_B_lock8=1;
		int un_T_B_lock9=1;
		int un_T_B_lock10=1;
		int un_T_B_lock11=1;
		int un_T_B_lock12=1;
		int un_T_B_lock13=1;
		int un_T_B_lock14=1;
		int un_T_B_lock15=1;
		int un_T_B_lock16=1;
		int un_T_B_lock17=1;
		int un_T_B_lock18=1;
		int un_T_B_lock19=1;
		int un_T_B_lock20=1;
		
/*****����ȡһ�к��ŵ�ҩ���־λ*****/	

		int un_O_B_lock1=1;
		int un_O_B_lock2=1;
		int un_O_B_lock3=1;
		int un_O_B_lock4=1;
		int un_O_B_lock5=1;
		int un_O_B_lock6=1;
		int un_O_B_lock7=1;
		int un_O_B_lock8=1;
		int un_O_B_lock9=1;
		int un_O_B_lock10=1;
		
/***********�����־λ***********/

/****��������ȡ���к��ŵ�ҩ��****/

		int buffer_lock20=1;
		int buffer_lock21=1;
		int buffer_lock22=1;
		int buffer_lock23=1;
		int buffer_lock24=1;

		int buffer_lock25=1;
		int buffer_lock26=1;
		int buffer_lock27=1;
		int buffer_lock28=1;
		int buffer_lock29=1;
		
/******���º��ŵ�ҩ���־λ******/	

		int buffer_lock15=1;
		int buffer_lock16=1;
		int buffer_lock17=1;
		int buffer_lock18=1;
		int buffer_lock19=1;

/***********������־λ***********/
        extern int deadlock1;
		extern int deadlock2;
		extern int deadlock3;
		extern int deadlock4;
		extern int deadlock5;

/***********KILL��־λ***********/
        int KILL=1;
 
/**********��Ϣ��������**********/
		int token1=0;
/********************************/

/*****��һ��ʶ�������Ա�־λ*****/
        int B_continuity1=1;
		int B_continuity2=1;
		int B_continuity3=1;
        int B_continuity4=1;
		int B_continuity5=1;
		int B_continuity6=1;
        int B_continuity7=1;
		int B_continuity8=1;
		int B_continuity9=1;		
        int B_continuity10=1;
		int B_continuity11=1;
		int B_continuity12=1;
		int B_continuity13=1;
		int B_continuity14=1;
		int B_continuity15=1;
		
/*****�ڶ���ʶ�������Ա�־λ*****/		
        int B_continuity16=1;
	    int B_continuity17=1;
	    int B_continuity18=1;
		int B_continuity19=1;		
        int B_continuity20=1;
	    int B_continuity21=1;
	    int B_continuity22=1;
		int B_continuity23=1;

void Mode_Behind(void)
{
	if(deadlock1==1){
/*********����ʿ�ж�֮ǰ�ļ�ʱ*********/
          s_time_count++;
/**************************************/
		
/**************Behind_Start*************/
	 if(KILL==1){
	start_B_lock1=0;//��������̧��
	start_B_lock2=0;//�������
	start_B_lock3=0;//צ������
		 
		 KILL=0;
	 }
	
/***************Start_B****************/
		
    if(start_B_lock1==0){
	   T_LIFT_POSITION_R = Lift_R_Value1;//��������̧��
	    //Toward_Left();//׷��
	   start_B_lock1=1;
    }
	
	if(start_B_lock2==0){
	   if(s_time_count>100){
		   Extension();//�������
		   start_B_lock2=1;
		   s_time_count=0;
		   token1=1; 
	    }
    }
	
  if(token1==1){	
	if(start_B_lock3==0){
		if(s_time_count>50){

		 if(auto_buffer2==1){	
	       T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//צ������
			  auto_buffer2=0;
		 }
	    if(s_time_count>150){
			
			auto_flag=0;
			auto_buffer2=1;
			
		   token1=0;	
	       start_B_lock3=1;
	       s_time_count=0;
			
		   deadlock1=0;
		   deadlock2=0;
		   Start=0;		  	
			
		 }
		}
	   }
      } 
    			
   }//deadlock1
/**************����ʿʶ��*************/ 	
  if(deadlock2==0){
	if(Start==0){
/**ͨ��Keyence����Ƿ���ȡ������**/	
	Grab_Condition=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);//Left_Limit();
/***********ֻ�ж�����***********/ 
   if(times==3){
		  times_lock=0;
	   }
	 if(times_lock==1){
		 
	   if(times_lock1==1){
        if(Grab_Condition==1){
 	         First=1;
		     times+=1;
		   times_lock1=0;
			last_value=1;			
          }
	     }
	   
	    if(times_lock2==1){
		 if(last_value==1){	
	     if(Grab_Condition==0){
		     Double=1;
		     times+=1;
			times_lock2=0;
			 last_value=0;
			 last_value1=1;
	       }
	      }
	     }
		
		if(times_lock3==1){
		 if(last_value1==1){
		  if(Grab_Condition==1){
			 Triple=1;
			 times+=1;
			times_lock3=0;
			 last_value1=0;
		    }
		   }
	      }
		
		}
	    
		 if(First*Double*Triple==1){

/**********���ƶ���־λ������Ч**********/
				auto_flag=1;//�Զ�ȡ����־λ
			 
/*************������Ӧ��־λ*************/	
			
/********** Under_Twobox_Behind**********/

			un_T_B_lock1=0;//צ�ӷ�תȡ��
			un_T_B_lock2=0;//��ס��ҩ��
			un_T_B_lock3=0;//����һ���߶�
			un_T_B_lock4=0;//����ҩ���뵯ҩ��
			un_T_B_lock5=0;//�����ƶ�����ȡ�ڶ�����ҩ��
			un_T_B_lock6=0;//�½�һ���߶�
			un_T_B_lock7=0;//צ���ɿ�
			un_T_B_lock8=0;//צ���ٴη�תȡ��
			un_T_B_lock9=0;//�ӳ���ҩ��
			un_T_B_lock10=0;//��ס��ҩ��
			un_T_B_lock11=0;//��λ
			un_T_B_lock12=0;//����һ���߶�
			un_T_B_lock13=0;//����ҩ���뵯ҩ��
			un_T_B_lock14=0;//�ڶ���ȡ�������Ҳ൯��
			un_T_B_lock15=0;//�ջ�����
			un_T_B_lock20=0;//צ���ɿ���׷����ţ�
			un_T_B_lock16=0;//צ������
			un_T_B_lock17=0;//�ӳ���ҩ��
			un_T_B_lock18=0;//�½�һ���߶�
			un_T_B_lock19=0;//��λ

/**********������־λ������Ч**********/		 
			    deadlock2=1;
			    deadlock3=0;
			 
                  First=0;
				  Double=0;
				  Triple=0;
				 				 		 		 
				  Start=1;
           }
		 
   }
  }//deadlock2		

  if(deadlock3==0){  
/*********����ʿ�ж�֮��ļ�ʱ*********/
          un_time_count++;
/**************************************/
	  
/**************************************/
    if(un_T_B_lock1==0){
       if(un_time_count>20){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//צ�ӷ�תȡ��
		   
		   B_continuity1=0;
		   
	       un_T_B_lock1=1;
	       un_time_count=0;
	   }
    }
	
    if(un_T_B_lock2==0){
	   if(B_continuity1==0){	
        if(un_time_count>30){
	       Clamp(); //��ס��ҩ��
			
		   B_continuity1=1;
		   B_continuity2=0;
			
	       un_T_B_lock2=1;
		   un_time_count=0;
	   }
      }
    }
	
	if(un_T_B_lock3==0){
	  if(B_continuity2==0){	
	   if(un_time_count>20){
		   T_LIFT_POSITION_R = Lift_R_Value2;//����һ���߶�
		   
		   B_continuity2=1;
		   B_continuity3=0;
		   
		   un_T_B_lock3=1;
		   un_time_count=0;
	   }
      }
    }	
	
	if(un_T_B_lock4==0){
	  if(B_continuity3==0){	
	   if(un_time_count>5){
	       //T_GRAB_POSITION= Grab_Value3;// grab_baseline;//����ҩ���뵯ҩ��
		   
		   B_continuity3=1;
		   B_continuity4=0;
		   
	       un_T_B_lock4=1;
		   un_time_count=0;
	   }
      }
    }
	
    if(un_T_B_lock5==0){
	  if(B_continuity4==0){	
       if(un_time_count>5){
           T_LIFT_POSITION_R = Lift_R_Value1;//�½�һ���߶�
		   
		   B_continuity4=1;
		   B_continuity5=0;
		   
	       un_T_B_lock5=1;
	 	   un_time_count=0;
	   }
      }
    }
	 
	if(un_T_B_lock6==0){
	  if(B_continuity5==0){	
	   if(un_time_count>10){
		   //Toward_Right();
	       //Toward_Left();//�����ƶ�����ȡ�ڶ�����ҩ��
		   
		   B_continuity5=1;
		   B_continuity6=0;
		   
		   un_T_B_lock6=1;
		   un_time_count=0;
	   }
      }
    }	
	
	if(un_T_B_lock7==0){
	  if(B_continuity6==0){	
 	   if(un_time_count>80){
	       Loosen();//צ���ɿ�
		   
		   B_continuity6=1;
		   B_continuity7=0;
		   
 		   un_T_B_lock7=1;
		   un_time_count=0;
	   }
      }
	}
	 
	if(un_T_B_lock8==0){
	 if(B_continuity7==0){	
       if(un_time_count>20){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//צ���ٴη�תȡ��
		   
		   B_continuity7=1;
		   B_continuity8=0;
		   
	       un_T_B_lock8=1;
	       un_time_count=0;
	   }
      }
    }
	 
	if(un_T_B_lock9==0){
	   if(B_continuity8==0){	
	    if(un_time_count>15){
//	        T_ROTATE_POSITION = Rotate_Value1;//�ӳ���ҩ��
			
			B_continuity8=1;
		    B_continuity9=0;
			
	        un_T_B_lock9=1;
			un_time_count=0;
		}
	   }
	}
	 
	if(un_T_B_lock10==0){
	   if(B_continuity9==0){	
		if(un_time_count>5){
			
			Clamp(); //��ס��ҩ��
			
			B_continuity9=1;
			
	        un_T_B_lock10=1;
			un_time_count=0;
			
			buffer_lock20=0;
			buffer_lock21=0;
		}
	   }
	}
	
	if(un_T_B_lock11==0){
	  if(buffer_lock20==0){	
        if(un_time_count>60){
		   if(buffer_lock21==0){
//	        T_ROTATE_POSITION = Rotate_Value2;//��λ
			   buffer_lock21=1;
			   buffer_lock22=0;
		   }
		}
		if(un_time_count>70){
		   if(buffer_lock22==0){
//		    T_ROTATE_POSITION = Rotate_Value3;
			   buffer_lock22=1;
			   buffer_lock23=0;
		   }
		}
		if(un_time_count>80){
		   if(buffer_lock23==0){
//		    T_ROTATE_POSITION = Rotate_Value4;
			   buffer_lock23=1;
			   buffer_lock24=0;
		   }
		}	
        if(un_time_count>90){		
 		   if(buffer_lock24==0){
//	        T_ROTATE_POSITION = Rotate_Value5;
			   buffer_lock24=1;
			   buffer_lock20=1;
			   
			B_continuity10=0;   
			   
	        un_T_B_lock11=1;
		    un_time_count=0;
		  }	   
	   }
     }	
    }
	 
	if(un_T_B_lock12==0){
	  if(B_continuity10==0){	
	   if(un_time_count>5){
		   
		   T_LIFT_POSITION_R = Lift_R_Value2;//����һ���߶�
		   
		   B_continuity10=1;
		   B_continuity11=0;
		   
		   un_T_B_lock12=1;
		   un_time_count=0;
	   }
      }
    }
		 
	if(un_T_B_lock13==0){
	  if(B_continuity11==0){	
	    if(un_time_count>15){
	        //T_GRAB_POSITION= Grab_Value3;//grab_baseline;//����ҩ���뵯ҩ��
			
			B_continuity11=1;
		    B_continuity12=0;
			
	        un_T_B_lock13=1;
		    un_time_count=0;
	   }
      }
    }
	 	
	if(un_T_B_lock20==0){
	  if(B_continuity12==0){
 	   if(un_time_count>80){
		   
		   T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//צ������
	       		   
		   B_continuity12=1;
		   B_continuity13=0;
		   
 		   un_T_B_lock20=1;
		   un_time_count=0;
	   }
      }
	}	
	
	if(un_T_B_lock16==0){
	  if(B_continuity13==0){	
		if(un_time_count>23){
	       
		   Loosen();//צ���ɿ���׷�ӣ�
			
		   B_continuity13=1;
		   B_continuity14=0;
			
	       un_T_B_lock16=1;
	       un_time_count=0;
		}
	   }
	}
  	
	if(un_T_B_lock17==0){
	  if(B_continuity14==0){	
	    if(un_time_count>10){
	        T_LIFT_POSITION_R = Lift_R_Value1;//�½�һ���߶�
			
			B_continuity14=1;
		    B_continuity15=0;
			
	        un_T_B_lock17=1;
			un_time_count=0;
		}
	   }
	}
	
	if(un_T_B_lock18==0){
	   if(B_continuity15==0){	
		if(un_time_count>60){
			
			auto_flag=0;//�Զ�ȡ����־λ��Ч
			
			B_continuity15=1;
			
	        un_T_B_lock18=1;
			un_time_count=0;
			
			deadlock3=1;
		    deadlock4=0;
		    N_Start=0;
			
		}
	   }
	}
	  
 }//deadlock3
/************����ʿ�ٴ�ʶ��***********/
 if(deadlock4==0){	
	if(N_Start==0){
/**ͨ��Keyence����Ƿ���ȡ������**/	
	N_Grab_Condition=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);//Left_Limit();
/***********ֻ�ж�����***********/ 
   if(N_times==3){
		  N_times_lock=0;
	   }
	 if(N_times_lock==1){
		 
	   if(N_times_lock1==1){
        if(N_Grab_Condition==1){
 	         N_First=1;
		     N_times+=1;
		   N_times_lock1=0;
			N_last_value=1;			
          }
	     }
	   
	    if(N_times_lock2==1){
		 if(N_last_value==1){	
	     if(N_Grab_Condition==0){
		     N_Double=1;
		     N_times+=1;
			N_times_lock2=0;
			 N_last_value=0;
			 N_last_value1=1;
	       }
	      }
	     }
		
		if(N_times_lock3==1){
		 if(N_last_value1==1){
		  if(N_Grab_Condition==1){
			 N_Triple=1;
			 N_times+=1;
			N_times_lock3=0;
			 N_last_value1=0;
		    }
		   }
	      }
		
		}
	    
		 if(N_First*N_Double*N_Triple==1){

/**********���ƶ���־λ������Ч**********/
				auto_flag=1;//�Զ�ȡ����־λ
			 
/*************������Ӧ��־λ*************/	
			
/**********Under_Onebox_Behind**********/

			un_O_B_lock1=0;//צ�ӷ�תȡ��
			un_O_B_lock2=0;//��ס��ҩ��
			un_O_B_lock3=0;//����һ���߶�
			un_O_B_lock4=0;//����ҩ���뵯ҩ��
			un_O_B_lock5=0;//�ջ�����
			un_O_B_lock6=0;//צ���ɿ�
			un_O_B_lock7=0;//צ������
			un_O_B_lock8=0;//�ӳ���ҩ��
			un_O_B_lock9=0;//�½�һ���߶�
			un_O_B_lock10=0;//��λ
			 
/**********������־λ������Ч**********/		 
			     deadlock4=1;  
			     deadlock5=0;
			 
                  N_First=0;
				  N_Double=0;
				  N_Triple=0;
				 				 		 		 
				  N_Start=1;
           }
		 
   }  	
  }//deadlock4	  
if(deadlock5==0){	
/******�ڶ��λ���ʿ�ж�֮��ļ�ʱ******/
          N_time_count++;
/**************************************/   
    if(un_O_B_lock1==0){
       if(N_time_count>20){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//צ�ӷ�תȡ��
		   
		   B_continuity16=0;
		   
	       un_O_B_lock1=1;
	       N_time_count=0;
	   }
    }
	
    if(un_O_B_lock2==0){
	   if(B_continuity16==0){	
        if(N_time_count>30){
	       Clamp(); //��ס��ҩ��
			
		   B_continuity16=1;
		   B_continuity17=0;
			
	       un_O_B_lock2=1;
		   N_time_count=0;
	   }
      }
    }
	
	if(un_O_B_lock3==0){
	  if(B_continuity17==0){	
	   if(N_time_count>20){
		   T_LIFT_POSITION_R = Lift_R_Value2;//����һ���߶�
		   
		   B_continuity17=1;
		   B_continuity18=0;
		   
		   un_O_B_lock3=1;
		   N_time_count=0;
	   }
      }
    }	
	
	if(un_O_B_lock4==0){
	  if(B_continuity18==0){	
	   if(N_time_count>5){
	       //T_GRAB_POSITION= Grab_Value3;//grab_baseline;//����ҩ���뵯ҩ��
		   
		   B_continuity18=1;
		   B_continuity19=0;
		   
	       un_O_B_lock4=1;
		   N_time_count=0;
	   }
      }
    }
	
	if(un_O_B_lock5==0){
	  if(B_continuity19==0){
	   if(N_time_count>5){
		   Contraction();//�ջ�����
		   
		   B_continuity19=1;
		   B_continuity20=0;
		   
		   un_O_B_lock5=1;
		   N_time_count=0;
	   }
      }
    }		
	
	if(un_O_B_lock6==0){
	  if(B_continuity20==0){	
 	   if(N_time_count>80){
	       		   
		   T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//צ������
		   
		   B_continuity20=1;
		   B_continuity21=0;
		   
 		   un_O_B_lock6=1;
		   N_time_count=0;
	   }
      }
	}
	
	if(un_O_B_lock7==0){
	  if(B_continuity21==0){	
	   if(N_time_count>23){
	       
		   Loosen();//צ���ɿ�
		   
		   B_continuity21=1;
		   B_continuity22=0;
		   
	       un_O_B_lock7=1;
	       N_time_count=0;
		}
	  }
	}
	
	if(un_O_B_lock8==0){
	   if(B_continuity22==0){
	    if(N_time_count>5){
	        T_LIFT_POSITION_R = Lift_R_Value1;//�½�һ���߶�
			
			B_continuity22=1;
	
	        un_O_B_lock8=1;
			N_time_count=0;
			
			deadlock5=1;
			
		}
	   }
	}
	
  }	//deadlock5
 
}
