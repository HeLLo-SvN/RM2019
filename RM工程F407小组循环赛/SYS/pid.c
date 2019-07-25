#include "main.h"

/*********************增量式PID控制***********************/
void PID_IncrementMode(PID_IncrementType *pid)
{
float dErrP,dErrI,dErrD;
	
	/*if(pid->kp<0) pid->kp=-pid->kp;
	if(pid->ki<0) pid->ki=-pid->ki;
	if(pid->kd<0) pid->kd=pid->kd;*/
	
	dErrP = pid->errNow-pid->errold1;
	dErrI = pid->errNow;
	dErrD = pid->errNow - 2*pid->errold1 + pid->errold2;
	
	pid->errold2 = pid->errold1;
	pid->errold1 = pid->errNow;
	
	pid->dCtrOut = pid->kp * dErrP + pid->ki * dErrI + pid->kd*dErrD;
	
//	printf("errNow=%f\r\n ctrOut=%f\r\n errold1=%f\r\n errold2=%f\r\n dCtrOut=%f\r\n",pid->errNow,pid->ctrOut,pid->errold1,pid->errold2,pid->dCtrOut);
	
	if(pid->kp==0&&pid->ki==0&&pid->kd==0)
		pid->ctrOut=0;
	else
		pid->ctrOut += pid->dCtrOut;
	if(pid->MaxOut != 0){
		if(pid->ctrOut > pid->MaxOut) pid->ctrOut = pid->MaxOut;
		if(pid->ctrOut < - pid->MaxOut) pid->ctrOut = -pid->MaxOut;
	}
}
/**********************************************/
void PID_AbsoluteMode(PID_AbsoluteType *pid) //绝对式PID控制
{
	pid->errP=pid->errNow;
	if(pid->errIPoint == 0){
		pid->errI += pid->errNow;
	}else{
		if(abs(pid->errNow) < abs(pid->errIPoint)){
			pid->errI += (pid->errIPoint - fabs(pid->errNow))/pid->errIPoint*pid->errNow;
		}
	}
	if(pid->errILim != 0)	
	{
		if(pid->errI >  pid->errILim)      pid->errI =  pid->errILim;
		else if(pid->errI < -pid->errILim) pid->errI = -pid->errILim;
	}

	pid->errD = pid->errNow-pid->errOld;
	if(abs(pid->errNow) < abs(pid->errDPoint)){
		pid->errD *= 0.1f;
	}
	pid->errOld =pid->errNow;
	pid->ctrOut = pid->kp*pid->errP + pid->ki * pid->errI + pid->kd*pid->errD;
	
	if(pid->MaxOut != 0){
		if(pid->ctrOut >  pid->MaxOut) pid->ctrOut =  pid->MaxOut;
		if(pid->ctrOut < -pid->MaxOut) pid->ctrOut = -pid->MaxOut;
	}
}


