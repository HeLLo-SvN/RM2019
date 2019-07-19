#include "main.h"

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

extern PID_AbsoluteType topleft;
extern PID_AbsoluteType topright;
extern PID_AbsoluteType downleft;
extern PID_AbsoluteType downright;
extern PID_AbsoluteType midleft;
extern PID_AbsoluteType midright;

extern int32_t T_GRAB_POSITION;
extern int16_t B_P_GRAB;
extern int32_t GRAB_POSITION;
extern int16_t B_V_GRAB;

extern PID_AbsoluteType grab_Ex;
extern PID_AbsoluteType grab_In;

extern int32_t T_LIFT_POSITION_L;
extern int16_t B_P_LIFT_L;
extern int32_t LIFT_POSITION_L;
extern int16_t B_V_LIFT_L;

extern int32_t T_LIFT_POSITION_R;
extern int16_t B_P_LIFT_R;
extern int32_t LIFT_POSITION_R;
extern int16_t B_V_LIFT_R;

extern PID_AbsoluteType lift_L_Ex;
extern PID_AbsoluteType lift_L_In;

extern PID_AbsoluteType lift_R_Ex;
extern PID_AbsoluteType lift_R_In;

extern int32_t T_ROTATE_POSITION;
extern int16_t B_P_ROTATE;
extern int32_t ROTATE_POSITION;
extern int16_t B_V_ROTATE;

extern PID_AbsoluteType rotate_Ex;
extern PID_AbsoluteType rotate_In;

extern int32_t F_LIFT_POSITION_L;
extern int32_t F_LIFT_POSITION_R;

extern int32_t F_GRAB_POSITION;

extern int First;
extern int Double;
extern int Triple;

extern int Grab_Condition;

extern int touch_switch;

extern int times;

extern RC_Ctl_t RC_Ctl;

extern int high_Trigger;

extern int grab_baseline;

extern PID_AbsoluteType  gyro_Angle;

extern float B_GYRO_ANGLE;
extern float INSTANTANEOUS;

void Print_Test(void){

/************************µ×ÅÌ²âÊÔ************************/	
//	printf("targetTL=%d\r\n",T_TOP_L);
//	printf("targetTR=%d\r\n",T_TOP_R);
//	printf("targetDL=%d\r\n",T_DOWN_L);
//	printf("targetDR=%d\r\n",T_DOWN_R);
//	printf("targetML=%d\r\n",T_MID_L);
//	printf("targetMR=%d\r\n",T_MID_R);
//	
//	printf("feedbackTL=%d\r\n",B_TOP_L);
//	printf("feedbackTR=%d\r\n",B_TOP_R);
//	printf("feedbackDL=%d\r\n",B_DOWN_L);
//	printf("feedbackDR=%d\r\n",B_DOWN_R);
//	printf("feedbackML=%d\r\n",B_MID_L);
//	printf("feedbackMR=%d\r\n",B_MID_R);
//	
//	printf("topleft.errNow=%f\r\n",topleft.errNow);
//	printf("topright.errNow=%f\r\n",topright.errNow);
//	printf("downleft.errNow=%f\r\n",downleft.errNow);
//	printf("downright.errNow=%f\r\n",downright.errNow);
//	printf("midleft.errNow=%f\r\n",midleft.errNow);
//	printf("midright.errNow=%f\r\n",midright.errNow);
//	
//	printf("topleft.ctrOut=%f\r\n",topleft.ctrOut);
//	printf("topright.ctrOut=%f\r\n",topright.ctrOut);
//	printf("downleft.ctrOut=%f\r\n",downleft.ctrOut);
//	printf("downright.ctrOut=%f\r\n",downright.ctrOut);
//	printf("midleft.ctrOut=%f\r\n",midleft.ctrOut);
//	printf("midright.ctrOut=%f\r\n",midright.ctrOut);
/************************×¥È¡²âÊÔ************************/
//	printf("targetTG=%d\r\n",T_GRAB_POSITION);
//	
//	printf("feedbackP1=%d\r\n",B_P_GRAB);
//  printf("feedbackP2=%d\r\n",GRAB_POSITION);
//	printf("feedbackV=%d\r\n",B_V_GRAB);
//	printf("IN.errNow=%f\r\n",grab_In.errNow);
//		
//	printf("grab_Ex.ctrOut=%f\r\n",grab_Ex.ctrOut);
//	printf("grab_In.ctrOut=%f\r\n",grab_In.ctrOut);
//	
//	printf("F_GRAB_POSITION=%d\r\n",F_GRAB_POSITION);
/************************Éý½µ²âÊÔ************************/		
//--	printf("targetTL=%d\r\n",T_LIFT_POSITION_L);
	printf("targetTR=%d\r\n",T_LIFT_POSITION_R);
	
	printf("feedbackPL1=%d\r\n",B_P_LIFT_L);
	printf("feedbackPL2=%d\r\n",LIFT_POSITION_L);
	printf("feedbackVL=%d\r\n",B_V_LIFT_L);
		
	printf("feedbackPR1=%d\r\n",B_P_LIFT_R);
	printf("feedbackPR2=%d\r\n",LIFT_POSITION_R);
	printf("feedbackVR=%d\r\n",B_V_LIFT_R);
	
////--	printf("LeftEx.errNow=%f\r\n",lift_L_Ex.errNow);
////--    printf("LeftIn.errNow=%f\r\n",lift_L_In.errNow);

	printf("RightEx.errNow=%f\r\n",lift_R_Ex.errNow);
    printf("RightIn.errNow=%f\r\n",lift_R_In.errNow);

////--	printf("lift_L_Ex.ctrOut=%f\r\n",lift_L_Ex.ctrOut);
////--	printf("lift_L_In.ctrOut=%f\r\n",lift_L_In.ctrOut);
	
	printf("lift_R_Ex.ctrOut=%f\r\n",lift_R_Ex.ctrOut);
	printf("lift_R_In.ctrOut=%f\r\n",lift_R_In.ctrOut);
	
	printf("F_LIFT_POSITION_R=%d\r\n",F_LIFT_POSITION_R);
	printf("F_LIFT_POSITION_L=%d\r\n",F_LIFT_POSITION_L);
	
/************************·­×ª²âÊÔ************************/	//×Ü¾öÈüÈ¡Ïû´Ë¹¦ÄÜ
//  printf("targetTRo=%d\r\n",T_ROTATE_POSITION);
//	
//	printf("feedbackP1=%d\r\n",B_P_ROTATE);
//	printf("feedbackP2=%d\r\n",ROTATE_POSITION);
//	printf("feedbackV=%d\r\n",B_V_ROTATE);
//		
//	printf("EX.errNow=%f\r\n",rotate_Ex.errNow);
//	printf("IN.errNow=%f\r\n",rotate_In.errNow);
//		
//	printf("rotate_Ex.ctrOut=%f\r\n",rotate_Ex.ctrOut);
//	printf("rotate_In.ctrOut=%f\r\n",rotate_In.ctrOut);
/***********************´¥Åö¿ª¹Ø²âÊÔ***********************/
//    printf("testing=%d\r\n",touch_switch);
/***********************Keyence²âÊÔ***********************/
//  printf("testing=%d\r\n",Keyence);
/************************Æø¸×²âÊÔ************************/
//  printf("testing=%f\r\n",Booleans);
/************************ÖÆ¶¯²âÊÔ************************/
//    printf("Grab_Condition=%d\r\n",Grab_Condition);
//    printf("First=%d\r\n",First);
//	  printf("Double=%d\r\n",Double);
//	  printf("Triple=%d\r\n",Triple);
//	  printf("times=%d\r\n",times);
/************************Ò£¿Ø²âÊÔ************************/
//    printf("Keyboard_Value=%d\r\n",RC_Ctl.key.v);
//    printf("Mouse_X_Value=%d\r\n",RC_Ctl.mouse.x);
//	  printf("Mouse_Y_Value=%d\r\n",RC_Ctl.mouse.y);
//	  printf("Mouse_Z_Value=%d\r\n",RC_Ctl.mouse.z);
/************************ÆÁÄ»²âÊÔ************************/
//    printf("high_Trigger=%d\r\n",high_Trigger);
/************************×Ô¼ì²âÊÔ************************/
//    printf("grab_baseline=%d\r\n",grab_baseline);
/*********************ÍÓÂÝÒÇ½Ç¶È²âÊÔ*********************/
//    printf("INSTANTANEOUS=%f\r\n",INSTANTANEOUS);
//    printf("B_GYRO_ANGLE=%f\r\n",B_GYRO_ANGLE);
//	  
//	  printf("ANGLE.errNow=%f\r\n",gyro_Angle.errNow);
//	  printf("F_GYRO_ANGLE=%f\r\n",gyro_Angle.ctrOut);
	  
}
