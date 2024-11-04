#include "data.H"

sbit BitMap1 = P3^2;  //P32
sbit BitMap2 = P4^1;  //P41
sbit BitMap3 = P3^3;  //P33
sbit BitMap4 = P3^6;  //P36
sbit BitMap5 = P4^4;  //P44
sbit BitMap6 = P3^4;  //P34
sbit BitMap7 = P4^2;  //P42
sbit BitMap8 = P3^5;  //P35
unsigned int BitMap_Count = 0;
void Delay200ms();
void BitMap_Init();
void Timer0Init();
void BitMap_control();
void Timer0Isr();


void main(void)  //main function//主函数
{
  BitMap_Init();
	Timer0Init();
	TR0 =1;
	while(1)
	{
		BitMap_control();
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
void Timer0Isr() interrupt 1  //中断服务
{
	static unsigned int Time1sCnt = 0;
	 Time1sCnt++;
	if (Time1sCnt >= 30)
	{
		Time1sCnt = 0;
		if(BitMap_Count <= 8)
		{
			BitMap_Count ++;
		}
		else
		{
			BitMap_Count = 0;
		}
	}
}
void BitMap_control()  //BitMap //点阵图图案控制
{
	if(BitMap_Count == 1)        //P32
	{
		BitMap1 = 1;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	else if (BitMap_Count == 2)  //P41
	{
		BitMap1 = 0;BitMap2 = 1;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	else if (BitMap_Count == 3)  //P33
	{
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 1;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	else if (BitMap_Count == 4)  //P36
	{
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 1;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	else if (BitMap_Count == 5)  //P44
	{
	  BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 1;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	}
	else if (BitMap_Count == 6)  //P34
	{
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 1;BitMap7 = 0;BitMap8 = 0;
	}
	else if (BitMap_Count == 7)  //P42
	{
	  BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 1;BitMap8 = 0;
	}
	else if (BitMap_Count == 8)  //P35
	{
		BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 1;
	}
}
void Timer0Init(void)		//5ms@11.0592MHz//定时器5ms
{
	AUXR &= 0x7F;
	TMOD &= 0xF0;
	TL0 = 0x00;
	TH0 = 0xEE;
	TF0 = 0;
	TR0 = 1;
	ET0 = 1;
	EA = 1;
}
/*void Delay200ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 9;
	j = 104;
	k = 139;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}*/