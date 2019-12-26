#include "tools.h"
#include "time_module.h"
#include "display_module.h"
#include "function_module.h"

sbit key_sys = P3^0;
sbit key_arm = P3^1;
sbit key_add = P3^2;
sbit key_sub = P3^3;

uint key_count = 0;
uint status = 0;

void add();
void sub();
void select_set();

void key_scan()
{
	if (key_sys == 0) {
		delayms(5);
		if (key_sys == 0) {
		 	while(!key_sys);
			status = 0;
			TR0 = 0;
			lcd_write_com(0x0f);
			while(TRUE) {		//循环检查是否按下其他键，唯一出口为设置完毕
				if (key_sys == 0) {
				   	delayms(5);
					if (key_sys == 0) {
					 	while (!key_sys);
						++key_count;
						select_set();
					}
				}
				if (key_add == 0) {
				  	delayms(5);
					if (key_add == 0) {
						while (!key_add);
					 	add();
						system_display();
						select_set();
					}
				} 
				if (key_sub == 0) {
				  	delayms(5);
					if (key_sub == 0) {
						while (!key_sub);
					      	sub();
						system_display();
						select_set();
					}
				}
				if (key_count == 6) {
					key_count = 0;
					lcd_write_com(0x0c);
					break;	//唯一出口
				}		
			}
			TR0 = 1;
		}
	}
	if (key_arm == 0) {
		delayms(5);
		if (key_arm == 0) {
		 	while(!key_arm);
			status = 1;
			lcd_write_com(0x0f);
			while(TRUE) {		//循环检查是否按下其他键，唯一出口为设置完毕
				if (key_arm == 0) {
				   	delayms(5);
					if (key_arm == 0) {
					 	while (!key_arm);
						++key_count;
						select_set();
					}
				}
				if (key_add == 0) {
				  	delayms(5);
					if (key_add == 0) {
						while (!key_add);
					 	add();
						alarm_display();
						select_set();
					}
				} 
				if (key_sub == 0) {
				  	delayms(5);
					if (key_sub == 0) {
						while (!key_sub);
					      	sub();
						alarm_display();
						select_set();
					}
				}
				if (key_count == 6) {
					key_count = 0;
					lcd_write_com(0x0c);
					break;	//唯一出口
				}		
			}
		}
	}
}

void select_set()
{
	switch (key_count) {
 	case 0:  
		lcd_write_com(SECOND_LCD_BIT + 2);
		break;
	case 1:
		lcd_write_com(MINUTE_LCD_BIT + 2);
		break;
	case 2:
		lcd_write_com(HOUR_LCD_BIT + 2);
		break;
	case 3:
		lcd_write_com(DAY_LCD_BIT + 2);
		break;
	case 4:
		lcd_write_com(MONTH_LCD_BIT + 2);
		break;
	case 5:
		lcd_write_com(YEAR_LCD_BIT + 4);
		break;
	}
}

void add()
{
	time_struct *current = systime;
	if (status == 1) {
	  	current = armtime;
	} 
	switch (key_count) {
	case 0:
		current->second = ++(current->second) % 60;
		break;
	case 1:
		current->minute = ++(current->minute) % 60;
		break;
	case 2:
		current->hour = ++(current->hour) % 24;
		break; 	
	case 3:
		current->day = ++(current->day) % (month_day[(current->month) - 1] + 1);
		if (current->day == 0) ++(current->day);
		break;
	case 4:
		if (++(current->month) == 13) current->month = 1; 
		break;
	case 5:
		++(current->year);
		break; 	
	}
}

void sub()
{
	time_struct *current = systime;
	if (status == 1) {
	  	current = armtime;
	} 
    	switch (key_count) {
 	case 0:
		if (current->second != 0) --(current->second);
		break;
	case 1:
		if (current->minute != 0) --(current->minute);
		break;
	case 2:
		if (current->hour != 0) --(current->hour);
		break;
	case 3:
		if (current->day != 1) --(current->day);
		break;
	case 4:
		if (current->month != 1) --(current->month);
		break;
	case 5:
		if (current->year != 1970) --(current->year);
		break;
	}
}