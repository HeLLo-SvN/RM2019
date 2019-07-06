#include "main.h"

PID_AbsoluteType grab_Ex;
PID_AbsoluteType grab_In;

extern int32_t GRAB_POSITION;
int32_t T_GRAB_POSITION;
extern int16_t B_V_GRAB;
int32_t F_GRAB_POSITION;

extern double P2;
extern double I2;
extern double D2;

extern double P3;
extern double I3;
extern double D3;

extern double TP;

void Grabpid_Init(void)
{
    grab_Ex.kp=0;
	grab_Ex.ki=0;
	grab_Ex.kd=0;
	grab_Ex.errNow=0;
/******外环位置环******/	
	grab_Ex.errILim=0;//积分上限
	grab_Ex.MaxOut=5000;//最大输出量
/**********************/	
	grab_Ex.ctrOut=0;

    grab_In.kp=0;
	grab_In.ki=0;
	grab_In.kd=0;
	grab_In.errNow=0;
/******内环速度环******/
	grab_In.errILim=5000;
	grab_In.MaxOut=30000;
/**********************/
	grab_In.ctrOut=0;

}

void Grabpid_Configuration(void)
{
     #if Adjust
	 
	 grab_Ex.kp=P2;
	 grab_Ex.ki=I2;
	 grab_Ex.kd=D2;
	
	 grab_In.kp=P3;
	 grab_In.ki=I3;
	 grab_In.kd=D3;
		
	 #endif
	
	 #if !Adjust
	 
	 grab_Ex.kp=ExGrabP;
	 grab_Ex.ki=ExGrabI;
	 grab_Ex.kd=ExGrabD;
	
	 grab_In.kp=InGrabP;
	 grab_In.ki=InGrabI;
	 grab_In.kd=InGrabD;
		 
	 #endif
	
//	T_GRAB_POSITION = TP;
	grab_Ex.errNow = T_GRAB_POSITION - GRAB_POSITION;
	PID_AbsoluteMode(&grab_Ex);
	grab_In.errNow = grab_Ex.ctrOut - B_V_GRAB;
    PID_AbsoluteMode(&grab_In);
	F_GRAB_POSITION = grab_In.ctrOut;
	
}
