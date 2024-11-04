#include "data.H"

void T0_ISR();
void T0Init();
void BleepDelay1();
void BleepDelay2();
void Bleep1();
void Bleep2();
void lightLED();
void light4();
void Delay100ms();
void Delayx100ms(unsigned char x100ms);
unsigned char code light_LED[] = {0xfb,0xf7,0xef,0xff};
unsigned char code light4_Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0xff};
//
//
void main(void)
{
	T0Init();
	TR0=1;
	
	P3M0 |= 0x80;
	P3M1 &= 0x7f;
	while(1)
	{
	P45 = 0;
	Bleep1();
	P45 = 1;
	Delayx100ms(3);
	P45 = 0;
	Bleep1();
	P45 = 1;
	Delayx100ms(3);
	P45 = 0;
	Bleep1();
	P45 = 1;
	Delayx100ms(6);
	Bleep2();
	
	}
}
//
//

void T0Init(void)		//50??@12.000MHz
{
	AUXR &= 0x7F;
	TMOD &= 0xF0;
	TL0 = 0xB0;
	TH0 = 0x3C;
	TF0 = 0;
	TR0 = 1;
}
void T0_ISR(void) interrupt 1
{
static unsigned char Cnt_1s=0;
	Cnt_1s++;
	if(Cnt_1s>=3)
	{
		Cnt_1s=0;
		P45 = !P45;
	}
}
void BleepDelay1()		//@11.0592MHz
{
	unsigned char i, j;
	
	i = 20;
	j = 160;
	do
	{
		while (--j);
	} while (--i);
}
void BleepDelay2()		//@11.0592MHz
{
	unsigned char i, j;
	
	i = 3;
	j = 170;
	do
	{
		while (--j);
	} while (--i);
}

void Bleep1(void)
{
 unsigned int i;
 for(i=200;i>0;i--)
 {
  P37 = !P37;
	BleepDelay1();
 }
}
void Bleep2(void)
{
 unsigned int i;
 for(i=10000;i>0;i--)
 {
  P37 = !P37;
	BleepDelay2();
 }
}

void lightLED(void)
{
	unsigned char i;
	for(i=0;i<4;i++)
	{
	 P45 = !P45;
	 
	 Delayx100ms(2);
	}
}
/*void light4(void)   //P00 P07 to 0.1s 低到高依次点亮,高到低熄灭
{
	 unsigned int i;
	for(i=9;i>0;i--)
	{
		P0 = light4_Tab[9-i];
		Delayx100ms(1);
	}
}*/
void Delay100ms()		//add function-clock 0.1s//@11.0592MHz
{
	unsigned char i, j, k;
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delayx100ms(unsigned char x100ms)
{
	while(x100ms)
	{
		Delay100ms();
		x100ms --;
	}
}





