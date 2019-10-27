#include "tools.h"
#include "time_module.h"
#include "display_module.h"

sbit KEY0_set_system = P3^0;
//sbit KEY1_set_alarm = P3^1;
sbit KEY2_add = P3^2;
sbit KEY3_sub = P3^3;

static uint KEY0_count;
//static uint KEY1_count;
static uint current_week;

static void KEY0_count_handle();
//static void KEY1_count_handle();
static void add();
static void sub();

void key_scan()
{
	if (KEY0_set_system == 0) {
		delayms(5);
		if (KEY0_set_system == 0) {
		 	while (!KEY0_set_system);
			//buzzer(100);
			KEY0_count_handle();
		}
	}
	if (KEY0_count != 0) {
		if (KEY2_add == 0) {
		      	delayms(5);
			if (KEY2_add == 0) {
				while (!KEY2_add);
				//buzzer(100);
				add();
			}
		}
		if (KEY3_sub == 0) {
			delayms(5);
			if (KEY3_sub == 0) {
			    	while (!KEY3_sub);
				//buzzer(100);
				sub();
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
		KEY0_count = 0;
		lcd_write_com(0x0c);
		TR0 = 1;
	}
}

static void add()
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
	case 4:
		system_day = ++system_day % month_day[system_month];
	       	lcd_update_bit(DAY_LCD_BIT, system_day);
		current_week = get_week(system_year, system_month, system_day);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(DAY_LCD_BIT + 2);
		break;
	case 5:
		if (++system_month == 13) system_month = 1; 
	       	lcd_update_bit(MONTH_LCD_BIT, system_month);
		current_week = get_week(system_year, system_month, system_day);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(MONTH_LCD_BIT + 2);
		break;
	case 6:
		++system_year;
	        lcd_update_year(YEAR_LCD_BIT, system_year);
		current_week = get_week(system_year, system_month, system_day);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(YEAR_LCD_BIT + 4);
		break; 	
	}
}
	
static void sub()
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
	case 4:
		if (system_day != 1) --system_day;
	       	lcd_update_bit(DAY_LCD_BIT, system_day);
		current_week = get_week(system_year, system_month, system_day);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(DAY_LCD_BIT + 2);
		break;
	case 5:
		if (system_month != 1) --system_month;
	       	lcd_update_bit(MONTH_LCD_BIT, system_month);
		current_week = get_week(system_year, system_month, system_day);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(MONTH_LCD_BIT + 2);
		break;
	case 6:
		if (system_year != 1970) --system_year;
	       	lcd_update_year(YEAR_LCD_BIT, system_year);
		current_week = get_week(system_year, system_month, system_day);
		lcd_update_week(WEEK_LCD_BIT, current_week);
		lcd_write_com(YEAR_LCD_BIT + 2);
		break;
	}
}