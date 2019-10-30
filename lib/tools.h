/*
	tools������ͷ�ļ�
*/

#ifndef _H_TOOLS
#define _H_TOOLS


#include "stc89c52.h"

#define uint	unsigned int
#define uchar 	unsigned char
#define ucode	unsigned char code
#define TRUE	1
#define FALSE	0

//��������
extern ucode select[];		//ѡ���ĸ������: 0, 1, 2, 3, 4, 5, ȫѡ, ��Ӱ
extern ucode encode[];		//ѡ����ʾ����	: 0, 1, 2, ... , f, С����	
extern uchar row_sel[];
extern uchar col_sel[];

sbit lcden	= P3^4;
sbit lcdrs 	= P3^5;
sbit dula 	= P2^6;
sbit wela	= P2^7;
sbit beep	= P2^3;

//��������

/*														  
 * ��ѡ��ʱʱ������ʱ����:����λ������ʱ������(unsigned int xms)
 */
void delayms(uint);	

/*
 * ����ѡ�е������(bit_select), ��ʾ����(part_select)
 */
void nixie_light_blink(uchar, uchar);

/*
 * �������ɨ�����	matrix_key_scan
 * ����:�¼������ĺ���ָ��	void (*event_p)(uint)	->	void event(uint)	
 */
void mat_key_scan(void (*event_p)(uint));

/*
 * LCDд����д����	
 */
void lcd_write_com(uchar);
void lcd_write_data(uchar);

/*
 * ������
 */
void buzzer(uint);


#endif