#include "tools.h"

void lcd_write_com(uchar com)
{
 	lcdrs = 0;	//����д����ģʽ
	//P0 = com;	//����д��P0
	P1 = com;
	delayms(5);	

	lcden = 1;	//��ʹ�ܶ˸����� 
	delayms(5);
	lcden = 0;	//��ɸ�����
}

void lcd_write_data(uchar wdata)
{
 	lcdrs = 1; 	//����д����ģʽ
	//P0 = wdata; 	//����д��P0
	P1= wdata;
	delayms(5);	

	lcden = 1;	
	delayms(5);
	lcden = 0;
}