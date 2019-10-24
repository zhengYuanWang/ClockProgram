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
	lcd_write_com(0x38);	//����16*2��ʾ, 5*7����,8λ���ݽӿ�
	lcd_write_com(0x0c);   	//���ÿ���ʾ,����ʾ���
	lcd_write_com(0x06);  	//дһ���ַ�ָ���Զ���1
	lcd_write_com(0x01);   	//��ʾ��0,������0

	lcd_write_com(0x80 + 0x01);
	for (count = 0; count < 14; ++count) {
		lcd_write_data(date_init[count]);
	}

	lcd_write_com(0x80 + 0x44);
	for (count = 0; count < 8; ++count) {
		lcd_write_data(time_init[count]);
	}
}