#include "timer.h"			//计时器头文件

volatile bit trigger_1ms = 0, trigger_10ms = 0;

void Timer0Init(void)		//1ms Timer @12.000MHz
{
	AUXR &= 0x7F;		
	TMOD &= 0xF0;	
	TL0 = 0x18;		
	TH0 = 0xFC;	
	TF0 = 0;	
	TR0 = 1;		
	ET0 = 1;
	EA = 1;
}

void Timer1Init(void)		//10ms@12.000MHz
{
	AUXR &= 0xBF;		
	TMOD &= 0x0F;		
	TL1 = 0xF0;	
	TH1 = 0xD8;		
	TF1 = 0;	
	TR1 = 1;
	ET1 = 1;
	EA = 1;
}

void T0_Isr() interrupt 1
{
		trigger_1ms = 1;
}
void T1_Isr() interrupt 3
{
		trigger_10ms = 1;
}


