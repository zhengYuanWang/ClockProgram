#include "tools.h"
#include "display_module.h"

void lcd_update_bit(uchar wbit, uchar wdata) reentrant
{
	lcd_write_com(wbit);
	lcd_write_data(0x30 + wdata / 10);
	lcd_write_data(0x30 + wdata % 10);
}