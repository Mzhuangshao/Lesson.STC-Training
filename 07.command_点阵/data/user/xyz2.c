#include "data.H"

sbit BitMap1 = P3^2;  //P32
sbit BitMap2 = P4^1;  //P41
sbit BitMap3 = P3^3;  //P33
sbit BitMap4 = P3^6;  //P36
sbit BitMap5 = P4^4;  //P44
sbit BitMap6 = P3^4;  //P34
sbit BitMap7 = P4^2;  //P42
sbit BitMap8 = P3^5;  //P35
unsigned int code BM1_Tab[] = {0x00,0x42,0x5a,0x66};
void BitMap_Init();
void Delay200ms();
void Delay300ms();

void main(void)
{
	BitMap_Init();
 while(1)
 {
	P2 = BM1_Tab[0];BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	Delay200ms();
	P2 = BM1_Tab[1];BitMap1 = 0;BitMap2 = 1;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	Delay200ms();
	P2 = BM1_Tab[2];BitMap1 = 0;BitMap2 = 0;BitMap3 = 1;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	Delay200ms();
	P2 = BM1_Tab[2];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 1;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	Delay200ms();
	P2 = BM1_Tab[3];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 1;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	Delay200ms();
	P2 = BM1_Tab[2];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 1;BitMap7 = 0;BitMap8 = 0;
	Delay200ms();
	P2 = BM1_Tab[2];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 1;BitMap8 = 0;
	Delay200ms();
	P2 = BM1_Tab[1];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	Delay300ms();
 }
}

void BitMap_Init()  //推挽输出
{
	P2M1 = 0x00;
	P2M0 = 0xff;
	
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

//
void Delay200ms()		//@11.0592MHz		//@11.0592MHz
{
	unsigned char i, j;

	i = 3;
	j = 35;
	do
	{
		while (--j);
	} while (--i);
}

void Delay300ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 13;
	j = 156;
	k = 83;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

