#ifndef __GRABPID_H__
#define __GRABPID_H__

#include "stm32f4xx.h"

#define   ExGrabP     0.1
#define   ExGrabI     0
#define   ExGrabD     0
#define   InGrabP     3.5
#define   InGrabI     0.1
#define   InGrabD     0

void Grabpid_Init(void);
void Grabpid_Configuration(void);

#endif
