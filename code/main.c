#include "tools.h"
#include "time_module.h"
#include "display_module.h"
#include "key_module.h"

sbit rd = P3^7;

void main()
{
	timer0_init();		//��ʱ����ʼ��
	lcd_init();		//LCDҺ������ʼ��
	rd = 0;

	while (TRUE) {
		key_scan();	//���ü���ɨ��
	}	
}