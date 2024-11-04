#include "LED.h"				//P0-LED头文件

unsigned char code light2_Tab[] = {0xff,0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00,0xff};
unsigned char code light3_Tab[] = {0xff,0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00,0xff};
unsigned char code light4_Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0xff};
unsigned char code light5_Tab[] = {0x7e,0x3c,0x18,0x00,0x18,0x3c,0x7e,0xff};

void main_LED()//P0 main-function//P0主控
{
	static unsigned char LED_num = 0;
	if(trigger_KEY1)		//KEY1 trigger Check//按键1触发检测
	{
		trigger_KEY1 = 0;
		LED_num ++;
		if(LED_num >= 5)	//reset count//重置计数器
		{
			LED_num = 1;
			P0 = 0xff;
		}
	}
	switch(LED_num)		//
	{
		case 1:light1();break;		//mode-I
		case 2:light2();break;		//mode-II
		case 3:light3();break;		//mode-II
		case 4:light4();break;		//mode-IV
		default:break;
	}
}

void light1()//mode-I		//模式1
{
	static unsigned int COUNT = 0;
	static bit trigger = 0;
		COUNT ++;
	if(COUNT >= 30)
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
void light2()//mode-II	//模式2
{
	static unsigned int COUNT = 0;
	static unsigned int trigger = 0;
	
		COUNT ++;
	if(COUNT >= 30)
	{
		COUNT = 0;
		trigger ++;
		if(trigger >= 9)
		{
			trigger = 0;
		}
	}
	if(trigger)
	{
		P0 = light2_Tab[trigger];
	}
}
void light3()//mode-III	//模式3
{
	static unsigned int COUNT = 0;
	static unsigned int trigger = 0;
	
		COUNT ++;
	if(COUNT >= 30)
	{
		COUNT = 0;
		trigger ++;
		if(trigger >= 9)
		{
			trigger = 0;
		}
	}
	if(trigger)
	{
		P0 = light3_Tab[trigger];
	}
}
void light4()//mode-IV	//模式4
{
	static unsigned int COUNT = 0;
	static unsigned int trigger = 0;
	
		COUNT ++;
	if(COUNT >= 30)
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
