#include "time_module.h"
#include "display_module.h"

extern uint one_second;	   

time_struct system_time;
time_struct *systime = &system_time;

uint month_day[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ucode week[7][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};

void time_handle() 
{
	if (one_second == 20){
		one_second = 0;		

		++systime->second;
		if (systime->second == 60) {
			systime->second = 0;
		 	
			++systime->minute;
			if (systime->minute == 60) {
				systime->minute = 0;
			 	
				++systime->hour;
				if (systime->hour == 24) {
				 	systime->hour = 0;
					date_handle();
				}
			}
		}
	}
}

static uint is_bissextile(uint year)
{
	if ((year % 4 == 0 && year % 100 != 0)
		|| (year % 4 == 0)) {
	 	return TRUE;
	} else 
		return FALSE;
}

uint get_week(uint y, uint m, uint d) reentrant
{
	return (d + (2 * m) + (3 * (m + 1)) / 5 + 
			y + (y / 4) - (y / 100) + (y / 400)) % 7;
}

void date_handle()
{
	if (is_bissextile(systime->year)) {
		month_day[1] = 29;
	} else {
	 	month_day[1] = 28;
	}

	++systime->day;
	if (systime->day == month_day[systime->month - 1] + 1) {
		systime->day = 1;	

		++systime->month;
		if (systime->month == 12 + 1) {
			systime->month = 1;
			
			++systime->year;	
		}
	}
	systime->week = get_week(systime->year, systime->month, systime->day);
}