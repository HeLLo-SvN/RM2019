#ifndef __LIFTPID_H__
#define __LIFTPID_H__

#include "stm32f4xx.h"

#define   ExLiftP     0.05
#define   ExLiftI     0
#define   ExLiftD     0
#define   InLiftP     4
#define   InLiftI     0.1
#define   InLiftD     0

void Liftpid_Init(void);
void Liftpid_Configuration(void);

#endif
