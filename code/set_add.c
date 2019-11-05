#include "time_module.h"
#include "display_module.h"

void set_add(uint count, uint status)
{
	uint current_week;	
	uint *year_p, *month_p, *day_p, *hour_p, *minute_p, *second_p;
	
	if (status == SYSTEM) {
	 	year_p		= &system_year;
		month_p	= &system_month;
		day_p		= &system_day;
		hour_p		= &system_hour;
		minute_p	= &system_minute;
		second_p	= &system_second;
	} else {
		year_p	 	= &alarm_year;
		month_p		= &alarm_month;
		day_p		= &alarm_day;
		hour_p		= &alarm_hour;
		minute_p	= &alarm_minute;
		second_p	= &alarm_second;
	}	

	switch (count) {
	case 1:
		*second_p = ++(*second_p) % 60;
	       	lcd_update_bit(SECOND_LCD_BIT, *second_p);
		lcd_write_com(SECOND_LCD_BIT + 2);
		break;
	case 2:
		*minute_p = ++(*minute_p) % 60;
	       	lcd_update_bit(MINUTE_LCD_BIT, *minute_p);
		lcd_write_com(MINUTE_LCD_BIT + 2);
		break;
	case 3:
		*hour_p = ++(*hour_p) % 60;
	       	lcd_update_bit(HOUR_LCD_BIT, *hour_p);
		lcd_write_com(HOUR_LCD_BIT + 2);
		break; 	
	case 4:
		*day_p = ++(*day_p) % (month_day[(*month_p) - 1] + 1);
		if (*day_p == 0) ++(*day_p);
	       	lcd_update_bit(DAY_LCD_BIT, *day_p);
		current_week = get_week(*year_p, *month_p, *day_p);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(DAY_LCD_BIT + 2);
		break;
	case 5:
		if (++(*month_p) == 13) *month_p = 1; 
	       	lcd_update_bit(MONTH_LCD_BIT, *month_p);
		current_week = get_week(*year_p, *month_p, *day_p);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(MONTH_LCD_BIT + 2);
		break;
	case 6:
		++(*year_p);
	        lcd_update_year(YEAR_LCD_BIT, *year_p);		
		current_week = get_week(*year_p, *month_p, *day_p);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(YEAR_LCD_BIT + 4);
		break; 	
	}
}