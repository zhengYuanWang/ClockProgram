#include "tools.h"
#include "time_module.h"
#include "display_module.h"

sbit KEY0 = P3^0;
sbit KEY1 = P3^1;
sbit KEY2 = P3^2;

static uint KEY0_count;

static void KEY0_count_handle();
static void add_time();
static void sub_time();

void key_scan()
{
 	if (KEY0 == 0) {
		delayms(5);
		if (KEY0 == 0) {
			while (!KEY0);
			buzzer(100);
			KEY0_count_handle();
		}
	}
	if (KEY0_count != 0) {
		if (KEY1 == 0) {
			delayms(5);
			if (KEY1 == 0) {
			    	while (!KEY1);
				buzzer(100);
				add_time();
			}
		}
		if (KEY2 == 0) {
			delayms(5);
			if (KEY2 == 0) {
			    	while (!KEY2);
				buzzer(100);
				sub_time();
			}
		}
	}
}

static void KEY0_count_handle()
{
	++KEY0_count;
	switch (KEY0_count) {
	case 1:
		TR0 = 0;
		lcd_write_com(0x80 + 0x52);
		lcd_write_com(0x0f);
		lcd_update_bit(SECOND_LCD_BIT, system_second);
		break;
	case 2:
		lcd_write_com(0x80 + 0x49);
		break;
	case 3:
		lcd_write_com(0x80 + 0x46);
		break;
	case 4:
		KEY0_count = 0;
		lcd_write_com(0x0c);
		TR0 = 1;
	}
}

static void add_time()
{
 	switch (KEY0_count) {
	case 1:
		system_second = ++system_second % 60;
	       	lcd_update_bit(SECOND_LCD_BIT, system_second);
		lcd_write_com(SECOND_LCD_BIT + 2);
		break;
	case 2:
		system_minute = ++system_minute % 60;
	       	lcd_update_bit(MINUTE_LCD_BIT, system_minute);
		lcd_write_com(MINUTE_LCD_BIT + 2);
		break;
	case 3:
		system_hour = ++system_hour % 60;
	       	lcd_update_bit(HOUR_LCD_BIT, system_hour);
		lcd_write_com(HOUR_LCD_BIT + 2);
		break; 	
	}
}

static void sub_time()
{
	switch (KEY0_count) {
	case 1:
		if (system_second != 0) --system_second;
	       	lcd_update_bit(SECOND_LCD_BIT, system_second);
		lcd_write_com(SECOND_LCD_BIT + 2);
		break;
	case 2:
		if (system_minute != 0) --system_minute;
	       	lcd_update_bit(MINUTE_LCD_BIT, system_minute);
		lcd_write_com(MINUTE_LCD_BIT + 2);
		break;
	case 3:
		if (system_hour != 0) --system_hour;
	       	lcd_update_bit(HOUR_LCD_BIT, system_hour);
		lcd_write_com(HOUR_LCD_BIT + 2);
		break; 	
	}
}