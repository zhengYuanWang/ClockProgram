#ifndef _H_DISPALY_MODULE
#define	_H_DISPALY_MODULE


#define	HOUR_LCD_BIT 	0x80 + 0x40 + 4
#define	MINUTE_LCD_BIT	0x80 + 0x40 + 7
#define SECOND_LCD_BIT	0x80 + 0x40 + 10	

void lcd_update_bit(uchar, uchar) reentrant;
void lcd_init();


#endif