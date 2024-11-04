#include "BitMap.h"

static unsigned char code Heart0[] = {0x00,0x36,0x49,0x41,0x22,0x14,0x08,0x00};//空心
static unsigned char code Heart1[] = {0x00,0x36,0x7f,0x7f,0x3e,0x1c,0x08,0x00};//实心

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

void BitMap()
{
	static unsigned int trigger_BM = 0;
				 unsigned char i ;
	static bit trigger_heart = 0;
		trigger_BM++;
if(trigger_BM >= 1000)
{
	trigger_BM = 0;
	trigger_heart = !trigger_heart;
}
	if(trigger_heart)										//触发器检测
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
		BitMapTab[i] = ~Heart1[i] ;
		}
	}
}
/*		OLD FUNCTION
void BitMap()
{
	static unsigned int T1Count = 0;
	static unsigned char Count = 0;
	T1Count ++;
	if (T1Count >= 100)
	{
		T1Count = 0;
		Count ++;
	}
	if(Count == 0)
	{
		P2 = ~FontTab0[0];
		BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 1)
	{
		P2 = ~FontTab0[0];
		BitMap1 = 0;BitMap2 = 1;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 2)
	{
		P2 = ~FontTab0[0];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 1;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 3)
	{
		P2 = ~FontTab0[0];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 1;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 4)
	{
		P2 = ~FontTab0[0];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 1;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 5)
	{
		P2 = ~FontTab0[0];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 1;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 6)
	{
		P2 = ~FontTab0[0];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 1;BitMap8 = 0;
	}
	if(Count == 7)
	{
		P2 = ~FontTab0[0];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	}
	if(Count == 8)
	{
		P2 = ~FontTab0[1];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	}
	if(Count == 9)
	{
		P2 = ~FontTab0[2];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	}
	if(Count == 10)
	{
		P2 = ~FontTab0[3];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	}
	if(Count == 11)
	{
		P2 = ~FontTab0[4];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	}
	if(Count == 12)
	{
		P2 = ~FontTab0[5];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	}
	if(Count == 13)
	{
		P2 = ~FontTab0[6];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	}
	if(Count == 14)
	{
		P2 = ~FontTab0[7];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	}
	if(Count == 15)
	{
		P2 = ~FontTab0[7];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 1;BitMap8 = 0;
	}
	if(Count == 16)
	{
		P2 = ~FontTab0[7];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 1;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 17)
	{
		P2 = ~FontTab0[7];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 1;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 18)
	{
		P2 = ~FontTab0[7];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 1;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 19)
	{
		P2 = ~FontTab0[7];
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 1;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 20)
	{
		P2 = ~FontTab0[7];
		BitMap1 = 0;BitMap2 = 1;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 21)
	{
		P2 = ~FontTab0[7];
		BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 22)
	{
		P2 = ~FontTab0[6];
		BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 23)
	{
		P2 = ~FontTab0[5];
		BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 24)
	{
		P2 = ~FontTab0[4];
		BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 25)
	{
		P2 = ~FontTab0[3];
		BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 26)
	{
		P2 = ~FontTab0[2];
		BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 27)
	{
		P2 = ~FontTab0[1];
		BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	if(Count == 28)
	{
	Count = 0;
	}
}*/

