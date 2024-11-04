#include "timer.h"
#include "Bleep.h"
#include "BitMap.h"
#include "SysLed.h"
#include "P0.h"

void main(void)				//主函数
{	
	//推挽设置
	BitMap_Init();
	Bleep_Init();
	//定时器设置
	Timer0Init();
  Timer1Init();
	Timer2Init();
	while(1)
	{
		if(trigger_1ms)				//1ms trigger
		{
			trigger_1ms = 0;
			BitMap_Display();
			BitMap();
		}
		if(trigger_10ms)			//10ms trigger
		{
			trigger_10ms = 0;
			SysLED();
			nor_LED();
			Bleep();
		}
		if(trigger_250us)			//
		{
			trigger_250us = 0;
		}
	}
}