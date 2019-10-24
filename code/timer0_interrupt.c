#include "time_module.h"

uchar one_second;

void timer0() interrupt 1
{
	TH0 = TH_50MS_INIT;
	TL0 = TL_50MS_INIT;
	++one_second;

	time_handle();
}