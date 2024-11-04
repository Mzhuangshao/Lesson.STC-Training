#include "STC15F.H"

void  Beep_Init(void)
{
	P3M1 &= 0x7f;
	P3M0 |= 0x80;
	CCON = 0;
	
	CL = 0;
	CH = 0;
	CMOD = 0x00;
	PCA_PWM2 = 0x00;
	CCAP2H = CCAP2L = 125;
	CCAPM2 = 0x42;
	
	CR	= 1;
}

void  Beep_ON(void)
{
  CR = 1;
}

void  Beep_OFF(void)
{
   CR = 0;
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


void Delay800ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 34;
	j = 159;
	k = 59;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main(void)    
{
    Beep_Init();
	
		while(1)
    {
     Beep_ON();
		 Delay200ms();
		 Beep_OFF();
		 Delay800ms();	
			
    }	
}
	
                        