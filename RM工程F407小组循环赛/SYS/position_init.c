#include "main.h"

extern int32_t T_GRAB_POSITION;
extern int32_t T_LIFT_POSITION_R;

extern int32_t GRAB_POSITION;
extern int32_t LIFT_POSITION_R;

int grab_initialization=1;
int lift_initialization=1;

void GRAB_Position_Init(void){
/***************目标值初始化***************/
	if(grab_initialization==1){
	T_GRAB_POSITION=GRAB_POSITION;
	
		grab_initialization=0;

	}
}

void LIFT_Position_Init(void){
/***************目标值初始化***************/
	if(lift_initialization==1){
	T_LIFT_POSITION_R=LIFT_POSITION_R;
		
		lift_initialization=0;

	}
}
