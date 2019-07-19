#ifndef __MAIN_H__
#define __MAIN_H__

#include "stm32f4xx.h"

#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include "delay.h"
#include "led.h"
#include "usart6.h"
#include "usart1.h"
#include "STMGood.h"
#include "can1.h"
#include "wheel.h"
#include "pid.h"
#include "tim7.h"
#include "chassispid.h"
#include "feedback.h"
#include "rc_init.h"
#include "can2.h"
#include "liftpid.h"
#include "grabpid.h"
#include "rotatepid.h"
#include "tim6.h"
#include "touch_switch.h"
#include "air_cylinder.h"
#include "action.h"
#include "keyence.h"
#include "end_of.h"
#include "keyboard_value.h"
#include "screen.h"
#include "testing.h"
#include "print.h"
#include "usart2.h"
#include "servo.h"
#include "rescue.h"
#include "to_hero.h"
#include "grab_check.h"
#include "position_init.h"
#include "quit_mode.h"
#include "get_mode1.h"
#include "get_mode2.h"
#include "get_mode3.h"
#include "gyropid.h"
#include "straight_angle.h"
#include "self_checking.h"

#define Lift_R_Value1 -300000//����һ���߶�
#define Lift_R_Value2 -450000//�ٴ�����һ���߶�
#define Lift_R_Value3 -5000//��λ
#define Grab_Value1 43000   //����
#define Grab_Value2 94000   //ȡ��
#define Grab_Value3 5000    //��λ
/*�ܾ�����������ҩ�䲿�ָ�Ϊ���׽ṹ*/
/*ȡ���������л��ڵ���ṹ�Ļ��崦��*/
//#define Rotate_Value1 -25000    //������ҩ��
//#define Rotate_Value2 -15000       //���帴λ
//#define Rotate_Value3 -10000
//#define Rotate_Value4 -5000
//#define Rotate_Value5 1500        //0

#endif
