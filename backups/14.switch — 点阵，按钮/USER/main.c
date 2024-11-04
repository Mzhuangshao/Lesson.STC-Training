#include "Timer.H"//包含头定时头文件

#include "Sysled.H"//包含系统灯头文件

#include "Buzzer.H"//包含蜂鸣器头文件

#include "Dotled.H"//包含头文件，点阵有关；

#include "ben.H"

#include "rad.H"	

//主函数
void main (void)
{
	Timer0Init();
	Timer1Init();
	DotLed_Init();
	K1_Check();
	K2_Check();

	while(1)
	{
		//一秒
		if(Flag_1ms)//一秒时间到
		{
			Flag_1ms = 0;//复位一秒时间标志，等待下一个一秒时间到
			
			Beep_Inte();
			DotLed_Display();
      
			
		}
		//十秒
		if(Flag_10ms)//一秒时间到
		{
			Flag_10ms = 0;//复位10秒时间标志，等待下一个一秒时间到
			
			Sysled_Display();//调用系统灯显示函数	
	  	DotLed_new();
		  ben_Mode1();
			K1_Check();
			K2_Check();

		}

		
		
	}
	
}