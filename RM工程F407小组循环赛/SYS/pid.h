#ifndef __PID_H__
#define __PID_H__


/********increase mode*******/
typedef  struct
{
	float kp;
	float ki;
	float kd;
	
	float errNow;
	float dCtrOut;
	float ctrOut;
	
	float errold1;
	float errold2;
	
	float MaxOut;

}PID_IncrementType;
/******* absolute mode********/
typedef struct
{
	float kp;
	float ki;
	float kd;	
	float errILim;
	float errNow; 
	float ctrOut;
	float errOld;
	float errP;
	float errI;
	float errD;
	float MaxOut;
	
	float errIPoint;
	float errDPoint;
	
}PID_AbsoluteType;


void PID_IncrementMode(PID_IncrementType *);        //增量式pid函数
void PID_AbsoluteMode(PID_AbsoluteType *);					//位置式pid函数
#endif
