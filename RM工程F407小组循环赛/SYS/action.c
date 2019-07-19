#include "main.h"

extern int32_t F_LIFT_POSITION_L;
extern int32_t F_LIFT_POSITION_R;
extern int32_t F_GRAB_POSITION;
extern int32_t F_ROTATE_POSITION;

void Actionpid_Configuration()
{
	Liftpid_Configuration();
	Grabpid_Configuration();
//	Rotatepid_Configuration();//总决赛取消基于电机的翻转弹药箱模式
	Action_Back((int16_t)F_LIFT_POSITION_L,(int16_t)F_LIFT_POSITION_R,(int16_t)F_GRAB_POSITION,(int16_t)F_ROTATE_POSITION);
}
