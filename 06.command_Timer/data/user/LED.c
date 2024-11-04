#include "data.H"

void lightLED();
void Delay200ms();
void Delay250us();
void T0_ISR();
void T0Init();
void T1Init();
void bleep();
unsigned char code light_LED[] = {0xfb,0xf7,0xef,0xff};


void main(void)
{
	T0Init();
	TR0=1;
	
	P3M0 |= 0x80;
	P3M1 &= 0x7f;
	while(1)
	{
	
	P37 = !P37;
	Delay250us();
	}
}

void Delay200ms()		//@11.0592MHz
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
}

void Delay250us()		//@11.0592MHz
{
	unsigned char i, j;

	i = 3;
	j = 173;
	do
	{
		while (--j);
	} while (--i);
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

void BLEEP(void)
{
 unsigned char i=0;
  i++;
	if(i>=100)
	{
		P37 = !P37;
		Delay250us();
	}


}


void T0Init(void)
{
	EA=0;
	TMOD=0x00;
	TH0=(65535-50000)/256;
	TL0=(65535-50000)%256;
	TF0=0;
	ET0=1;
	TR0=1;
	EA=1;
}
void lightLED(void)
{
	unsigned char i;
	for(i=0;i<3;i++)
	{
	 P1 = light_LED[i];
	 Delay200ms();
	}
}