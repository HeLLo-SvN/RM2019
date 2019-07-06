#include "main.h"

extern int32_t F_LIFT_POSITION_L;
extern int32_t F_LIFT_POSITION_R;
extern int32_t F_GRAB_POSITION;
extern int32_t F_ROTATE_POSITION;

void Actionpid_Configuration()
{
	Liftpid_Configuration();
	Grabpid_Configuration();
	Rotatepid_Configuration();
	Action_Back((int16_t)F_LIFT_POSITION_L,(int16_t)F_LIFT_POSITION_R,(int16_t)F_GRAB_POSITION,(int16_t)F_ROTATE_POSITION);
}
