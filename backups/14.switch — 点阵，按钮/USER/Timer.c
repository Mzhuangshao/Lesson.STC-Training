#include "Buzzer.H"////����ͷ�ļ�����ʱ���й�

volatile bit Flag_1ms = 0,Flag_10ms = 0 ;//����1��ȫ�ֱ�����ÿ����Ӧ�Ķ�ʱ����ʱ����Ϊ1����ʾʱ�䵽��

void Timer0Init(void)		//1����@11.0592MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x66;		//���ö�ʱ��ֵ
	TH0 = 0xFC;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ

        ET0 = 1;//  ����T0�ж� 
      EA = 1 ;//  �������ж�

}


void T0_ISR(void) interrupt 1
{
   Flag_1ms = 1;
}





void Timer1Init(void)		//010����@11.0592MHz
{
	AUXR &= 0xBF;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TL1 = 0x00;		//���ö�ʱ��ֵ
	TH1 = 0xDC;		//���ö�ʱ��ֵ
	TF1 = 0;		//���TF1��־
	TR1 = 1;		//��ʱ��1��ʼ��ʱ

       ET1 = 1;//  ����T1�ж� 
      EA = 1 ;//  �������ж�
}


void T1_ISR(void) interrupt 3
{
   Flag_10ms = 1;
}





