#include "button.h"

//unsigned char code tab[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0xff};
unsigned char code num0[] = {0x0e,0x11,0x13,0x15,0x19};
unsigned char code num1[] = {0x04,0x0c,0x1f};
unsigned char code num2[] = {0x0e,0x11,0x01,0x06,0x08,0x10,0x1f};
unsigned char code num3[] = {0x0e,0x11,0x01,0x06};
unsigned char code num4[] = {0x03,0x05,0x09,0x11,0x1f,0x01};
unsigned char code num5[] = {0x1f,0x10,0x1e,0x01,0x11,0x0e};
unsigned char code num6[] = {0x0e,0x11,0x10,0x1e};
unsigned char code num7[] = {0x1f,0x11,0x01,0x02,0x04};
unsigned char code num8[] = {0x0e,0x11};
unsigned char code num9[] = {0x0e,0x11,0x0f,0x01,0x02,0x0c};
unsigned char M1=0;
unsigned char M2=0;


void button_CHECK(void)
{
	unsigned char i, j;
	for(i=0;i<100;i++)
	{	
		for(j=0;j<200;j++);
	}
}

void button_control(void)
{
	button1();
  
}

void button1(void)
{
	if(BUTTON1==0)
	{
		button_CHECK();
		 if(BUTTON1==0)
			{ 
				M1++;
				if(M1>8)
			   {
					M1=0;
			   }
				while(BUTTON1==0);
			}
	 }
}