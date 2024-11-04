#include "LED.h"

unsigned char code light4_Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0xff};

void main_LED()														//P0 main-function//P0Ö÷¿Ø
{
	static unsigned char LED_num = 0;
	static bit FREEZE = 0;
	
	if(trigger_KEY1)
	{
		trigger_KEY1 = 0;
		FREEZE = 0;
		LED_num ++;
		if(LED_num >= 5)
		{
			LED_num = 0;
			P0 = 0xff;
		}
	}
	if(trigger_KEY2_1)
	{
		trigger_KEY2_1 = 0;
		FREEZE = 1;
	}
	
	if(FREEZE == 0)
	{
		switch(LED_num)
		{
			case 1:light1();break;
			case 2:light2();break;
			case 3:light3();break;
			case 4:light4();break;
			default:break;
		}
	}
	else
	{
		P0 = 0xff;
	}
}
void light1()
{
	static unsigned int COUNT = 0;
	static bit trigger = 0;
		COUNT ++;
	if(COUNT >= 50)
	{
		COUNT = 0;
		trigger = !trigger;
	}
	if(trigger)
	{
		P0 = 0xaa;
	}
	else 
	{
		P0 = 0x55;
	}
}
void light2()
{
	static unsigned int COUNT = 0;
	static bit trigger = 0;
		COUNT ++;
	if(COUNT >= 50)
	{
		COUNT = 0;
		trigger = !trigger;
	}
	if(trigger)
	{
		P0 = 0xcc;
	}
	else 
	{
		P0 = 0x33;
	}
}
void light3()
{
	static unsigned int COUNT = 0;
	static bit trigger = 0;
		COUNT ++;
	if(COUNT >= 8)
	{
		COUNT = 0;
		trigger = !trigger;
	}
	if(trigger)
	{
		P0 = 0x66;
	}
	else 
	{
		P0 = 0x99;
	}
}
void light4()
{
	static unsigned int COUNT = 0;
	static unsigned int trigger = 0;
	
		COUNT ++;
	if(COUNT >= 10)
	{
		COUNT = 0;
		trigger ++;
		if(trigger >= 15)
		{
			trigger = 0;
		}
	}
	if(trigger)
	{
		P0 = light4_Tab[trigger];
	}
}
