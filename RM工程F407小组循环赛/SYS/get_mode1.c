#include "main.h"

extern int32_t T_LIFT_POSITION_R;
extern int32_t T_GRAB_POSITION;
extern int32_t T_ROTATE_POSITION;

int auto_buffer1=1;//�Զ�������߻���
extern int auto_flag;//�Զ�ȡ����־λ

int s_time_count;//����ʿ�ж�֮ǰ��ʱ����������
int un_time_count;//����ʿ�ж�֮��ʱ����������
int N_time_count;//�ڶ��λ���ʿ�ж�֮��ʱ����������

/*****��һ�λ���ʿʶ�����־λ*****/

int Grab_Condition;

int First=0;
int Double=0;
int Triple=0;

int times=0;
int times_lock=1;
int times_lock1=1;
int times_lock2=1;
int times_lock3=1;
int last_value=0;
int last_value1=0;

int Start=1;

/*****�ڶ��λ���ʿʶ�����־λ*****/
int N_Grab_Condition;

int N_First=0;
int N_Double=0;
int N_Triple=0;

int N_times=0;
int N_times_lock=1;
int N_times_lock1=1;
int N_times_lock2=1;
int N_times_lock3=1;
int N_last_value=0;
int N_last_value1=0;

int N_Start=1;

/*****����׼��ȡǰ�ŵ�ҩ���־λ*****/

		int start_F_lock1=1;
		int start_F_lock2=1;

/***��������ȡ����ǰ�ŵ�ҩ���־λ***/

		int un_T_F_lock1=1;
		int un_T_F_lock2=1;
		int un_T_F_lock3=1;
		int un_T_F_lock4=1;
		int un_T_F_lock5=1;
		int un_T_F_lock6=1;
		int un_T_F_lock7=1;
		int un_T_F_lock8=1;
		int un_T_F_lock9=1;
		int un_T_F_lock10=1;
		int un_T_F_lock11=1;
		int un_T_F_lock12=1;
		int un_T_F_lock13=1;
		int un_T_F_lock14=1;
		int un_T_F_lock15=1;
		int un_T_F_lock16=1;
		int un_T_F_lock17=1;
		int un_T_F_lock18=1;
		int un_T_F_lock19=1;

/*****����ȡһ��ǰ�ŵ�ҩ���־λ*****/

		int un_O_F_lock1=1;
		int un_O_F_lock2=1;
		int un_O_F_lock3=1;
		int un_O_F_lock4=1;
		int un_O_F_lock5=1;
		int un_O_F_lock6=1;
		int un_O_F_lock7=1;
		int un_O_F_lock8=1;
		int un_O_F_lock9=1;

/***********�����־λ***********/

/****��������ȡ����ǰ�ŵ�ҩ��****/

		int buffer_lock5=1;
		int buffer_lock6=1;
		int buffer_lock7=1;
		int buffer_lock8=1;
		int buffer_lock9=1;

		int buffer_lock10=1;
		int buffer_lock11=1;
		int buffer_lock12=1;
		int buffer_lock13=1;
		int buffer_lock14=1;

/******����ǰ�ŵ�ҩ���־λ******/

		int buffer_lock=1;
		int buffer_lock1=1;
		int buffer_lock2=1;
		int buffer_lock3=1;
		int buffer_lock4=1;

/***********������־λ***********/
        int deadlock1=1;
		int deadlock2=1;
		int deadlock3=1;
		int deadlock4=1;
		int deadlock5=1;

/***********KILL��־λ***********/
        extern int KILL;
		
/*****��һ��ʶ�������Ա�־λ*****/
        int continuity1=1;
		int continuity2=1;
		int continuity3=1;
        int continuity4=1;
		int continuity5=1;
		int continuity6=1;
        int continuity7=1;
		int continuity8=1;
		int continuity9=1;		
        int continuity10=1;
		int continuity11=1;
		int continuity12=1;
		int continuity13=1;
		int continuity14=1;
		int continuity15=1;
		
/*****�ڶ���ʶ�������Ա�־λ*****/		
        int continuity16=1;
	    int continuity17=1;
	    int continuity18=1;
		int continuity19=1;		
        int continuity20=1;
	    int continuity21=1;
	    int continuity22=1;
		
void Mode_Front(void)
{
	if(deadlock1==1){
/*********����ʿ�ж�֮ǰ�ļ�ʱ*********/
          s_time_count++;
/**************************************/
	
/**************Front_Start*************/
	    if(KILL==1){
		  start_F_lock1=0;//��������̧��
		  start_F_lock2=0;//צ������
		
		   KILL=0;
		}
		
/***************Start_F****************/
  	
	if(start_F_lock1==0){
	   T_LIFT_POSITION_R = Lift_R_Value1;//��������̧��
		Toward_Left();//׷��
	   start_F_lock1=1;
    }
  	
	if(start_F_lock2==0){
		if(s_time_count>50){
		  if(auto_buffer1==1){	
	       T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//צ������
			  auto_buffer1=0;
		   }
		if(s_time_count>100){ 
 			auto_flag=0;
			auto_buffer1=1;
			
	       start_F_lock2=1;
	       s_time_count=0;
			
		   deadlock1=0;
		   deadlock2=0;
		   Start=0;
		  		  
		 }
		}
	  }
     
  }	//deadlock1
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
			
/**********Under_Twobox_Front**********/

		un_T_F_lock1=0;//צ�ӷ�תȡ��
		un_T_F_lock2=0;//��ס��ҩ��
		un_T_F_lock3=0;//����һ���߶�
		un_T_F_lock4=0;//����ҩ���뵯ҩ��
		un_T_F_lock5=0;//�����ƶ�����ȡ�ڶ�����ҩ��
		un_T_F_lock6=0;//�½�һ���߶�
		un_T_F_lock7=0;//צ���ɿ�
		un_T_F_lock8=0;//צ���ٴη�תȡ��
		un_T_F_lock9=0;//�ӳ���ҩ��
		un_T_F_lock10=0;//��ס��ҩ��
		un_T_F_lock11=0;//��λ
		un_T_F_lock12=0;//����һ���߶�
		un_T_F_lock13=0;//����ҩ���뵯ҩ��
		un_T_F_lock14=0;//�ڶ���ȡ�������Ҳ൯��
		un_T_F_lock19=0;//צ���ɿ���׷����ţ�
		un_T_F_lock15=0;//צ������
		un_T_F_lock16=0;//�ӳ���ҩ��
		un_T_F_lock17=0;//�½�һ���߶�
		un_T_F_lock18=0;//��λ

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
    if(un_T_F_lock1==0){
        if(un_time_count>20){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//צ�ӷ�תȡ��
			
		   continuity15=0;
			
	       un_T_F_lock1=1;
	       un_time_count=0;
	   }
    }
	  
	if(un_T_F_lock2==0){
	   if(continuity15==0){	
        if(un_time_count>30){
	        Clamp(); //��ס��ҩ��
	        un_T_F_lock2=1;
		    un_time_count=0;
			
			continuity15=1;
			continuity1=0;
	   }
      }	
    }
	
	if(un_T_F_lock3==0){
	  if(continuity1==0){	
	   if(un_time_count>20){
		   T_LIFT_POSITION_R = Lift_R_Value2;//����һ���߶�
		   
		   continuity1=1;
		   continuity2=0;
		   
		   un_T_F_lock3=1;
		   un_time_count=0;
	   }
      }
    }
	
	if(un_T_F_lock4==0){
	  if(continuity2==0){	
	   if(un_time_count>5){
	       T_GRAB_POSITION=Grab_Value3; //grab_baseline;//����ҩ���뵯ҩ��
		   
		   continuity2=1;
		   continuity3=0;
		   
	       un_T_F_lock4=1;
		   un_time_count=0;
	   }
      }
    }
	 
	if(un_T_F_lock5==0){
	  if(continuity3==0){	
       if(un_time_count>5){
		   T_LIFT_POSITION_R = Lift_R_Value1;//�½�һ���߶�
		   
		   continuity3=1;
		   continuity4=0;
		   
	       un_T_F_lock5=1;
	 	   un_time_count=0;
	   }
      }
    }
	 
	if(un_T_F_lock6==0){
	  if( continuity4==0){	
	   if(un_time_count>10){
           Toward_Right();
	       //Toward_Left();//�����ƶ�����ȡ�ڶ�����ҩ��
		   		   
		    continuity4=1;
		    continuity5=0;
		   
		   un_T_F_lock6=1;
		   un_time_count=0;
	   }
      } 
    }	
	
	if(un_T_F_lock7==0){
	  if(continuity5==0){	
 	   if(un_time_count>80){
	       Loosen();//צ���ɿ�
		   
		   continuity5=1;
		   continuity6=0;
		   
 		   un_T_F_lock7=1;
		   un_time_count=0;
	   }
      } 
	}
	 
	if(un_T_F_lock8==0){
	  if(continuity6==0){	
       if(un_time_count>10){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//צ���ٴη�תȡ��
		   
		   continuity6=1;
		   continuity7=0;
		   
	       un_T_F_lock8=1;
	       un_time_count=0;
	   }
     }
    }
	 
	if(un_T_F_lock9==0){
	  if(continuity7==0){	
	    if(un_time_count>5){
	        T_ROTATE_POSITION = Rotate_Value1;//�ӳ���ҩ��
			
			continuity7=1;
									
	        un_T_F_lock9=1;
			un_time_count=0;
			
			buffer_lock5=0;
			buffer_lock6=0;
						
		}
	  }	
	}
	
	if(un_T_F_lock11==0){
	   if(buffer_lock5==0){
        if(un_time_count>60){
           if(buffer_lock6==0){
	        T_ROTATE_POSITION = Rotate_Value2;//��λ
			   buffer_lock6=1;
			   buffer_lock7=0;
		   }
		}
		if(un_time_count>70){
		   if(buffer_lock7==0){
		    T_ROTATE_POSITION = Rotate_Value3;
			   buffer_lock7=1;
			   buffer_lock8=0;
		   }	
		}
		if(un_time_count>80){
		   if(buffer_lock8==0){
		    T_ROTATE_POSITION = Rotate_Value4;
			   buffer_lock8=1;
			   buffer_lock9=0;
		   }
		}
        if(un_time_count>90){
           if(buffer_lock9==0){		
	        T_ROTATE_POSITION = Rotate_Value5;
			  
            buffer_lock9=1;
			buffer_lock5=1;
			   
	        un_T_F_lock11=1;
		    un_time_count=0;
			   
			continuity8=0;   
			   
		   }
	   }
     }
    }

	if(un_T_F_lock10==0){
	   if(continuity8==0){	
		if(un_time_count>5){
			
			Clamp(); //��ס��ҩ��
			
			continuity8=1;
			continuity9=0;
			
	        un_T_F_lock10=1;
			un_time_count=0;
			
			
		}
	  }
	}    
	
	if(un_T_F_lock12==0){
	  if(continuity9==0){	
	   if(un_time_count>20){
		   
		   T_LIFT_POSITION_R = Lift_R_Value2;//����һ���߶�
		   
		   continuity9=1;
		   continuity10=0;
		   
		   un_T_F_lock12=1;
		   un_time_count=0;
	   }
      }
    }
		 
	if(un_T_F_lock13==0){
	  if(continuity10==0){	
	    if(un_time_count>15){
	        T_GRAB_POSITION= Grab_Value3;//grab_baseline;//����ҩ���뵯ҩ��
			
			continuity10=1;
			continuity11=0;
			
	        un_T_F_lock13=1;
		    un_time_count=0;
	   }
      }	
    }
	 
	
	if(un_T_F_lock19==0){
	  if(continuity11==0){	
 	   if(un_time_count>80){
	       Loosen();//צ���ɿ���׷�ӣ�
		   
		   continuity11=1;
		   continuity12=0;
		   
 		   un_T_F_lock19=1;
		   un_time_count=0;
	   }
      }
	}	
	
	if(un_T_F_lock15==0){
	  if(continuity12==0){	
		if(un_time_count>15){
	       T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//צ������
			
		   continuity12=1;
		   continuity13=0;
			
	       un_T_F_lock15=1;
	       un_time_count=0;
		}
	   }	
	}
 	
	if(un_T_F_lock16==0){
	   if(continuity13==0){	
	    if(un_time_count>10){
	        T_LIFT_POSITION_R = Lift_R_Value1;//�½�һ���߶�
			
			continuity13=1;
			continuity14=0;
						
	        un_T_F_lock16=1;
			un_time_count=0;
		}
	   }
	}
	
	if(un_T_F_lock17==0){
	   if(continuity14==0){	
		if(un_time_count>20){  //10
			
			T_ROTATE_POSITION = Rotate_Value1;//�ӳ���ҩ��
			
			continuity14=1;
			
			
	        un_T_F_lock17=1;
			un_time_count=0;
			
            buffer_lock10=0;			
			buffer_lock11=0;
		}
	   }
	}	
	
	if(un_T_F_lock18==0){
	 	
      if(buffer_lock10==0){	
	   if(un_time_count>70){
	      if(buffer_lock11==0){
	       T_ROTATE_POSITION = Rotate_Value2;//��λ
			  buffer_lock11=1;
			  buffer_lock12=0;
		  }
	   }
	   if(un_time_count>80){
		  if(buffer_lock12==0){
		   T_ROTATE_POSITION = Rotate_Value3;
			  buffer_lock12=1;
			  buffer_lock13=0;
		  }
	   
	   }
	   if(un_time_count>90){
		  if(buffer_lock13==0){
		   T_ROTATE_POSITION = Rotate_Value4;
			  buffer_lock13=1;
			  buffer_lock14=0;
		  }
	   
	   }
	   if(un_time_count>100){
		  if(buffer_lock14==0){
           T_ROTATE_POSITION = Rotate_Value5;
			  buffer_lock14=1;
			  }
		      			  
			 if(un_time_count>60){ 
			  
				auto_flag=0;//�Զ�ȡ����־λ��Ч 
								
				buffer_lock10=1;
				 
				un_T_F_lock18=1;
				un_time_count=0;
									
				deadlock3=1;
				deadlock4=0;
				N_Start=0;	  
		  }  
			  

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
			
/**********Under_Onebox_Front**********/

		un_O_F_lock1=0;//צ�ӷ�תȡ��
		un_O_F_lock2=0;//��ס��ҩ��
		un_O_F_lock3=0;//����һ���߶�
		un_O_F_lock4=0;//����ҩ���뵯ҩ��
		un_O_F_lock5=0;//צ���ɿ�
		un_O_F_lock6=0;//צ������
		un_O_F_lock7=0;//�ӳ���ҩ��
		un_O_F_lock8=0;//�½�һ���߶�
		un_O_F_lock9=0;//��λ
			 
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

   	if(un_O_F_lock1==0){
        if(N_time_count>20){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//צ�ӷ�תȡ��
			
		   continuity16=0;
			
	       un_O_F_lock1=1;
	       N_time_count=0;
		             		
	   }
    }
	
	if(un_O_F_lock2==0){
       if(continuity16==0){
        if(N_time_count>30){
	       Clamp(); //��ס��ҩ��
			
		   continuity16=1;
		   continuity17=0;
			
	       un_O_F_lock2=1;
		   N_time_count=0;
				   			
	   }
      }
 	
    }
	
	if(un_O_F_lock3==0){
	  if(continuity17==0){	
	   if(N_time_count>20){
		   T_LIFT_POSITION_R = Lift_R_Value2;//����һ���߶�
		   
		   continuity17=1;
		   continuity18=0;
		   
		   un_O_F_lock3=1;
		   N_time_count=0;
	   }
      }
    }
	
	if(un_O_F_lock4==0){
	 if(continuity18==0){	
	   if(N_time_count>5){
	       T_GRAB_POSITION=Grab_Value3; //grab_baseline;//����ҩ���뵯ҩ��
		   
		   continuity18=1;
		   continuity19=0;
		   
	       un_O_F_lock4=1;
		   N_time_count=0;
	   }
      }
    }
	
	if(un_O_F_lock5==0){
	  if(continuity19==0){	
 	   if(N_time_count>5){
	       T_LIFT_POSITION_R = Lift_R_Value1;//�½�һ���߶�
		   
		   continuity19=1;
		   continuity20=0;
		   
 		   un_O_F_lock5=1;
		   N_time_count=0;
	   }
      }
	}
	
	if(un_O_F_lock6==0){
	   if(continuity20==0){	
		if(N_time_count>80){
	       Loosen();//צ���ɿ�
			
		   continuity20=1;
		   continuity21=0;
			
	       un_O_F_lock6=1;
	       N_time_count=0;
		}
	  }
	}
	
	if(un_O_F_lock7==0){
	   if(continuity21==0){
		if(N_time_count>40){
	        T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//צ������
			
			continuity21=1;
			continuity22=0;
			
	        un_O_F_lock7=1;
			N_time_count=0;
		}
	  }
	}
	
	if(un_O_F_lock8==0){
	   if(continuity22==0){	
		if(N_time_count>30){
						
			T_ROTATE_POSITION = Rotate_Value1;//�ӳ���ҩ��
			
			continuity22=1;
						
	        un_O_F_lock8=1;
			N_time_count=0;
			
			buffer_lock=0;
			buffer_lock1=0;
		}
	   }
	}
	
	if(un_O_F_lock9==0){
	  if(buffer_lock==0){
	   if(N_time_count>70){
	        if(buffer_lock1==0){
	        T_ROTATE_POSITION = Rotate_Value2;//��λ
                  buffer_lock1=1;
				  buffer_lock2=0;
			}
	   }
	   if(N_time_count>80){
		   if(buffer_lock2==0){
		    T_ROTATE_POSITION = Rotate_Value3;
			   buffer_lock2=1;
			   buffer_lock3=0;
			   
		   }
	   }
       if(N_time_count>90){
		   if(buffer_lock3==0){
		    T_ROTATE_POSITION = Rotate_Value4;
			   buffer_lock3=1;
			   buffer_lock4=0;
		   }
	   }
	   if(N_time_count>100){
		   if(buffer_lock4==0){
		    T_ROTATE_POSITION = Rotate_Value5;
		   
		   un_O_F_lock9=1;
		   N_time_count=0;
		   
		   buffer_lock4=1;
		   buffer_lock=1;
		   
		   deadlock5=1;   
		  }
	   }
      }
    }	
  }	//deadlock5
	
}
