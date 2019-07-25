#include "main.h"

PID_AbsoluteType lift_L_Ex;
PID_AbsoluteType lift_L_In;
PID_AbsoluteType lift_R_Ex;
PID_AbsoluteType lift_R_In;

extern int32_t LIFT_POSITION_L;
extern int32_t LIFT_POSITION_R;
int32_t T_LIFT_POSITION_L;
int32_t T_LIFT_POSITION_R;
extern int16_t B_V_LIFT_L;
extern int16_t B_V_LIFT_R;
int32_t F_LIFT_POSITION_L;
int32_t F_LIFT_POSITION_R;

extern double P2;
extern double I2;
extern double D2;

extern double P3;
extern double I3;
extern double D3;

extern double TPL;
extern double TPR;

extern double P4;
extern double I4;
extern double D4;

extern double P5;
extern double I5;
extern double D5;

void Liftpid_Init(void)
{
	
//  lift_L_Ex.kp=0;
//	lift_L_Ex.ki=0;
//	lift_L_Ex.kd=0;
//	lift_L_Ex.errNow=0;
///******外环位置环******/	
//	lift_L_Ex.errILim=0;//积分上限
//	lift_L_Ex.MaxOut=5000;//最大输出量
///**********************/	
//	lift_L_Ex.ctrOut=0;

//    lift_L_In.kp=0;
//	lift_L_In.ki=0;
//	lift_L_In.kd=0;
//	lift_L_In.errNow=0;
///******内环速度环******/
//	lift_L_In.errILim=5000;
//	lift_L_In.MaxOut=20000;
///**********************/
//	lift_L_In.ctrOut=0;

    lift_R_Ex.kp=0;
	lift_R_Ex.ki=0;
	lift_R_Ex.kd=0;
	lift_R_Ex.errNow=0;
/******外环位置环******/
	lift_R_Ex.errILim=0;//积分上限
	lift_R_Ex.MaxOut=6000;//最大输出量
/**********************/	
	lift_R_Ex.ctrOut=0;

    lift_R_In.kp=0;
	lift_R_In.ki=0;
	lift_R_In.kd=0;
	lift_R_In.errNow=0;
/******内环速度环******/
	lift_R_In.errILim=6000;
	lift_R_In.MaxOut=25000;
/**********************/
	lift_R_In.ctrOut=0;
	
}

void Liftpid_Configuration(void)
{
     #if Adjust
	 
//	 lift_L_Ex.kp=P4;
//	 lift_L_Ex.ki=I4;
//	 lift_L_Ex.kd=D4;
//	
//	 lift_L_In.kp=P5;
//	 lift_L_In.ki=I5;
//	 lift_L_In.kd=D5;
	
	 lift_R_Ex.kp=P4;
	 lift_R_Ex.ki=I4;
	 lift_R_Ex.kd=D4;

	 lift_R_In.kp=P5;
	 lift_R_In.ki=I5;
	 lift_R_In.kd=D5;
	
	 #endif
	
	 #if !Adjust
	 
//	 lift_L_Ex.kp=ExLiftP;
//	 lift_L_Ex.ki=ExLiftI;
//	 lift_L_Ex.kd=ExLiftD;
//	
//	 lift_L_In.kp=InLiftP;
//	 lift_L_In.ki=InLiftI;
//	 lift_L_In.kd=InLiftD;
	
	 lift_R_Ex.kp=ExLiftP;
	 lift_R_Ex.ki=ExLiftI;
	 lift_R_Ex.kd=ExLiftD;
	
	 lift_R_In.kp=InLiftP;
	 lift_R_In.ki=InLiftI;
	 lift_R_In.kd=InLiftD;
	 
	 #endif
	
//	T_LIFT_POSITION_L = TPL;
//	lift_L_Ex.errNow = T_LIFT_POSITION_L - LIFT_POSITION_L;
//	PID_AbsoluteMode(&lift_L_Ex);
//	lift_L_In.errNow = lift_L_Ex.ctrOut - B_V_LIFT_L;
//  PID_AbsoluteMode(&lift_L_In);
//  F_LIFT_POSITION_L = lift_L_In.ctrOut;

//  T_LIFT_POSITION_R = TPR;
    lift_R_Ex.errNow = T_LIFT_POSITION_R - LIFT_POSITION_R;
    PID_AbsoluteMode(&lift_R_Ex);
    lift_R_In.errNow = lift_R_Ex.ctrOut - B_V_LIFT_R;
	PID_AbsoluteMode(&lift_R_In);
	F_LIFT_POSITION_R = lift_R_In.ctrOut;

    F_LIFT_POSITION_L = -lift_R_In.ctrOut;
	
}
