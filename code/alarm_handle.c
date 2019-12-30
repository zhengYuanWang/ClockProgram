#include "tools.h"
#include "display_module.h"
#include "time_module.h"

time_struct alarm_time;
time_struct *armtime = &alarm_time;

void alarm_display()
{
	lcd_update_year(YEAR_LCD_BIT, armtime->year); lcd_write_data('-');
       	lcd_update_bit(MONTH_LCD_BIT, armtime->month); lcd_write_data('-');
	lcd_update_bit(DAY_LCD_BIT, armtime->day);
	armtime->week = get_week(armtime->year, armtime->month, armtime->day);
	lcd_update_week(WEEK_LCD_BIT, armtime->week);
	lcd_update_bit(HOUR_LCD_BIT, armtime->hour); lcd_write_data(':');	
	lcd_update_bit(MINUTE_LCD_BIT, armtime->minute); lcd_write_data(':');
	lcd_update_bit(SECOND_LCD_BIT, armtime->second);	 
}

void time_out()
{
	if (armtime->year == systime->year
		&& armtime->month == systime->month
		&& armtime->day == systime->day
		&& armtime->hour == systime->hour
		&& armtime->minute == systime->minute
		&& armtime->second == systime->second) {
		buzzer(1000);
	}
}