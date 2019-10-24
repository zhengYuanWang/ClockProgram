#include "tools.h"
#include "time_module.h"

//初始化函数
void timer0_init()
{
   	TMOD = 0x01;		//工作方式1
	TH0 = TH_50MS_INIT;	//初值
	TL0 = TL_50MS_INIT;
	EA = 1;			//开总中断
	ET0 = 1;		//开定时器0中断
	TR0 = 1;		//启动定时器0
}