#include "timer.h"
#include "Bleep.h"
#include "BitMap.h"
#include "SysLed.h"
#include "LED.h"
#include "button.h"

void main(void)				//Ö÷º¯Êý
{	

	BitMap_Init();
	Bleep_Init();

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
			//nor_LED();
			LED_Display();
			Bleep();
		}
	}
}