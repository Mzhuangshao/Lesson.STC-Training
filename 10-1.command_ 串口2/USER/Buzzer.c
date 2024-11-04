#include "Buzzer.H"	

void	Beep_Init(void)
{
	P3M1 &= 0x7f;		//0111 11111 �������ʵ�����λ����
	P3M0 |= 0x80;		//1000 00000 �������ʵ�����λ��λ
	
	//CON
	CCON = 0;                       //��ʼ��PCA���ƼĴ���
                                    //PCA��ʱ��ֹͣ
                                    //���CF��־
                                    //���ģ���жϱ�־
  CL = 0;                         //��λPCA�Ĵ���
  CH = 0;
  CMOD = 0x00;                    //����PCAʱ��Դ SysClk/12
                                  //��ֹPCA��ʱ������ж�
  //PCA_PWM0 = 0x00;                //PCAģ��0������8λPWM
  //CCAP0H = CCAP0L = 0x20;         //PWM0��ռ�ձ�Ϊ87.5% ((100H-20H)/100H)
  //CCAPM0 = 0x42;                  //PCAģ��0Ϊ8λPWMģʽ

  //PCA_PWM1 = 0x40;                //PCAģ��1������7λPWM
  //CCAP1H = CCAP1L = 0x20;         //PWM1��ռ�ձ�Ϊ75% ((80H-20H)/80H)
  //CCAPM1 = 0x42;                  //PCAģ��1Ϊ7λPWMģʽ

  PCA_PWM2 = 0x00;                //PCAģ��0������8λPWM
  CCAP2H = CCAP2L = 125;         //PWM0��ռ�ձ�Ϊ50% 
  CCAPM2 = 0x42;                  //PCAģ��2Ϊ8λPWMģʽ

  CR = 1;                         //PCA��ʱ����ʼ����
	
}

void	Beep_ON(void)
{
	//CR = 1;                         //PCA��ʱ����ʼ����
	PCA_PWM2 &= 0xfc;
	CCAP2H = CCAP2L = 125;         //PWM0��ռ�ձ�Ϊ50% 
}

void	Beep_OFF(void)
{
	//CR = 0;                         //PCA��ʱ��ֹͣ����
	PCA_PWM2 |=0x03;
	CCAP2H = CCAP2L = 255;         //ռ�ձ�Ϊ0%����������� 
}

void	Buzzer_Handle(void)
{
	static	unsigned int Time100ms_Cnt = 0;		//����������ۼ�100ms
	
	
	if((Rec_Val > 0) && (Rec_Val != 0xaa) && (Rec_Val != 0x55))
	{
		Beep_ON();
		Time100ms_Cnt ++;
		if(Time100ms_Cnt >= 10)
		{
			Time100ms_Cnt = 0;
			Rec_Val = 0;
		}
	}
	else
	{
		Beep_OFF();
		Time100ms_Cnt = 0;	
	}

}
