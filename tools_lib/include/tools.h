/*
	tools函数的头文件
*/

#ifndef _H_TOOLS
#define _H_TOOLS


#include "stc89c52.h"
#include <stdlib.h>

#define uint	unsigned int
#define uchar 	unsigned char
#define ucode	unsigned char code
#define TRUE	1
#define FALSE	0

//变量声明
extern ucode select[];		//选择哪个数码管: 0, 1, 2, 3, 4, 5, 全选, 消影
extern ucode encode[];		//选择显示的数	: 0, 1, 2, ... , f, 小数点	
extern uchar row_sel[];
extern uchar col_sel[];

sbit lcden	= P3^4;
sbit lcdrs 	= P3^5;
sbit dula 	= P2^6;
sbit wela	= P2^7;
sbit beep	= P2^3;

//函数声明

/*														  
 * 可选延时时长的延时函数:输入位所需延时毫秒数(unsigned int xms)
 */
void delayms(uint);	

/*
 * 点亮选中的数码管(bit_select), 显示内容(part_select)
 */
void nixie_light_blink(uchar, uchar);

/*
 * 矩阵键盘扫描程序	matrix_key_scan
 * 参数:事件函数的函数指针	void (*event_p)(uint)	->	void event(uint)	
 */
void mat_key_scan(void (*event_p)(uint));

/*
 * LCD写命令写数据
 * 注:课程设计需要,将开发板对LCD默认IO口P0->P1
 */
void lcd_write_com(uchar);
void lcd_write_data(uchar);

/*
 * 蜂鸣器
 */
void buzzer(uint);


#endif