/*	
  	��ѡ��ʱʱ������ʱ����:����λ������ʱ������(unsigned int xms)
*/

#include "tools.h"

void delayms(uint xms)
{
	uint i, j;
	for (i = xms; i > 0; --i) {
		//ִ�п����,ʱ��Լ1ms
	 	for (j = 110; j > 0; --j);
	}
}