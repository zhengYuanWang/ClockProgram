#include "tools.h"
#include "time_module.h"
#include "display_module.h"
#include "key_module.h"

void main()
{
	timer0_init();		//��ʱ����ʼ��
	lcd_init();		//LCDҺ������ʼ��
	key_init();		//���������ʼ��

	while (true) {
		key_scan();	//���ü���ɨ��
	}	
}