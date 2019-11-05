#include "tools.h"
#include "time_module.h"
#include "display_module.h"
#include "key_module.h"

sbit KEY0_set_system = P3^0;
sbit KEY1_set_alarm = P3^1;
sbit KEY2_add = P3^2;
sbit KEY3_sub = P3^3;

uint KEY0_count;
uint KEY1_count;
uint *KEY0_count_p = &KEY0_count;
uint *KEY1_count_p = &KEY1_count;

static void KEY_count_handle(uint*);
static void add_sub_select(uint, uint);

void key_scan()
{
	if (KEY0_set_system == 0) {
		delayms(5);
		if (KEY0_set_system == 0) {
		 	while (!KEY0_set_system);
			//buzzer(100);
			KEY1_count = 0;
			system_display();
			KEY_count_handle(KEY0_count_p);
		}
	}
	if (KEY1_set_alarm == 0) {
		delayms(5);
		if (KEY1_set_alarm == 0) {
		 	while (!KEY1_set_alarm);
			//buzzer(100);
			KEY0_count = 0;
			alarm_display();
			KEY_count_handle(KEY1_count_p);
		}
	}
	if (KEY0_count != 0) {
		add_sub_select(KEY0_count, SYSTEM);
	}
	if (KEY1_count != 0) {
	 	add_sub_select(KEY1_count, ALARM);
	}
}

static void add_sub_select(uint count, uint status)
{
	if (KEY2_add == 0) {
	      	delayms(5);
		if (KEY2_add == 0) {
			while (!KEY2_add);
			//buzzer(100);
			set_add(count, status);
		}
	}				     
	if (KEY3_sub == 0) {
		delayms(5);
		if (KEY3_sub == 0) {
		    	while (!KEY3_sub);
			//buzzer(100);
			set_sub(count, status);
		}
	}
}

static void KEY_count_handle(uint *count)
{
	++(*count);
	switch (*count) {
	case 1:
		TR0 = 0;   
		lcd_write_com(0x0f);
		lcd_write_com(SECOND_LCD_BIT + 2);
		break;
	case 2:
		lcd_write_com(MINUTE_LCD_BIT + 2);
		break;
	case 3:
		lcd_write_com(HOUR_LCD_BIT + 2);
		break;
	case 4:
		lcd_write_com(DAY_LCD_BIT + 2);
		break;
	case 5:
		lcd_write_com(MONTH_LCD_BIT + 2);
		break;
	case 6:
		lcd_write_com(YEAR_LCD_BIT + 4);
		break;
	case 7:
		*count = 0;
		lcd_write_com(0x0c);
		system_display();
		TR0 = 1;
	}
}