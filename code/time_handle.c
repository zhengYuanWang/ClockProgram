#include "time_module.h"
#include "display_module.h"

extern uint one_second;

uint system_hour, system_minute, system_second;

void time_handle() 
{
	if (one_second == 20){
		one_second = 0;		

		++system_second;
		if (system_second == 60) {
			system_second = 0;
		 	
			++system_minute;
			if (system_minute == 60) {
				system_minute = 0;
			 	
				++system_hour;
				if (system_hour == 24) {
				 	system_hour = 0;
					date_handle();
				}
				lcd_update_bit(HOUR_LCD_BIT, system_hour);
			}
			lcd_update_bit(MINUTE_LCD_BIT, system_minute);
		}
		lcd_update_bit(SECOND_LCD_BIT, system_second);
	}
}