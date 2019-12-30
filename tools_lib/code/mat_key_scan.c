/*
  	矩阵键盘扫描程序		matrix_key_scan
	参数:事件函数的函数指针	void (*event_p)(uchar)	->	void event(uchar)	
*/

#include "tools.h"

uchar row_sel[] = { 0xfe, 0xfd, 0xfb, 0xf7 };
uchar col_sel[] = { 0xe0, 0xd0, 0xb0, 0x70 };

void mat_key_scan(void (*event_p)(uint))
{
	uchar temp;
	uint row, col, key;

	for (row = 0; row < 4; ++row) {
		P3 = row_sel[row];
		temp = P3;
		temp = temp & 0xf0;
		if (temp != 0xf0) {
		 	delayms(10);
			temp = P3;
			temp = temp & 0xf0;
			if (temp != 0xf0) {
				for (col = 0; col < 4; ++col) {
					if (temp == col_sel[col]) {
						key = row * 4 + col;
						while (temp != 0xf0) {
							temp = P3;
							temp = temp & 0xf0;
						}
						event_p(key);
						break;
					}
				}
			}
		}
	}
}