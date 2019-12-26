#ifndef _H_DISPALY_MODULE
#define	_H_DISPALY_MODULE


#define YEAR_LCD_BIT	0x80 + 1	
#define MONTH_LCD_BIT	0x80 + 6
#define DAY_LCD_BIT	0x80 + 9
#define WEEK_LCD_BIT	0x80 + 12
#define	HOUR_LCD_BIT 	0x80 + 0x40 + 4
#define	MINUTE_LCD_BIT	0x80 + 0x40 + 7
#define SECOND_LCD_BIT	0x80 + 0x40 + 10

void lcd_update_bit(uchar, uint) reentrant;
void lcd_update_year(uchar, uint) reentrant;
void lcd_update_week(uchar, uint) reentrant;
void lcd_init();
void system_display();
void alarm_display();


#endif