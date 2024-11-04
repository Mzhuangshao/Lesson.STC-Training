#include "data.H"

sbit BitMap1 = P3^2;  //P32
sbit BitMap2 = P4^1;  //P41
sbit BitMap3 = P3^3;  //P33
sbit BitMap4 = P3^6;  //P36
sbit BitMap5 = P4^4;  //P44
sbit BitMap6 = P3^4;  //P34
sbit BitMap7 = P4^2;  //P42
sbit BitMap8 = P3^5;  //P35

unsigned int code FontTab0[] = {0x0e,0x04};
unsigned int code FontTab1[] = {0x36,0x49,0x41,0x22,0x14,0x08};
unsigned int code FontTab2[] = {0x0e,0x11,0x10};
unsigned int code FontTab3[] = {0x10,0x16,0x11};
unsigned int code FontTab4[] = {0x02,0x00};
unsigned int code FontTab5[] = {0x1e,0x11};
unsigned int code FontTab6[] = {0x0e,0x01,0x0f,0x11};
void Bleep_Init();
void BitMap_Init();
void Timer0Init();
void Timer1Init();
void Timer2Init();
//void Delay100us();
//
//
void main()													//main function
{
	BitMap_Init();
	//Bleep_Init();
	
	Timer0Init();
  Timer1Init();
  Timer2Init();
 while(1)
 {
		
		
 }
}

void Bleep_Init()
{
	P3M1 &= 0x7f;
	P3M0 |= 0x80;
}
/*
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
}*/
//
void T0Isr() interrupt 1  //中断服务 蜂鸣器控制
{
	static unsigned int BleepTimer = 0;
	 BleepTimer++;
	if (BleepTimer >= 4000)
	{
		BleepTimer = 0;
	}
	if(BleepTimer >= 3200)
	 {
		P37 = !P37;
	 }
	if(BleepTimer >= 800)
	 {
	  P37 = 0;
	 }
}
//
void T1Isr() interrupt 3  //中断服务 P2控制
	{
	static unsigned int T1Count = 0;
	static unsigned char Count = 0;
	static unsigned char Count1 = 0;
	T1Count ++;
	if (T1Count >= 5000)
	{
		T1Count = 0;
		Count ++;
	}
	if(Count ==2)
	{
		Count1++;
		Count = 0;
	}
	if(Count1 == 0)
	{
		P2 = ~FontTab0[0];BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab0[1];BitMap1 = 0;BitMap2 = 1;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab0[1];BitMap1 = 0;BitMap2 = 0;BitMap3 = 1;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab0[1];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 1;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab0[1];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 1;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab0[0];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 1;BitMap7 = 0;BitMap8 = 0;
		//BitMap1 = 0;BitMap2 = 0;BitMap3 = 1;BitMap4 = 1;BitMap5 = 1;BitMap6 = 1;BitMap7 = 1;BitMap8 = 1;
	}
	else if (Count1 == 1)
	{
		P2 = ~FontTab1[0];BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab1[1];BitMap1 = 0;BitMap2 = 1;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab1[2];BitMap1 = 0;BitMap2 = 0;BitMap3 = 1;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab1[3];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 1;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab1[4];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 1;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
		P2 = ~FontTab1[5];BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 1;BitMap7 = 0;BitMap8 = 0;
	}
	else if (Count1 == 2)
	{
	
	}
	else if (Count1 == 3)
	{
		
	}
	else if (Count1 == 4)
	{
		Count = 0;
	}
}
//
void T2Isr() interrupt 12 //中断服务 P45控制
{
	static unsigned int T2Count = 0;
	T2Count ++;
	if(T2Count >= 4)
	{
		T2Count = 0;
		P45 = !P45;
	}
}
//
void Timer0Init(void)		//250us@12.000MHz
{
	AUXR |= 0x80;	
	TMOD &= 0xF0;	
	TL0 = 0x48;	
	TH0 = 0xF4;
	TF0 = 0;
	TR0 = 1;
	ET0 = 1;
	EA = 1;
}
void Timer1Init(void)		//250us@12.000MHz
{
	AUXR |= 0x80;	
	TMOD &= 0xF0;	
	TL1 = 0x48;	
	TH1 = 0xF4;
	TF1 = 0;
	TR1 = 1;
	ET1 = 1;
	EA = 1;
}
void Timer2Init(void)		//100us@12.000MHz
{
	AUXR &= 0xFB;		//?????12T??
	T2L = 0x9C;		//??????
	T2H = 0xFF;		//??????
	AUXR |= 0x10;		//???2????

	IE2 |= 0x04;
	EA = 1;
}
/*void Delay100us()		//@11.0592MHz
{
	unsigned char i, j;
	i = 2;
	j = 15;
	do
	{
		while (--j);
	} while (--i);
}*/

