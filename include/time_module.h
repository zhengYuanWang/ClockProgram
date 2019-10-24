#ifndef _H_TIME_MODULE
#define	_H_TIME_MODULE


#include "tools.h"

#define TH_50MS_INIT (65536 - 45872) / 256;
#define TL_50MS_INIT (65536 - 45872) % 256;

extern uchar system_hour, system_minute, system_second;

void timer0_init();
void time_handle();


#endif