#include "tools.h"
#include "display_module.h"
#include "time_module.h"

void lcd_init()
{
 	dula = 0;
	wela = 0;
	lcden = 0;

	lcd_write_com(0x38);	//����16*2��ʾ, 5*7����,8λ���ݽӿ�
	lcd_write_com(0x0c);   	//���ÿ���ʾ,����ʾ���
	lcd_write_com(0x06);  	//дһ���ַ�ָ���Զ���1
	lcd_write_com(0x01);   	//��ʾ��0,������0
}