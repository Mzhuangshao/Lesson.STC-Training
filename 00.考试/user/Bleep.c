#include "Bleep.h"			//������ͷ�ļ�

void Bleep_Init()				//��������ʼ��
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

void	Bleep(void)  			//�������ܿ�
{
	static	unsigned int COUNT = 0;
	if(trigger_KEY_control)		//��������
	{
		BleepON();							//trun on
		COUNT ++;
		if(COUNT >= 20)					//reset
		{
			COUNT = 0;
			trigger_KEY_control = 0;
			P37 = 0;
		}
	}
	else											//trun off
	{
		BleepOFF();
		COUNT = 0;	
	}

}

void BleepON()	//��������
{
	CR = 1;
}
void BleepOFF()//��������
{
	CR = 0;
}