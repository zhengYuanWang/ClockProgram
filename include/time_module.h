#ifndef _H_TIME_MODULE
#define	_H_TIME_MODULE


#include "tools.h"

typedef struct {
	uint year;
	uint month;
	uint day;
	uint week;

	uint hour;
	uint minute;
	uint second;
} time_struct; 

extern time_struct *systime; 

#define TH_50MS_INIT (65536 - 45872) / 256;
#define TL_50MS_INIT (65536 - 45872) % 256;

extern ucode week[7][4];
extern uint month_day[];

void timer0_init();
void time_handle();
void date_handle();
uint get_week(uint, uint, uint) reentrant;
void alarm_display();
void alarm_timeout();


#endif