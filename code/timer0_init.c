#include "tools.h"
#include "time_module.h"
#include "function_module.h"

//初始化函数
void timer0_init()
{
   	TMOD = 0x01;		//工作方式1
	TH0 = TH_50MS_INIT;	//初值
	TL0 = TL_50MS_INIT;
	EA = 1;			//开总中断
	ET0 = 1;		//开定时器0中断
	TR0 = 1;		//启动定时器0

	systime->second = 58;
	systime->minute = 59;
	systime->hour = 23;
	systime->year = 2019;
	systime->month = 12;
	systime->day = 25;
	systime->week = get_week(systime->year, systime->month, systime->day);

	armtime->second = 58;
	armtime->minute = 59;
	armtime->hour = 23;
	armtime->year = 2019;
	armtime->month = 12;
	armtime->day = 24;
	armtime->week = get_week(armtime->year, armtime->month, armtime->day);
}