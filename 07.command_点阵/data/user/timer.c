#include "data.H"

/*void BleepDelay()		//@11.0592MHz
{
	unsigned char i, j;
	i = 20;
	j = 200;
	do
	{
		while (--j);
	} while (--i);
}*/


void Timer0Init(void)		//250??@12.000MHz
{
	AUXR &= 0x7F;		
	TMOD &= 0xF0;		
	TL0 = 0x06;		
	TH0 = 0xFF;	
	TF0 = 0;		
	TR0 = 1;		
	ET0 = 1;
	EA = 1;
}
void Timer0Isr() interrupt 1
{
	static unsigned int Time1sCnt = 0;
	static bit BleepCount = 1;
	 Time1sCnt++;
	if (Time1sCnt >= 8000)
	{
		Time1sCnt = 0;
		BleepCount = !BleepCount;
	}
	if(BleepCount)
	 {
		P37 = !P37;
	 }
	else
	 {
	  P37 = 0;
	 }
}
void main(void)
{
	Timer0Init();
	P3M1 &= 0x7f;
	P3M0 |= 0x80;
 while(1)
 {
  }
}