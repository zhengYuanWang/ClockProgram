#include "tools.h"
#include "time_module.h"

//��ʼ������
void timer0_init()
{
   	TMOD = 0x01;		//������ʽ1
	TH0 = TH_50MS_INIT;	//��ֵ
	TL0 = TL_50MS_INIT;
	EA = 1;			//�����ж�
	ET0 = 1;		//����ʱ��0�ж�
	TR0 = 1;		//������ʱ��0
}