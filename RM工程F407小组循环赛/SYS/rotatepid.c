#include "main.h"

PID_AbsoluteType rotate_Ex;
PID_AbsoluteType rotate_In;

extern int32_t ROTATE_POSITION;
int32_t T_ROTATE_POSITION;
extern int16_t B_V_ROTATE;
int32_t F_ROTATE_POSITION;

extern double P2;
extern double I2;
extern double D2;

extern double P3;
extern double I3;
extern double D3;

extern double TP;

int up_Down=1;

void Rotatepid_Init(void)
{
	
    rotate_Ex.kp=0;
	rotate_Ex.ki=0;
	rotate_Ex.kd=0;
	rotate_Ex.errNow=0;
/******外环位置环******/	
	rotate_Ex.errILim=0;//积分上限
	rotate_Ex.MaxOut=5000;//最大输出量
/**********************/	
	rotate_Ex.ctrOut=0;

    rotate_In.kp=0;
	rotate_In.ki=0;
	rotate_In.kd=0;
	rotate_In.errNow=0;
/******内环速度环******/
	rotate_In.errILim=5000;
	rotate_In.MaxOut=25000;
/**********************/
	rotate_In.ctrOut=0;

}

void Rotatepid_Configuration(void)
{
     #if Adjust
	 
	 rotate_Ex.kp=P2;
	 rotate_Ex.ki=I2;
	 rotate_Ex.kd=D2;
	
	 rotate_In.kp=P3;
	 rotate_In.ki=I3;
	 rotate_In.kd=D3;
		
	 #endif
	
	 #if !Adjust
	 	
	 rotate_Ex.kp=U_ExRotateP;
	 rotate_Ex.ki=U_ExRotateI;
	 rotate_Ex.kd=U_ExRotateD;
	
	 rotate_In.kp=U_InRotateP;
	 rotate_In.ki=U_InRotateI;
	 rotate_In.kd=U_InRotateD;
	
	 #endif
	 
//	T_ROTATE_POSITION = TP;
	rotate_Ex.errNow = T_ROTATE_POSITION - ROTATE_POSITION;
	PID_AbsoluteMode(&rotate_Ex);
	rotate_In.errNow = rotate_Ex.ctrOut - B_V_ROTATE;
    PID_AbsoluteMode(&rotate_In);
	F_ROTATE_POSITION = rotate_In.ctrOut;
	
}
