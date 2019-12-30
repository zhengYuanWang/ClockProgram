#include "tools.h"

void buzzer(uint xms)
{
	beep = 0;
	delayms(xms);
	beep = 1;	
}