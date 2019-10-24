#include "tools.h"
#include "time_module.h"
#include "display_module.h"
#include "key_module.h"

void main()
{
	timer0_init();		//定时器初始化
	lcd_init();		//LCD液晶屏初始化
	key_init();		//键盘输入初始化

	while (true) {
		key_scan();	//调用键盘扫描
	}	
}