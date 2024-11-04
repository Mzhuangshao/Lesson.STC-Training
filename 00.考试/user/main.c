#include "timer.h"			//计时器头文件
#include "Bleep.h"			//蜂鸣器头文件
#include "BitMap.h"			//点阵头文件
#include "SysLed.h"			//P45系统灯头文件
#include "LED.h"				//P0-LED头文件
#include "KEY.h"				//按键头文件

void main(void)									 //main function//主函数
{	
	//部分设置初始化
	BitMap_Init();
	Bleep_Init();
	
	//定时器设置初始化
	Timer0Init();
  Timer1Init();
	while(1)
	{
		if(trigger_1ms)				       //1ms trigger
		{
			trigger_1ms = 0;		 		   //reset trigger
			KEY1_CHECK(); KEY2_CHECK();//KEY check//按键检测
			BitMap_Display();					 //点阵显示图案预加载
		}
		if(trigger_10ms)						 //10ms trigger
		{
			trigger_10ms = 0;					 //reset trigger
			SysLED();									 //system-LED flash//P45系统灯闪烁
			Bleep();									 //蜂鸣器
			main_LED();								 //P0-LED总控
			main_BitMap();						 //点阵图案总控
		}
	}
}