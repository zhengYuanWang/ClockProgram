/*	
  	可选延时时长的延时函数:输入位所需延时毫秒数(unsigned int xms)
*/

#include "tools.h"

void delayms(uint xms)
{
	uint i, j;
	for (i = xms; i > 0; --i) {
		//执行空语句,时长约1ms
	 	for (j = 110; j > 0; --j);
	}
}