#include "data.H"

void Timer0Init();
void Timer1Init();
void Timer2Init();


void main()
{
	Timer0Init();
	Timer1Init();
	Timer2Init();
	while(1)
	{
	
	}
}

void T0Isr() interrupt 1  //中断服务 蜂鸣器控制
{
	P37 = !P37;
}

void T1Isr() interrupt 3  //中断服务 P0控制
{
	static unsigned int T1Count = 0;
	T1Count ++;
	if(T1Count >= 10)
	{
		T1Count = 0;
		P0 = ~P0;
	}
}

void T2Isr() interrupt 12 //中断服务 P45控制
{
	static unsigned int T2Count = 0;
	T2Count ++;
	if(T2Count >= 10)
	{
		T2Count = 0;
		P45 = !P45;
	}
}


void Timer0Init(void)		//350us@12.000MHz
{
	AUXR |= 0x80;		
	TMOD &= 0xF0;		
	TL0 = 0x98;	
	TH0 = 0xEF;	
	TF0 = 0;		
	TR0 = 1;	
	ET0 = 1;
	EA = 1;
}
void Timer1Init(void)		//50ms@12.000MHz
{
	AUXR &= 0xBF;		
	TL1 = 0xB0;	
	TH1 = 0x3C;	
	TF1 = 0;	
	TR1 = 1;		
	ET1 = 1;
	EA = 1;
}
void Timer2Init(void)		//20ms@12.000MHz
{
	AUXR &= 0xFB;
	T2L = 0xE0;		
	T2H = 0xB1;		
	AUXR |= 0x10;	
	IE2 |= 0x04;
	EA = 1;
}

