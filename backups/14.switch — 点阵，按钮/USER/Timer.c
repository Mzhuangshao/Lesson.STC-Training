#include "Buzzer.H"////包含头文件，定时器有关

volatile bit Flag_1ms = 0,Flag_10ms = 0 ;//定义1个全局变量，每隔相应的定时到达时，设为1！表示时间到了

void Timer0Init(void)		//1毫秒@11.0592MHz
{
	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时

        ET0 = 1;//  开启T0中断 
      EA = 1 ;//  开启总中断

}


void T0_ISR(void) interrupt 1
{
   Flag_1ms = 1;
}





void Timer1Init(void)		//010毫秒@11.0592MHz
{
	AUXR &= 0xBF;		//定时器时钟12T模式
	TMOD &= 0x0F;		//设置定时器模式
	TL1 = 0x00;		//设置定时初值
	TH1 = 0xDC;		//设置定时初值
	TF1 = 0;		//清除TF1标志
	TR1 = 1;		//定时器1开始计时

       ET1 = 1;//  开启T1中断 
      EA = 1 ;//  开启总中断
}


void T1_ISR(void) interrupt 3
{
   Flag_10ms = 1;
}





