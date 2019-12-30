#include "tools.h"
#include "time_module.h"
#include "display_module.h"
#include "key_module.h"
#include "function_module.h"

sbit rd = P3^7;	

void main()
{
	timer0_init();		//��ʱ����ʼ��
	lcd_init();		//LCDҺ������ʼ��
	rd = 0;			//����ɨ���ʼ��

	while(TRUE) {
	    	system_display();
		key_scan();
		time_out();
	}
}