#include "main.h"

extern int32_t T_LIFT_POSITION_R;
extern int32_t T_GRAB_POSITION;
extern int32_t T_ROTATE_POSITION;

extern int grab_baseline;//建立抓取机构的基准位置
extern int lift_baseline;//建立升降机构的基准位置

int auto_buffer1=1;//自动向后行走缓冲
extern int auto_flag;//自动取弹标志位

int s_time_count;//基恩士判断之前定时器计数变量
int un_time_count;//基恩士判断之后定时器计数变量
int N_time_count;//第二次基恩士判断之后定时器计数变量

int DN_time_count;//第三次基恩士判断之后定时器计数变量（总决赛追加）

/*****第一次基恩士识别检测标志位*****/

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

/*****第二次基恩士识别检测标志位*****/
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

/*****第三次基恩士识别检测标志位*****///（总决赛追加）

int DN_Grab_Condition;

int DN_First=0;
int DN_Double=0;
int DN_Triple=0;

int DN_times=0;
int DN_times_lock=1;
int DN_times_lock1=1;
int DN_times_lock2=1;
int DN_times_lock3=1;
int DN_last_value=0;
int DN_last_value1=0;

int DN_Start=1;

/*****岛下准备取前排弹药箱标志位*****/

		int start_F_lock1=1;
		int start_F_lock2=1;

/***岛下连续取两盒前排弹药箱标志位***/

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

/*****岛下取一盒前排弹药箱标志位*****/

		int un_O_F_lock1=1;
		int un_O_F_lock2=1;
		int un_O_F_lock3=1;
		int un_O_F_lock4=1;
		int un_O_F_lock5=1;
		int un_O_F_lock6=1;
		int un_O_F_lock7=1;
		int un_O_F_lock8=1;
		int un_O_F_lock9=1;

/***岛下连续取下一盒弹药箱标志位***///（总决赛追加）

	   int DO_lock1=1;
	   int DO_lock2=1;
	   int DO_lock3=1;
       int DO_lock4=1;
	   int DO_lock5=1;
	   int DO_lock6=1;
	   int DO_lock7=1;
       int DO_lock8=1;
	   int DO_lock9=1;
	   int DO_lock10=1;

/***********缓冲标志位***********/

/****岛下连续取两盒前排弹药箱****/

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

/******岛下前排弹药箱标志位******/

		int buffer_lock=1;
		int buffer_lock1=1;
		int buffer_lock2=1;
		int buffer_lock3=1;
		int buffer_lock4=1;

/***********自锁标志位***********/
        int deadlock1=1;
		int deadlock2=1;
		int deadlock3=1;
		int deadlock4=1;
		int deadlock5=1;
		int D_deadlock6=1;//（总决赛追加）
	    int D_deadlock7=1;//（总决赛追加）

/***********KILL标志位***********/
        extern int KILL;
		
/*****第一次识别连续性标志位*****/
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
		
/*****第二次识别连续性标志位*****/		
        int continuity16=1;
	    int continuity17=1;
	    int continuity18=1;
		int continuity19=1;		
        int continuity20=1;
	    int continuity21=1;
	    int continuity22=1;

/*****第三次识别连续性标志位*****/ ///（总决赛追加）	
       int D_continuity16=1;
	   int D_continuity17=1;
	   int D_continuity18=1;
   	   int D_continuity19=1;		
       int D_continuity20=1;
	   int D_continuity21=1;
	   int D_continuity22=1;
   	   int D_continuity23=1;
	   int D_continuity24=1;

void Mode_Front(void)
{
	if(deadlock1==1){
/*********基恩士判断之前的计时*********/
          s_time_count++;
/**************************************/
	
/**************Front_Start*************/
	    if(KILL==1){
		  start_F_lock1=0;//升降机构抬升
		  start_F_lock2=0;//爪子竖立
		
		   KILL=0;
		}
		
/***************Start_F****************/
  	
	if(start_F_lock1==0){
	   T_LIFT_POSITION_R = Lift_R_Value1;//+lift_baseline;//升降机构抬升

	   start_F_lock1=1;
    }
  	
	if(start_F_lock2==0){
//		if(s_time_count>50){
//		  if(auto_buffer1==1){	
//	       T_GRAB_POSITION = Grab_Value1;//+grab_baseline;//爪子竖立
//			  auto_buffer1=0;
//		   }
		if(s_time_count>5){ 
 			auto_flag=0;
//			auto_buffer1=1;
			
	       start_F_lock2=1;
	       s_time_count=0;
			
		   deadlock1=0;
		   deadlock2=0;
		   Start=0;
		  		  
		 }
//		}
	  }
     
  }	//deadlock1
/**************基恩士识别*************/ 	
  if(deadlock2==0){
	if(Start==0){
/**通过Keyence检测是否有取弹条件**/	
	Grab_Condition=Right_Limit();
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
			
/**********Under_Twobox_Front**********/

		un_T_F_lock1=0;//爪子翻转取弹
		un_T_F_lock2=0;//夹住弹药箱
		un_T_F_lock3=0;//上升一定高度
		un_T_F_lock4=0;//将弹药倒入弹药箱
		un_T_F_lock5=0;//向左移动连续取第二个弹药箱
		un_T_F_lock6=0;//下降一定高度
		un_T_F_lock7=0;//爪子松开
		un_T_F_lock8=0;//爪子再次翻转取弹
		un_T_F_lock9=0;//扔出弹药箱
		un_T_F_lock10=0;//夹住弹药箱
		un_T_F_lock11=0;//复位
		un_T_F_lock12=0;//上升一定高度
		un_T_F_lock13=0;//将弹药倒入弹药箱
		un_T_F_lock14=0;//第二次取弹放置右侧弹舱
		un_T_F_lock19=0;//爪子松开（追加序号）
		un_T_F_lock15=0;//爪子竖立
		un_T_F_lock16=0;//扔出弹药箱
		un_T_F_lock17=0;//下降一定高度
		un_T_F_lock18=0;//复位

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
    if(un_T_F_lock1==0){
        if(un_time_count>5){
	       T_GRAB_POSITION = Grab_Value1+grab_baseline;//爪子翻转取弹
			
		   continuity15=0;
			
	       un_T_F_lock1=1;
	       un_time_count=0;
	   }
    }
	  
	if(un_T_F_lock2==0){
	   if(continuity15==0){	
        if(un_time_count>30){
	        Clamp(); //夹住弹药箱
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
		  
		   T_GRAB_POSITION=Grab_Value3+grab_baseline;//将弹药倒入弹药箱
		   
		   continuity1=1;
		   continuity5=0;
		   
		   un_T_F_lock3=1;
		   un_time_count=0;
	   }
      }
    }
			
	if(un_T_F_lock7==0){
	  if(continuity5==0){	
 	   if(un_time_count>50){
	       Loosen();//爪子松开
		   
		   continuity5=1;
		   continuity12=0;
		   
 		   un_T_F_lock7=1;
		   un_time_count=0;
	   }
      } 
	}
			
	if(un_T_F_lock15==0){
	  if(continuity12==0){	
		if(un_time_count>15){
			
	       T_GRAB_POSITION = Grab_Value2+grab_baseline;//爪子竖立
			
		   continuity12=1;
		   continuity13=0;
			
	       un_T_F_lock15=1;
	       un_time_count=0;
		}
	   }	
	}
 	
	if(un_T_F_lock16==0){
	   if(continuity13==0){	
	    if(un_time_count>30){
			
			Pop();//扔出弹药箱
	        
			continuity13=1;
			continuity14=0;
									
	        un_T_F_lock16=1;
			un_time_count=0;
			
			auto_flag=0;//自动取弹标志位生效
									
		}
	   }
	}
	
	if(un_T_F_lock18==0){
	   if(continuity14==0){		      			  
	    if(un_time_count>10){ 
			 
			Withdraw();//弹射机构复位
			
            continuity14=1;			
							 
			un_T_F_lock18=1;
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
	N_Grab_Condition=Right_Limit();
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
			
/**********Under_Onebox_Front**********/

		un_O_F_lock1=0;//爪子翻转取弹
		un_O_F_lock2=0;//夹住弹药箱
		un_O_F_lock3=0;//上升一定高度
		un_O_F_lock4=0;//将弹药倒入弹药箱
		un_O_F_lock5=0;//爪子松开
		un_O_F_lock6=0;//爪子竖立
		un_O_F_lock7=0;//扔出弹药箱
		un_O_F_lock8=0;//下降一定高度
		un_O_F_lock9=0;//复位
			 
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

   	if(un_O_F_lock1==0){
        if(N_time_count>5){
	       T_GRAB_POSITION = Grab_Value1+grab_baseline;//爪子翻转取弹
			
		   continuity16=0;
			
	       un_O_F_lock1=1;
	       N_time_count=0;
		             		
	   }
    }
	
	if(un_O_F_lock2==0){
       if(continuity16==0){
        if(N_time_count>30){
	       Clamp(); //夹住弹药箱
			
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
		   
		   T_GRAB_POSITION=Grab_Value3+grab_baseline;//将弹药倒入弹药箱
		   
		   continuity17=1;
		   continuity20=0;
		   
		   un_O_F_lock3=1;
		   N_time_count=0;
	   }
      }
    }	

	if(un_O_F_lock6==0){
	   if(continuity20==0){	
		if(N_time_count>50){
			
	       Loosen();//爪子松开
			
		   continuity20=1;
		   continuity21=0;
			
	       un_O_F_lock6=1;
	       N_time_count=0;
		}
	  }
	}
	
	if(un_O_F_lock7==0){
	   if(continuity21==0){
		if(N_time_count>15){
	        T_GRAB_POSITION = Grab_Value2+grab_baseline;//爪子竖立
			
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
						
			Pop();//扔出弹药箱
			
			continuity22=1;
			continuity18=0;
						
	        un_O_F_lock8=1;
			N_time_count=0;
			
			auto_flag=0;//自动取弹标志位生效
						
		}
	   }
	}
	
	if(un_O_F_lock9==0){
       if(continuity18==0){
	    if(N_time_count>10){
		
		   Withdraw();//弹射机构复位
			
		   continuity18=1;
			
		   un_O_F_lock9=1;
		   N_time_count=0;
		   		   		   
		   deadlock5=1;  
			
		   D_deadlock6=0;
		   DN_Start=0;
		  
	   }
      }
    }	
  }	//deadlock5

  /************基恩士三次识别***********///（总决赛追加）
 if(D_deadlock6==0){	
	if(DN_Start==0){
/**通过Keyence检测是否有取弹条件**/	
	DN_Grab_Condition= Right_Limit();
/***********只判断三次***********/ 
   if(DN_times==3){
		  DN_times_lock=0;
	   }
	 if(DN_times_lock==1){
		 
	   if(DN_times_lock1==1){
        if(DN_Grab_Condition==1){
 	         DN_First=1;
		     DN_times+=1;
		   DN_times_lock1=0;
			DN_last_value=1;			
          }
	     }
	   
	    if(DN_times_lock2==1){
		 if(DN_last_value==1){	
	     if(DN_Grab_Condition==0){
		     DN_Double=1;
		     DN_times+=1;
			DN_times_lock2=0;
			 DN_last_value=0;
			 DN_last_value1=1;
	       }
	      }
	     }
		
		if(DN_times_lock3==1){
		 if(DN_last_value1==1){
		  if(DN_Grab_Condition==1){
			 DN_Triple=1;
			 DN_times+=1;
			DN_times_lock3=0;
			 DN_last_value1=0;
		    }
		   }
	      }
		
		}
	    
		 if(DN_First*DN_Double*DN_Triple==1){

/**********车制动标志位立即生效**********/
				auto_flag=1;//自动取弹标志位
			 
/*************解锁相应标志位*************/	
			
/**************ON_NEXT_Box***************/

			DO_lock1=0;//爪子翻转取弹
			DO_lock2=0;//夹住弹药箱
			DO_lock3=0;//上升一定高度
			DO_lock4=0;//将弹药倒入弹药箱
			DO_lock5=0;//收回悬臂
			DO_lock6=0;//爪子松开
			DO_lock7=0;//爪子竖立
			DO_lock8=0;//扔出弹药箱
			DO_lock9=0;//下降一定高度
			DO_lock10=0;//复位
			 
/**********自锁标志位立即生效**********/		 
			     D_deadlock6=1;  
			     D_deadlock7=0;
			 
                  DN_First=0;
				  DN_Double=0;
				  DN_Triple=0;
				 				 		 		 
				  DN_Start=1;
           }
		 
   }  	
  }//D_deadlock6   （总决赛追加） 
 
 if(D_deadlock7==0){	//（总决赛追加）
/******第三次基恩士判断之后的计时******/
          DN_time_count++;
/**************************************/   
    if(DO_lock1==0){
       if(DN_time_count>5){
	       T_GRAB_POSITION = Grab_Value1+grab_baseline;//爪子翻转取弹
		   
		   D_continuity16=0;
		   
	       DO_lock1=1;
	       DN_time_count=0;
	   }
    }
	
    if(DO_lock2==0){
	   if(D_continuity16==0){	
        if(DN_time_count>20){
	       Clamp(); //夹住弹药箱
			
		   D_continuity16=1;
		   D_continuity18=0;
			
	       DO_lock2=1;
		   DN_time_count=0;
	   }
      }
    }
	
	if(DO_lock4==0){
	  if(D_continuity18==0){	
	   if(DN_time_count>15){
	       T_GRAB_POSITION= Grab_Value3+grab_baseline;//将弹药倒入弹药箱
		   
		   D_continuity18=1;
		   D_continuity19=0;
		   
	       DO_lock4=1;
		   DN_time_count=0;
	   }
      }
    }
	
	if(DO_lock5==0){
	  if(D_continuity19==0){
	   if(DN_time_count>50){
		   Loosen();//爪子松开
		   
		   D_continuity19=1;
		   D_continuity20=0;
		   
		   DO_lock5=1;
		   DN_time_count=0;
	   }
      }
    }		
	
	if(DO_lock6==0){
	  if(D_continuity20==0){	
 	   if(DN_time_count>15){
	       T_GRAB_POSITION = Grab_Value2+grab_baseline;//爪子竖立
		   
		   D_continuity20=1;
		   D_continuity21=0;
		  
 		   DO_lock6=1;
		   DN_time_count=0;
	   }
      }
	}
	
	if(DO_lock7==0){
	  if(D_continuity21==0){	
	   if(DN_time_count>30){
		   
	       Pop();//扔出弹药箱
		   		   
		   D_continuity21=1;
		   D_continuity22=0;
		   
	       DO_lock7=1;
	       DN_time_count=0;
		   
		   
		}
	  }
	}
	
	if(DO_lock8==0){
	  if(D_continuity22==0){	
	   if(DN_time_count>10){
		   
	       Withdraw();//弹射机构复位
		   		   
		   D_continuity22=1;
		   D_continuity23=0;
		   
	       DO_lock8=1;
	       DN_time_count=0;
		   
		   
		}
	  }
	}
	
	if(DO_lock9==0){
	  if(D_continuity23==0){	
	   if(DN_time_count>20){
		   
	       T_GRAB_POSITION = Grab_Value3+grab_baseline;//爪子复位
		   		   
		   D_continuity23=1;
		   D_continuity24=0;
		  		   
	       DO_lock9=1;
	       DN_time_count=0;
		   
	
		}
	  }
	}
	
	if(DO_lock10==0){
	  if(D_continuity24==0){	
	   if(DN_time_count>1){
		   
//	       T_LIFT_POSITION_R = Lift_R_Value2;//+lift_baseline;//升降复位
		   		   
		   D_continuity24=1;
		  		   
	       DO_lock10=1;
	       DN_time_count=0;
		   
		   D_deadlock7=1;
		}
	  }
	}
	
  }	//D_deadlock7 （总决赛追加）  

  
}
