#include "Timer.H"//����ͷ��ʱͷ�ļ�

#include "Sysled.H"//����ϵͳ��ͷ�ļ�

#include "Buzzer.H"//����������ͷ�ļ�

#include "Dotled.H"//����ͷ�ļ��������йأ�

#include "ben.H"

#include "rad.H"	

//������
void main (void)
{
	Timer0Init();
	Timer1Init();
	DotLed_Init();
	K1_Check();
	K2_Check();

	while(1)
	{
		//һ��
		if(Flag_1ms)//һ��ʱ�䵽
		{
			Flag_1ms = 0;//��λһ��ʱ���־���ȴ���һ��һ��ʱ�䵽
			
			Beep_Inte();
			DotLed_Display();
      
			
		}
		//ʮ��
		if(Flag_10ms)//һ��ʱ�䵽
		{
			Flag_10ms = 0;//��λ10��ʱ���־���ȴ���һ��һ��ʱ�䵽
			
			Sysled_Display();//����ϵͳ����ʾ����	
	  	DotLed_new();
		  ben_Mode1();
			K1_Check();
			K2_Check();

		}

		
		
	}
	
}