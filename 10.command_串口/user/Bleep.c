#include "Bleep.h"


//void	Bleep_Init(void)
//{
//	//P37???????
//	P3M1 &= 0x7f;		//0111 11111 ???,???????
//	P3M0 |= 0x80;		//1000 00000 ???,???????
//	
//	//CON
//	CCON = 0;                       //???PCA?????
//                                    //PCA?????
//                                    //??CF??
//                                    //????????
//  CL = 0;                         //??PCA???
//  CH = 0;
//  CMOD = 0x00;                    //??PCA??? SysClk/12
//                                  //??PCA???????
//  //PCA_PWM0 = 0x00;                //PCA??0???8?PWM
//  //CCAP0H = CCAP0L = 0x20;         //PWM0?????87.5% ((100H-20H)/100H)
//  //CCAPM0 = 0x42;                  //PCA??0?8?PWM??

//  //PCA_PWM1 = 0x40;                //PCA??1???7?PWM
//  //CCAP1H = CCAP1L = 0x20;         //PWM1?????75% ((80H-20H)/80H)
//  //CCAPM1 = 0x42;                  //PCA??1?7?PWM??

//  PCA_PWM2 = 0x00;                //PCA??0???8?PWM
//  CCAP2H = CCAP2L = 125;         //PWM0?????50% 
//  CCAPM2 = 0x42;                  //PCA??2?8?PWM??

//  CR = 1;                         //PCA???????
//	
//}

//void	BleepON(void)
//{
//	//CR = 1;                         //PCA???????
//	CCAP2H = CCAP2L = 125;         //PWM0?????50% 
//}

//void	BleepOFF(void)
//{
//	//CR = 0;                         //PCA???????
//	CCAP2H = CCAP2L = 255;         //????0%,????? 
//}

//void	Bleep(void)
//{
//	static	unsigned int Time100ms_Cnt = 0;		//????,??100ms
//	
//	
//	if(trigger_KEY_control)
//	{
//		BleepON();//P37 = !P37;
//		Time100ms_Cnt ++;
//		if(Time100ms_Cnt >= 100)
//		{
//			Time100ms_Cnt = 0;
//			trigger_KEY_control = 0;
//			P37 = 0;
//		}
//	}
//	else
//	{
//		BleepOFF();
//		Time100ms_Cnt = 0;	
//	}

//}

//void Bleep(void)
//{
//  static unsigned int Time100ms_Cnt = 0;
//	if(trigger_KEY_control)
//	{
//		P37 = !P37;
//		Time100ms_Cnt ++;
//		if(Time100ms_Cnt >= 100)
//		{
//			Time100ms_Cnt = 0;
//			trigger_KEY_control = 0;	
//		}
//	}
//	else 
//	{
//		P37 = 0;
//		trigger_KEY_control = 0;
//	}
//}

void Bleep_Init()
{
	P3M1 &= 0x7f;
	P3M0 |= 0x80;
	CCON = 0;
	CL = 0;
	CH = 0;
	CMOD =0x00;
	PCA_PWM2 = 0x00;
	CCAP2H = CCAP2L = 125;
	CCAPM2 = 0x42;
	CR = 1;
}
void BleepON()
{
	CR = 1;
}
void BleepOFF()
{
	CR = 0;
}
void Bleep()
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