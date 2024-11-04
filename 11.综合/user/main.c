#include "timer.h"
#include "Bleep.h"
#include "BitMap.h"
#include "SysLed.h"
#include "LED.h"
#include "KEY.h"

void main(void)				//������
{	
	//��������
	BitMap_Init();
	Bleep_Init();
	//��ʱ������
	Timer0Init();
  Timer1Init();
	while(1)
	{
		if(trigger_1ms)				//1ms trigger
		{
			trigger_1ms = 0;
			KEY1_CHECK(); KEY2_CHECK();
			BitMap_Display();
			SysLED();
			
		}
		if(trigger_10ms)			//10ms trigger
		{
			trigger_10ms = 0;
			
			
			Bleep();
			main_LED();
			main_BitMap();
			
			
			
			
		}
	}
}