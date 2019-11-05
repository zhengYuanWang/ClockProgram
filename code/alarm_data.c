#include "tools.h"
#include "display_module.h"
#include "time_module.h"

uint alarm_hour, alarm_minute, alarm_second;
uint alarm_year, alarm_month, alarm_day;

void alarm_display()
{
	uint current_week;

	lcd_update_year(YEAR_LCD_BIT, alarm_year);
       	lcd_update_bit(MONTH_LCD_BIT, alarm_month);
	lcd_update_bit(DAY_LCD_BIT, alarm_day);
	current_week = get_week(alarm_year, alarm_month, alarm_day);
	lcd_update_week(WEEK_LCD_BIT, current_week);
	lcd_update_bit(HOUR_LCD_BIT, alarm_hour);	
	lcd_update_bit(MINUTE_LCD_BIT, alarm_minute);
	lcd_update_bit(SECOND_LCD_BIT, alarm_second);	 	
}

void system_display()
{
	uint current_week;

	lcd_update_year(YEAR_LCD_BIT, system_year);
       	lcd_update_bit(MONTH_LCD_BIT, system_month);
	lcd_update_bit(DAY_LCD_BIT, system_day);
	current_week = get_week(system_year, system_month, system_day);
	lcd_update_week(WEEK_LCD_BIT, current_week);
	lcd_update_bit(HOUR_LCD_BIT, system_hour);	
	lcd_update_bit(MINUTE_LCD_BIT, system_minute);
	lcd_update_bit(SECOND_LCD_BIT, system_second);	 
}

void alarm_timeout()
{
	if (system_year == alarm_year && system_month == alarm_month && system_day == alarm_day) {
	 	if (system_hour == alarm_hour && system_minute == alarm_minute && system_second == alarm_second) {
			//buzzer(100);
		}
	} 
}