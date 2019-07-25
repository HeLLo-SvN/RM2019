#include "main.h"

extern int32_t T_LIFT_POSITION_R;
extern int32_t T_GRAB_POSITION;
extern int32_t T_ROTATE_POSITION;

int auto_buffer2=1;//自动向后行走缓冲
extern int auto_flag;//自动取弹标志位

extern int s_time_count;//基恩士判断之前定时器计数变量
extern int un_time_count;//基恩士判断之后定时器计数变量
extern int N_time_count;//第二次基恩士判断之后定时器计数变量

/*****第一次基恩士识别检测标志位*****/

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

/*****第二次基恩士识别检测标志位*****/
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

/*****岛下准备取后排弹药箱标志位*****/

		int start_B_lock1=1;
		int start_B_lock2=1;
		int start_B_lock3=1;

/***岛下连续取两盒后排弹药箱标志位***/

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
		
/*****岛下取一盒后排弹药箱标志位*****/	

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
		
/***********缓冲标志位***********/

/****岛下连续取两盒后排弹药箱****/

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
		
/******岛下后排弹药箱标志位******/	

		int buffer_lock15=1;
		int buffer_lock16=1;
		int buffer_lock17=1;
		int buffer_lock18=1;
		int buffer_lock19=1;

/***********自锁标志位***********/
        extern int deadlock1;
		extern int deadlock2;
		extern int deadlock3;
		extern int deadlock4;
		extern int deadlock5;

/***********KILL标志位***********/
        int KILL=1;
 
/**********消息队列令牌**********/
		int token1=0;
/********************************/

/*****第一次识别连续性标志位*****/
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
		
/*****第二次识别连续性标志位*****/		
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
/*********基恩士判断之前的计时*********/
          s_time_count++;
/**************************************/
		
/**************Behind_Start*************/
	 if(KILL==1){
	start_B_lock1=0;//升降机构抬升
	start_B_lock2=0;//伸出悬臂
	start_B_lock3=0;//爪子竖立
		 
		 KILL=0;
	 }
	
/***************Start_B****************/
		
    if(start_B_lock1==0){
	   T_LIFT_POSITION_R = Lift_R_Value1;//升降机构抬升
	    //Toward_Left();//追加
	   start_B_lock1=1;
    }
	
	if(start_B_lock2==0){
	   if(s_time_count>100){
		   Extension();//伸出悬臂
		   start_B_lock2=1;
		   s_time_count=0;
		   token1=1; 
	    }
    }
	
  if(token1==1){	
	if(start_B_lock3==0){
		if(s_time_count>50){

		 if(auto_buffer2==1){	
	       T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//爪子竖立
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
/**************基恩士识别*************/ 	
  if(deadlock2==0){
	if(Start==0){
/**通过Keyence检测是否有取弹条件**/	
	Grab_Condition=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);//Left_Limit();
/***********只判断三次***********/ 
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

/**********车制动标志位立即生效**********/
				auto_flag=1;//自动取弹标志位
			 
/*************解锁相应标志位*************/	
			
/********** Under_Twobox_Behind**********/

			un_T_B_lock1=0;//爪子翻转取弹
			un_T_B_lock2=0;//夹住弹药箱
			un_T_B_lock3=0;//上升一定高度
			un_T_B_lock4=0;//将弹药倒入弹药箱
			un_T_B_lock5=0;//向左移动连续取第二个弹药箱
			un_T_B_lock6=0;//下降一定高度
			un_T_B_lock7=0;//爪子松开
			un_T_B_lock8=0;//爪子再次翻转取弹
			un_T_B_lock9=0;//扔出弹药箱
			un_T_B_lock10=0;//夹住弹药箱
			un_T_B_lock11=0;//复位
			un_T_B_lock12=0;//上升一定高度
			un_T_B_lock13=0;//将弹药倒入弹药箱
			un_T_B_lock14=0;//第二次取弹放置右侧弹舱
			un_T_B_lock15=0;//收回悬臂
			un_T_B_lock20=0;//爪子松开（追加序号）
			un_T_B_lock16=0;//爪子竖立
			un_T_B_lock17=0;//扔出弹药箱
			un_T_B_lock18=0;//下降一定高度
			un_T_B_lock19=0;//复位

/**********自锁标志位立即生效**********/		 
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
/*********基恩士判断之后的计时*********/
          un_time_count++;
/**************************************/
	  
/**************************************/
    if(un_T_B_lock1==0){
       if(un_time_count>20){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//爪子翻转取弹
		   
		   B_continuity1=0;
		   
	       un_T_B_lock1=1;
	       un_time_count=0;
	   }
    }
	
    if(un_T_B_lock2==0){
	   if(B_continuity1==0){	
        if(un_time_count>30){
	       Clamp(); //夹住弹药箱
			
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
		   T_LIFT_POSITION_R = Lift_R_Value2;//上升一定高度
		   
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
	       //T_GRAB_POSITION= Grab_Value3;// grab_baseline;//将弹药倒入弹药箱
		   
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
           T_LIFT_POSITION_R = Lift_R_Value1;//下降一定高度
		   
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
	       //Toward_Left();//向右移动连续取第二个弹药箱
		   
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
	       Loosen();//爪子松开
		   
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
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//爪子再次翻转取弹
		   
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
//	        T_ROTATE_POSITION = Rotate_Value1;//扔出弹药箱
			
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
			
			Clamp(); //夹住弹药箱
			
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
//	        T_ROTATE_POSITION = Rotate_Value2;//复位
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
		   
		   T_LIFT_POSITION_R = Lift_R_Value2;//上升一定高度
		   
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
	        //T_GRAB_POSITION= Grab_Value3;//grab_baseline;//将弹药倒入弹药箱
			
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
		   
		   T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//爪子竖立
	       		   
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
	       
		   Loosen();//爪子松开（追加）
			
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
	        T_LIFT_POSITION_R = Lift_R_Value1;//下降一定高度
			
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
			
			auto_flag=0;//自动取弹标志位生效
			
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
/************基恩士再次识别***********/
 if(deadlock4==0){	
	if(N_Start==0){
/**通过Keyence检测是否有取弹条件**/	
	N_Grab_Condition=GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_13);//Left_Limit();
/***********只判断三次***********/ 
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

/**********车制动标志位立即生效**********/
				auto_flag=1;//自动取弹标志位
			 
/*************解锁相应标志位*************/	
			
/**********Under_Onebox_Behind**********/

			un_O_B_lock1=0;//爪子翻转取弹
			un_O_B_lock2=0;//夹住弹药箱
			un_O_B_lock3=0;//上升一定高度
			un_O_B_lock4=0;//将弹药倒入弹药箱
			un_O_B_lock5=0;//收回悬臂
			un_O_B_lock6=0;//爪子松开
			un_O_B_lock7=0;//爪子竖立
			un_O_B_lock8=0;//扔出弹药箱
			un_O_B_lock9=0;//下降一定高度
			un_O_B_lock10=0;//复位
			 
/**********自锁标志位立即生效**********/		 
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
/******第二次基恩士判断之后的计时******/
          N_time_count++;
/**************************************/   
    if(un_O_B_lock1==0){
       if(N_time_count>20){
	       T_GRAB_POSITION = Grab_Value2;//+grab_baseline;//爪子翻转取弹
		   
		   B_continuity16=0;
		   
	       un_O_B_lock1=1;
	       N_time_count=0;
	   }
    }
	
    if(un_O_B_lock2==0){
	   if(B_continuity16==0){	
        if(N_time_count>30){
	       Clamp(); //夹住弹药箱
			
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
		   T_LIFT_POSITION_R = Lift_R_Value2;//上升一定高度
		   
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
	       //T_GRAB_POSITION= Grab_Value3;//grab_baseline;//将弹药倒入弹药箱
		   
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
		   Contraction();//收回悬臂
		   
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
	       		   
		   T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//爪子竖立
		   
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
	       
		   Loosen();//爪子松开
		   
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
	        T_LIFT_POSITION_R = Lift_R_Value1;//下降一定高度
			
			B_continuity22=1;
	
	        un_O_B_lock8=1;
			N_time_count=0;
			
			deadlock5=1;
			
		}
	   }
	}
	
  }	//deadlock5
 
}
