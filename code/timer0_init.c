#include "tools.h"
#include "time_module.h"
#include "function_module.h"

//��ʼ������
void timer0_init()
{
   	TMOD = 0x01;		//������ʽ1
	TH0 = TH_50MS_INIT;	//��ֵ
	TL0 = TL_50MS_INIT;
	EA = 1;			//�����ж�
	ET0 = 1;		//����ʱ��0�ж�
	TR0 = 1;		//������ʱ��0

	systime->second = 58;
	systime->minute = 59;
	systime->hour = 23;
	systime->year = 2019;
	systime->month = 12;
	systime->day = 25;
	systime->week = get_week(systime->year, systime->month, systime->day);

	armtime->second = 0;
	armtime->minute = 0;
	armtime->hour = 0;
	armtime->year = 2019;
	armtime->month = 12;
	armtime->day = 26;
	armtime->week = get_week(armtime->year, armtime->month, armtime->day);
}