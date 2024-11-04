#include "P0.h"

unsigned char code light1_Tab[] = {0xff,0x00};
unsigned char code light4_Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0xff};

//extern volatile unsigned char lightCount = 0;

void nor_LED()
{
	static unsigned int lightCount = 0;
	static unsigned int LED_num = 0;
	lightCount++;
	if(lightCount > 20)
	{
		lightCount = 0;
		LED_num++;
	}
	if(LED_num == 0)
	{
		P0 = light1_Tab[0];
	}
	if(LED_num == 2)
	{
		P0 = light1_Tab[1];
	}
	if(LED_num == 4)
	{
		P0 = light1_Tab[0];
	}
	if(LED_num == 6)
	{
		P0 = light1_Tab[1];
	}
	if(LED_num == 7)
	{
		P0 = light1_Tab[0];
	}
	if(LED_num == 8)
	{
		P0 = light4_Tab[0];
	}
	if(LED_num == 9)
	{
		P0 = light4_Tab[1];
	}
	if(LED_num == 10)
	{
		P0 = light4_Tab[2];
	}
	if(LED_num == 11)
	{
		P0 = light4_Tab[3];
	}
	if(LED_num == 12)
	{
		P0 = light4_Tab[4];
	}
	if(LED_num == 13)
	{
		P0 = light4_Tab[5];
	}
	if(LED_num == 14)
	{
		P0 = light4_Tab[6];
	}
	if(LED_num == 15)
	{
		P0 = light4_Tab[7];
	}
	if(LED_num == 16)
	{
		P0 = light4_Tab[8];
	}
	if(LED_num == 17)
	{
		P0 = light4_Tab[9];
	}
	if(LED_num == 18)
	{
		P0 = light4_Tab[10];
	}
	if(LED_num == 19)
	{
		P0 = light4_Tab[11];
	}
	if(LED_num == 20)
	{
		P0 = light4_Tab[12];
	}
	if(LED_num == 21)
	{
		P0 = light4_Tab[13];
	}
	if(LED_num == 22)
	{
		P0 = light4_Tab[14];
	}
	if(LED_num == 23)
	{
		P0 = light4_Tab[15];
	}
	if(LED_num == 24)
	{
		LED_num = 0;
	}
}
