#include "tools.h"
#include "display_module.h"
#include "time_module.h"

void lcd_init()
{
 	dula = 0;
	wela = 0;
	lcden = 0;

	lcd_write_com(0x38);	//设置16*2显示, 5*7点阵,8位数据接口
	lcd_write_com(0x0c);   	//设置开显示,不显示光标
	lcd_write_com(0x06);  	//写一个字符指针自动加1
	lcd_write_com(0x01);   	//显示清0,数据清0
}