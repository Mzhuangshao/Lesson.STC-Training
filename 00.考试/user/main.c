#include "timer.h"			//��ʱ��ͷ�ļ�
#include "Bleep.h"			//������ͷ�ļ�
#include "BitMap.h"			//����ͷ�ļ�
#include "SysLed.h"			//P45ϵͳ��ͷ�ļ�
#include "LED.h"				//P0-LEDͷ�ļ�
#include "KEY.h"				//����ͷ�ļ�

void main(void)									 //main function//������
{	
	//�������ó�ʼ��
	BitMap_Init();
	Bleep_Init();
	
	//��ʱ�����ó�ʼ��
	Timer0Init();
  Timer1Init();
	while(1)
	{
		if(trigger_1ms)				       //1ms trigger
		{
			trigger_1ms = 0;		 		   //reset trigger
			KEY1_CHECK(); KEY2_CHECK();//KEY check//�������
			BitMap_Display();					 //������ʾͼ��Ԥ����
		}
		if(trigger_10ms)						 //10ms trigger
		{
			trigger_10ms = 0;					 //reset trigger
			SysLED();									 //system-LED flash//P45ϵͳ����˸
			Bleep();									 //������
			main_LED();								 //P0-LED�ܿ�
			main_BitMap();						 //����ͼ���ܿ�
		}
	}
}