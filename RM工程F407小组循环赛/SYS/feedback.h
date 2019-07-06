#ifndef __FEEDBACK_H__
#define __FEEDBACK_H__

#include "stm32f4xx.h"

void V_Back(int16_t FTL,int16_t FTR,int16_t FDL,int16_t FDR);
void VR_Back(int16_t FML,int16_t FMR,int16_t UNKNOWN1,int16_t UNKNOWN2);
void Action_Back(int16_t FliftL,int16_t FliftR,int16_t FGrab,int16_t FRotate);

#endif
