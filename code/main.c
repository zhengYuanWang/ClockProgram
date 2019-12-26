#include "tools.h"
#include "time_module.h"
#include "display_module.h"
#include "key_module.h"

sbit rd = P3^7;	

void main()
{
	timer0_init();		//定时器初始化
	lcd_init();		//LCD液晶屏初始化
	rd = 0;			//键盘扫描初始化

	while(TRUE) {
	    	system_display();
		key_scan();
	}
}