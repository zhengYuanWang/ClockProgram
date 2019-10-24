#include "stc89c52.h"

sbit rd = P3^7;

void key_init()
{
	rd = 0;
}