#include "BitMap.h"			//����ͷ�ļ�

static unsigned char code Heart0[] = {0x00,0x36,0x49,0x41,0x22,0x14,0x08,0x00};//����
static unsigned char code Heart1[] = {0x00,0x36,0x7f,0x7f,0x3e,0x1c,0x08,0x00};//ʵ��
static unsigned char code BLOCK0[] = {0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff};
static unsigned char code BLOCK1[] = {0xff,0x81,0xbd,0xa5,0xa5,0xbd,0x81,0xff};
static unsigned char code BLOCK2[] = {0xff,0xff,0xc3,0xc3,0xc3,0xc3,0xff,0xff};
volatile unsigned int BitMapTab[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};


void BitMap_Display()		//������ʾͼ��Ԥ����
{
	static unsigned char accept_count = 0;
	BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	accept_count++;
	if(accept_count > 8)
	{
		accept_count = 1;
	}
	P2 = BitMapTab[accept_count - 1];
	switch(accept_count)
	{
		case 1:BitMap1 = 1;break;
		case 2:BitMap2 = 1;break;
		case 3:BitMap3 = 1;break;
		case 4:BitMap4 = 1;break;
		case 5:BitMap5 = 1;break;
		case 6:BitMap6 = 1;break;
		case 7:BitMap7 = 1;break;
		case 8:BitMap8 = 1;break;
		default:break;
	}
}
void main_BitMap()		 //������ʾ�ܿ�
{
	unsigned char i ;
	static char trigger_BM = 0;
	if(trigger_KEY2)		//KEY2 trigger Check/����2�������
	{
		trigger_KEY2 = 0;
		trigger_BM++;
	}
	switch(trigger_BM)
	{
		//�л�Ϊ����
		case 1: 
		for(i=0;i<8;i++)
		{
			BitMapTab[i] = ~Heart1[i];
		}
		break;
		//�л�Ϊ����
		case 2:	
		for(i=0;i<8;i++)
		{
			BitMapTab[i] = ~BLOCK2[i];
		}
		break;
		//����Ϊ����
		case 3:trigger_BM = 1;break;
		default:break;
	}
}
void BitMap_Init()  //�����ʼ��
{
	P2M1 &= 0x00;
	P2M0 |= 0xff;
	
	P3M1 &= 0xfb;
	P3M0 |= 0x04;
	
	P4M1 &= 0xfd;
	P4M0 |= 0x02;
	
	P3M1 &= 0xf7;
	P3M0 |= 0x08;
	
	P3M1 &= 0xbf;
	P3M0 |= 0x40;
	
	P4M1 &= 0xef;
	P4M0 |= 0x10;
	
	P3M1 &= 0xef;
	P3M0 |= 0x10;
	
	P4M1 &= 0xfb;
	P4M0 |= 0x04;
	
	P3M1 &= 0xdf;
	P3M0 |= 0x20;
	
	P2 = 0x00;
	BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
}
