#include "Bleep.h"

void Bleep_Init()
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
	CR = 1;
}

void Bleep(void)
{
	static unsigned int Time100ms_Cnt = 0; //????,??100ms

	if (trigger_KEY_control)
	{
		BleepON(); // P37 = !P37;
		Time100ms_Cnt++;
		if (Time100ms_Cnt >= 20)
		{
			Time100ms_Cnt = 0;
			trigger_KEY_control = 0;
			P37 = 0;
		}
	}
	else
	{
		BleepOFF();
		Time100ms_Cnt = 0;
	}
}

void BleepON()
{
	CR = 1;
}
void BleepOFF()
{
	CR = 0;
}
/*void Bleep()
{
	static unsigned char Count = 0;
	static unsigned char Bleep_Count = 0;
	Count ++;
	if(Count >=20)
	{
		Count = 0;
		Bleep_Count ++;
		if(Bleep_Count >= 5)
		{
			Bleep_Count = 0;
		}
	}
		switch(Bleep_Count)
	{
		case 0:BleepON();break;
		case 1:BleepON();break;
		case 2:BleepOFF();break;
		case 3:BleepOFF();break;
		case 4:BleepOFF();break;
	}
}


void Bleep(void)
{
	static unsigned int BleepTimer = 0;
	 BleepTimer++;
	if (BleepTimer >= 4000)
	{
		BleepTimer = 0;
	}
	if(BleepTimer >= 0)
	 {
		P37 = !P37;
	 }
	if(BleepTimer >= 800)
	 {
	  P37 = 0;
	 }
}*/