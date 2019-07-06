#include "main.h"

int16_t F_TOP_L;
int16_t F_TOP_R;
int16_t F_DOWN_L;
int16_t F_DOWN_R;
int16_t F_MID_L;
int16_t F_MID_R;

PID_AbsoluteType topleft;
PID_AbsoluteType topright;
PID_AbsoluteType downleft;
PID_AbsoluteType downright;
PID_AbsoluteType midleft;
PID_AbsoluteType midright;

extern double P1;
extern double I1;
extern double D1;

extern int16_t T_TOP_L;
extern int16_t T_TOP_R;
extern int16_t T_DOWN_L;
extern int16_t T_DOWN_R;
extern int16_t T_MID_L;
extern int16_t T_MID_R;

extern int16_t B_TOP_L;
extern int16_t B_TOP_R;
extern int16_t B_DOWN_L;
extern int16_t B_DOWN_R;
extern int16_t B_MID_L;
extern int16_t B_MID_R;

void Chassispid_Init(void)
{
	
    topleft.kp=0;
	topleft.ki=0;
	topleft.kd=0;
	topleft.errNow=0;
	topleft.errILim=6000;
	topleft.MaxOut=30000;
	topleft.ctrOut=0;

    topright.kp=0;
	topright.ki=0;
	topright.kd=0;
	topright.errNow=0;
	topright.errILim=6000;
	topright.MaxOut=30000;
	topright.ctrOut=0;

    downleft.kp=0;
	downleft.ki=0;
	downleft.kd=0;
	downleft.errNow=0;
	downleft.errILim=6000;
	downleft.MaxOut=30000;
	downleft.ctrOut=0;

    downright.kp=0;
	downright.ki=0;
	downright.kd=0;
	downright.errNow=0;
	downright.errILim=6000;
	downright.MaxOut=30000;
	downright.ctrOut=0;
	
	midleft.kp=0;
	midleft.ki=0;
	midleft.kd=0;
	midleft.errNow=0;
	midleft.errILim=6000;
	midleft.MaxOut=30000;
	midleft.ctrOut=0;
	
	midright.kp=0;
	midright.ki=0;
	midright.kd=0;
	midright.errNow=0;
	midright.errILim=6000;
	midright.MaxOut=30000;
	midright.ctrOut=0;

}

void Chassispid_Configuration(void)
{
   #if Adjust
	 
	 topleft.kp=P1;
	 topleft.ki=I1;
	 topleft.kd=D1;
	
	 topright.kp=P1;
	 topright.ki=I1;
	 topright.kd=D1;
	
	 downleft.kp=P1;
	 downleft.ki=I1;
	 downleft.kd=D1;
	
	 downright.kp=P1;
	 downright.ki=I1;
	 downright.kd=D1;
	
	 midleft.kp=P1;
	 midleft.ki=I1;
	 midleft.kd=D1;
	 
	 midright.kp=P1;
	 midright.ki=I1;
	 midright.kd=D1;
	
	 #endif

	 #if !Adjust
	 
     topleft.kp=ChassisP;
	 topleft.ki=ChassisI;
	 topleft.kd=ChassisD;
	
	 topright.kp=ChassisP;
	 topright.ki=ChassisI;
	 topright.kd=ChassisD;
	
	 downleft.kp=ChassisP;
	 downleft.ki=ChassisI;
	 downleft.kd=ChassisD;
	
	 downright.kp=ChassisP;
	 downright.ki=ChassisI;
	 downright.kd=ChassisD;
	 
	 midleft.kp=ChassisP;
	 midleft.ki=ChassisI;
	 midleft.kd=ChassisD;
	 
	 midright.kp=ChassisP;
	 midright.ki=ChassisI;
	 midright.kd=ChassisD;
	 
   #endif

    topleft.errNow = T_TOP_L-B_TOP_L;  
	topright.errNow = T_TOP_R-B_TOP_R;    
	downleft.errNow = T_DOWN_L-B_DOWN_L;   
	downright.errNow = T_DOWN_R-B_DOWN_R;
	midleft.errNow = T_MID_L-B_MID_L;   
	midright.errNow = T_MID_R-B_MID_R;
	
	
	PID_AbsoluteMode(&topleft);
	F_TOP_L = topleft.ctrOut;
	
	PID_AbsoluteMode(&topright);
	F_TOP_R = topright.ctrOut;

    PID_AbsoluteMode(&downleft);
	F_DOWN_L = downleft.ctrOut;
	
	PID_AbsoluteMode(&downright);
	F_DOWN_R = downright.ctrOut;

    PID_AbsoluteMode(&midleft);
	F_MID_L = midleft.ctrOut;
	
    PID_AbsoluteMode(&midright);
	F_MID_R = midright.ctrOut;

  V_Back((int16_t)F_TOP_L,(int16_t)F_TOP_R,(int16_t)F_DOWN_L,(int16_t)F_DOWN_R);
	
  VR_Back((int16_t)F_MID_L ,(int16_t)F_MID_R,0,0);
}

