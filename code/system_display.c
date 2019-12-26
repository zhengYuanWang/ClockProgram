#include "tools.h"
#include "display_module.h"
#include "time_module.h"

void system_display()
{
	lcd_update_year(YEAR_LCD_BIT, systime->year); lcd_write_data('-');
       	lcd_update_bit(MONTH_LCD_BIT, systime->month); lcd_write_data('-');
	lcd_update_bit(DAY_LCD_BIT, systime->day);
	lcd_update_week(WEEK_LCD_BIT, systime->week);
	lcd_update_bit(HOUR_LCD_BIT, systime->hour); lcd_write_data(':');	
	lcd_update_bit(MINUTE_LCD_BIT, systime->minute); lcd_write_data(':');
	lcd_update_bit(SECOND_LCD_BIT, systime->second);	 
}