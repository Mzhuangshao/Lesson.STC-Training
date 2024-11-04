#include "timer.h"
#include "Bleep.h"
#include "BitMap.h"
#include "SysLed.h"
#include "LED.h"
#include "KEY.h"

void main(void)				//主函数
{	
	//推挽设置
	BitMap_Init();
	Bleep_Init();
//	P3M1 = 0x00;
 // P3M0 = 0xff;
	//定时器设置
	Timer0Init();
  Timer1Init();
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
			LED_Display();
			Bleep();
			KEY1_CHECK();
			KEY2_CHECK();
		}
	}
}