#include "BitMap.h"

static unsigned char code Heart0[] = {0x00,0x36,0x49,0x41,0x22,0x14,0x08,0x00};//空心
static unsigned char code Heart1[] = {0x00,0x36,0x7f,0x7f,0x3e,0x1c,0x08,0x00};//实心
static unsigned char code BLOCK[] = {0xff,0x81,0x81,0x81,0x81,0x81,0x81,0xff};
static unsigned char code NUM0[] = {0x0e,0x11,0x13,0x15,0x19,0x11,0x0e,0x00};
static unsigned char code NUM1[] = {0x04,0x0c,0x04,0x04,0x04,0x04,0x1f,0x00};
static unsigned char code NUM2[] = {0x0e,0x11,0x01,0x06,0x08,0x10,0x1f,0x00};
static unsigned char code NUM3[] = {0x0e,0x11,0x01,0x06,0x01,0x11,0x0e,0x00};
static unsigned char code NUM4[] = {0x03,0x05,0x09,0x11,0x1f,0x01,0x01,0x00};
static unsigned char code NUM5[] = {0x1f,0x10,0x1e,0x01,0x01,0x11,0x0e,0x00};
static unsigned char code NUM6[] = {0x0e,0x11,0x10,0x1e,0x11,0x11,0x0e,0x00};
static unsigned char code NUM7[] = {0x1f,0x11,0x01,0x02,0x04,0x04,0x04,0x00};
static unsigned char code NUM8[] = {0x0e,0x11,0x11,0x0e,0x11,0x11,0x0e,0x00};
static unsigned char code NUM9[] = {0x0e,0x11,0x11,0x0f,0x01,0x02,0x0c,0x00};
volatile unsigned int BitMapTab[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};


void BitMap_Display()		
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
void main_BitMap()
{
	//static unsigned int COUNT_BM = 0;
				 unsigned char i ;
	static char trigger_BM = 0;
	if(trigger_KEY2)
	{
		trigger_KEY2 = 0;
		trigger_BM++;
	}
//	if(trigger_KEY1)
//	{
//		trigger_KEY1 = 0;
//		trigger_BM = 0;
//	}
	switch(trigger_BM)
	{
		case 1:
		for(i=0;i<8;i++)
		{
			BitMapTab[i] = ~Heart0[i];
		}
		break;
		
		case 2:
		for(i=0;i<8;i++)
		{
			BitMapTab[i] = ~BLOCK[i];
		}
		break;
	
		case 3:trigger_BM = 1;break;
		default:break;
	}

}
/*void BitMap()
{
	static unsigned int COUNT_BM = 0;
				 unsigned char i ;
	static bit trigger_BM = 0;
		COUNT_BM++;
if(COUNT_BM >= 1000)
{
	COUNT_BM = 0;
	trigger_BM = !trigger_BM;
}
	if(trigger_BM)										//触发器检测
	{
		for(i=0;i<8;i++)									//空心
		{
		BitMapTab[i] = ~Heart0[i] ;
		}
	}
	else
	{
		for(i=0;i<8;i++)									//实心
		{
		BitMapTab[i] = ~BLOCK[i] ;
		}
	}
}
void BitMap()
{
	static unsigned int COUNT_BM = 0;
				 unsigned char i ;
	static unsigned trigger_BM = 0;
		COUNT_BM++;
if(COUNT_BM >= 1000)
{
	COUNT_BM = 0;
	trigger_BM ++;
}
	switch(trigger_BM)
	{
	  	//BieMap Show Number-0
		case 0:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM0[i] ;
		}
		break;
	  	//BieMap Show Number-1
		case 1:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM1[i] ;
		}
		break;
		  //BieMap Show Number-2
		case 2:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM2[i] ;
		}
		break;
	  	//BieMap Show Number-3
		case 3:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM3[i] ;
		}
		break;
	 	 //BieMap Show Number-4
		case 4:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM4[i] ;
		}
		break;
			//BieMap Show Number-5
		case 5:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM5[i] ;
		}
		break;
			//BieMap Show Number-6
		case 6:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM6[i] ;
		}
		break;
			//BieMap Show Number-7
		case 7:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM7[i] ;
		}
		break;
			//BieMap Show Number-8
		case 8:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM8[i] ;
		}
		break;
			//BieMap Show Number-9
		case 9:
		for(i=0;i<8;i++)									
		{
		BitMapTab[i] = ~NUM9[i] ;
		}
		break;
		//BieMap-Count reset to 0
		case 10:trigger_BM = 0;break;
		default:break;
	}
}*/

void BitMap_Init()  //推挽输出
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
