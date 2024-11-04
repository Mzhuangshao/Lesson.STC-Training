#include "Buzzer.H"	

void	Beep_Init(void)
{
	P3M1 &= 0x7f;		//0111 11111 与操作，实现最高位清零
	P3M0 |= 0x80;		//1000 00000 或操作，实现最高位置位
	
	//CON
	CCON = 0;                       //初始化PCA控制寄存器
                                    //PCA定时器停止
                                    //清除CF标志
                                    //清除模块中断标志
  CL = 0;                         //复位PCA寄存器
  CH = 0;
  CMOD = 0x00;                    //设置PCA时钟源 SysClk/12
                                  //禁止PCA定时器溢出中断
  //PCA_PWM0 = 0x00;                //PCA模块0工作于8位PWM
  //CCAP0H = CCAP0L = 0x20;         //PWM0的占空比为87.5% ((100H-20H)/100H)
  //CCAPM0 = 0x42;                  //PCA模块0为8位PWM模式

  //PCA_PWM1 = 0x40;                //PCA模块1工作于7位PWM
  //CCAP1H = CCAP1L = 0x20;         //PWM1的占空比为75% ((80H-20H)/80H)
  //CCAPM1 = 0x42;                  //PCA模块1为7位PWM模式

  PCA_PWM2 = 0x00;                //PCA模块0工作于8位PWM
  CCAP2H = CCAP2L = 125;         //PWM0的占空比为50% 
  CCAPM2 = 0x42;                  //PCA模块2为8位PWM模式

  CR = 1;                         //PCA定时器开始工作
	
}

void	Beep_ON(void)
{
	//CR = 1;                         //PCA定时器开始工作
	PCA_PWM2 &= 0xfc;
	CCAP2H = CCAP2L = 125;         //PWM0的占空比为50% 
}

void	Beep_OFF(void)
{
	//CR = 0;                         //PCA定时器停止工作
	PCA_PWM2 |=0x03;
	CCAP2H = CCAP2L = 255;         //占空比为0%，持续输出低 
}

void	Buzzer_Handle(void)
{
	static	unsigned int Time100ms_Cnt = 0;		//定义变量，累计100ms
	
	
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
