#include "tools.h"

void lcd_write_com(uchar com)
{
 	lcdrs = 0;	//进入写命令模式
	//P0 = com;	//命令写入P0
	P1 = com;
	delayms(5);	

	lcden = 1;	//给使能端高脉冲 
	delayms(5);
	lcden = 0;	//完成高脉冲
}

void lcd_write_data(uchar wdata)
{
 	lcdrs = 1; 	//进入写数据模式
	//P0 = wdata; 	//数据写入P0
	P1= wdata;
	delayms(5);	

	lcden = 1;	
	delayms(5);
	lcden = 0;
}