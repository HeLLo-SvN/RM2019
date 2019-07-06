#include "main.h"

PID_AbsoluteType  gyro_Angle;

float F_GYRO_ANGLE=0;

extern float B_GYRO_ANGLE;
extern float INSTANTANEOUS;

extern double P1;
extern double I1;
extern double D1;

extern double TP;

void Gyropid_Init(void)
{
    gyro_Angle.kp=0;
	gyro_Angle.ki=0;
	gyro_Angle.kd=0;
	gyro_Angle.errNow=0;
	gyro_Angle.errILim=350;
	gyro_Angle.MaxOut=6000;
	gyro_Angle.ctrOut=0;
}

void Gyropid_Configuration(void)
{
     #if Adjust
	 
	 gyro_Angle.kp=P1;
	 gyro_Angle.ki=I1;
	 gyro_Angle.kd=D1;
			
	 #endif
	
	 #if !Adjust
	 
	 gyro_Angle.kp=GYROP;
	 gyro_Angle.ki=GYROI;
	 gyro_Angle.kd=GYROD;
	
	 #endif

	gyro_Angle.errNow = (INSTANTANEOUS-B_GYRO_ANGLE)*10;
    PID_AbsoluteMode(&gyro_Angle);
	F_GYRO_ANGLE = gyro_Angle.ctrOut;
	
}
