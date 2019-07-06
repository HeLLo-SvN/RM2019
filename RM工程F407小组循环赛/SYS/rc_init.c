#include "main.h"

extern RC_Ctl_t RC_Ctl;

void Remote_Init(void)
{
	memset(&RC_Ctl,0,sizeof(RC_Ctl_t));
	RC_Ctl.rc.ch0 = 1024;
	RC_Ctl.rc.ch1 = 1024;
	RC_Ctl.rc.ch2 = 1024;
	RC_Ctl.rc.ch3 = 1024;
}





