#include "tools.h"
#include "display_module.h"

void lcd_init()
{
	uint count;
	ucode date_init[] = "2019-10-23 THU";
	ucode time_init[] = "00:00:00";
	
 	dula = 0;
	wela = 0;
	lcden = 0;
	lcd_write_com(0x38);	//设置16*2显示, 5*7点阵,8位数据接口
	lcd_write_com(0x0c);   	//设置开显示,不显示光标
	lcd_write_com(0x06);  	//写一个字符指针自动加1
	lcd_write_com(0x01);   	//显示清0,数据清0

	lcd_write_com(0x80 + 0x01);
	for (count = 0; count < 14; ++count) {
		lcd_write_data(date_init[count]);
	}

	lcd_write_com(0x80 + 0x44);
	for (count = 0; count < 8; ++count) {
		lcd_write_data(time_init[count]);
	}
}