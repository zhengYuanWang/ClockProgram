#include "tools.h"
#include "display_module.h"
#include "time_module.h"			  

void lcd_update_bit(uchar wbit, uint wdata) reentrant
{
	lcd_write_com(wbit);
	lcd_write_data(0x30 + wdata / 10);
	lcd_write_data(0x30 + wdata % 10);
}

void lcd_update_year(uchar wbit, uint wdata) reentrant 
{
 	lcd_write_com(wbit);
	lcd_write_data(0x30 + wdata / 1000);
	wdata %= 1000;
	lcd_write_data(0x30 + wdata / 100);
	wdata %= 100;
	lcd_write_data(0x30 + wdata / 10);
	lcd_write_data(0x30 + wdata % 10);
}

void lcd_update_week(uchar wbit, uint wdata) reentrant
{
	uint count;
	lcd_write_com(wbit);
	for (count = 0; count < 3; ++count) {
		lcd_write_data(week[wdata][count]);
	}
}