#ifndef _H_TIME_MODULE
#define	_H_TIME_MODULE


#include "tools.h"

#define TH_50MS_INIT (65536 - 45872) / 256;
#define TL_50MS_INIT (65536 - 45872) % 256;

extern uint system_hour, system_minute, system_second;
extern uint system_year, system_month, system_day;

void timer0_init();
void time_handle();
void date_handle();


#endif