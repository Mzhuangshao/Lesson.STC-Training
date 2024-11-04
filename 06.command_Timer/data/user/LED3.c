#include "data.H"

void BleepDelay1();
void Bleep1();
void Delay100ms();
void BleepInit();
void Timer0Init();
void Delay250us();
void Delayx100ms(unsigned char x100ms);
 
 void Timer0Init(void)		//50ms@11.0592MHz
{
	AUXR &= 0x7F;		
	TMOD &= 0xF0;		
	TL0 = 0x00;		
	TH0 = 0x4C;		
	TF0 = 0;		
	TR0 = 1;
	ET0 = 1;
	EA = 1;
}
unsigned char bleepcount = 0;
bit count = 0;
void BleepInit() interrupt 1
{
	 bleepcount++;
	if(bleepcount>=10)
	{
	 bleepcount=0;
	 count=1;
	}
}


void main(void)
{
  P3M0 |= 0x80;
	P3M1 &= 0x7f;
	Timer0Init();
	TR0=1;
	while(1)
	{
		if(count==0)
		{
			P37 = !P37;
			Delay250us();
		}
		else
		{
		  P37 = 0;
		}
	}
}
/*void BleepDelay1()		//@11.0592MHz
{
	unsigned char i, j;
	
	i = 10;
	j = 180;
	do
	{
		while (--j);
	} while (--i);
}


void Bleep1(void)
{
 unsigned int i;
 for(i=1400;i>0;i--)
 {
  P37 = !P37;
	Delay250us();
 }
}*/


void Delay250us()		//@11.0592MHz
{
	unsigned char i, j;
	i = 20;
	j = 190;
	do
	{
		while (--j);
	} while (--i);
}
