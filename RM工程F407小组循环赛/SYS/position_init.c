#include "main.h"

extern int32_t T_GRAB_POSITION;
extern int32_t T_ROTATE_POSITION;
extern int32_t T_LIFT_POSITION_R;

extern int32_t GRAB_POSITION;
extern int32_t ROTATE_POSITION;
extern int32_t LIFT_POSITION_R;



int initialization=1;

void Position_Init(void){
/***************目标值初始化***************/
	if(initialization==1){
//	T_GRAB_POSITION=GRAB_POSITION;
	T_ROTATE_POSITION=Rotate_Value5;
//	T_LIFT_POSITION_R=LIFT_POSITION_R;
		initialization=0;
	}
}
