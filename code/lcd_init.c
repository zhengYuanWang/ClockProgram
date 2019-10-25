#include "tools.h"
#include "display_module.h"
#include "time_module.h"

void lcd_init()
{
	uint count;
	ucode date_init[] = "2008-04-28 Fri";
	ucode time_init[] = "23:59:58";
	system_second = 58;
	system_minute = 59;
	system_hour = 23;
	system_year = 2008;
	system_month = 4;
	system_day = 28;
	
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