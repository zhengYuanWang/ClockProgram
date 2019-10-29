#include "time_module.h"
#include "display_module.h"

static uint current_week;
extern uint KEY0_count;

void set_sub()
{
	switch (KEY0_count) {
 	case 1:
		if (system_second != 0) --system_second;
	       	lcd_update_bit(SECOND_LCD_BIT, system_second);
		lcd_write_com(SECOND_LCD_BIT + 2);
		break;
	case 2:
		if (system_minute != 0) --system_minute;
	       	lcd_update_bit(MINUTE_LCD_BIT, system_minute);
		lcd_write_com(MINUTE_LCD_BIT + 2);
		break;
	case 3:
		if (system_hour != 0) --system_hour;
	       	lcd_update_bit(HOUR_LCD_BIT, system_hour);
		lcd_write_com(HOUR_LCD_BIT + 2);
		break;
	case 4:
		if (system_day != 1) --system_day;
	       	lcd_update_bit(DAY_LCD_BIT, system_day);
		current_week = get_week(system_year, system_month, system_day);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(DAY_LCD_BIT + 2);
		break;
	case 5:
		if (system_month != 1) --system_month;
	       	lcd_update_bit(MONTH_LCD_BIT, system_month);
		current_week = get_week(system_year, system_month, system_day);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(MONTH_LCD_BIT + 2);
		break;
	case 6:
		if (system_year != 1970) --system_year;
	       	lcd_update_year(YEAR_LCD_BIT, system_year);
		current_week = get_week(system_year, system_month, system_day);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(YEAR_LCD_BIT + 2);
		break;
	}
}