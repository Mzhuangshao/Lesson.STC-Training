#include "timer.h"

volatile bit trigger_1ms = 0, trigger_10ms = 0 , trigger_250us = 0 ;

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

void Timer2Init(void)		//250us@12.000MHz
{
	AUXR &= 0xFB;		
	T2L = 0x06;		
	T2H = 0xFF;		
	AUXR |= 0x10;	

	IE2 |= 0x04;
	EA = 1;
}


void T0_Isr() interrupt 1
{
	//static unsigned int T0_Count = 0;
	//T0_Count++;
	//if(T0_Count >= 200)
	//{
		//T0_Count = 0;
		trigger_1ms = 1;
	//}
}
void T1_Isr() interrupt 3
{
	//static unsigned int T1_Count = 0;
	//T1_Count++;
	//if(T1_Count >= 5)
	//{
		//T1_Count = 0;
		trigger_10ms = 1;
	//}
}

void T2_Isr() interrupt 12
{
	//static unsigned int T2_Count = 0;
	//T2_Count++;
	//if(T2_Count >= 5000)
	//{
		//T2_Count = 0;
		trigger_250us = 1;
	//}
}
