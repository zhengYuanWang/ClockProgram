#include "tools.h"
#include "display_module.h"

uint month_day[] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
uchar week[7][4] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
uint system_year, system_month, system_day;
static uint current_week;

static uint is_bissextile(uint year)
{
	if ((year % 4 == 0 && year % 100 != 0)
		|| (year % 4 == 0)) {
	 	return true;
	} else 
		return false;
}

uint get_week(uint y, uint m, uint d) reentrant
{
	return (d + (2 * m) + (3 * (m + 1)) / 5 + y + (y / 4) - (y / 100) + (y / 400)) % 7;
}

void date_handle()
{
	if (is_bissextile(system_year)) {
		month_day[1] = 29;
	} else {
	 	month_day[1] = 28;
	}

	++system_day;
	if (system_day == month_day[system_month - 1] + 1) {
		system_day = 1;	

		++system_month;
		if (system_month == 12 + 1) {
			system_month = 1;
			
			++system_year;	
		}
		lcd_update_bit(MONTH_LCD_BIT, system_month);
		lcd_update_year(YEAR_LCD_BIT, system_year);
	}
	lcd_update_bit(DAY_LCD_BIT, system_day);

	current_week = get_week(system_year, system_month, system_day);
	lcd_update_week(WEEK_LCD_BIT, current_week);
}