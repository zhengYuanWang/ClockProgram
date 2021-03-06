/*
  	点亮选中的数码管(bit_select), 显示内容(part_select), 延时时长(xms)
*/

#include "tools.h"

#define S_LIM 0xff;	//消影

ucode encode[] = {
	 	0x3f, 0x06, 0x5b, 0x4f,	
		0x66, 0x6d, 0x7d, 0x07,
		0x7f, 0x6f, 0x77, 0x7c,
		0x39, 0x5e, 0x79, 0x71,
		0x80
};

ucode select[] = {
		0xfe, 0xfd, 0xfb, 0xf7,
		0xef, 0xdf, 0xc0, 0xff
};

void nixie_light_blink(uchar bit_select, uchar part_select)
{
	dula = 1;
	P0 = part_select;
	dula = 0;	 	

	P0 = S_LIM;

	wela = 1;
	P0 = bit_select;
	wela = 0;
}