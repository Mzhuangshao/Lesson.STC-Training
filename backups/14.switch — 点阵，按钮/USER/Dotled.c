#include "DotLed.H"		//包含头文件，定时器有关 自己创建的！！！！

static unsigned char code Love_Tab1[] = {0xff,0x93,0x6d,0x7d,0xbb,0xd7,0xef,0xff};  //空心心形
static unsigned char code Love_Tab2[] = {0xff,0x93,0x01,0x01,0x83,0xc7,0xef,0xff};  //实心心形

volatile	unsigned char Dot_Tab[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};


//点阵LED驱动函数，用户想要显示其他数值，只需更新数组Dot_Tab
void	DotLed_Display(void)
{
	static	unsigned char Row_Cnt = 0;
	
	P32 = 0;P41 = 0;P33 = 0;P36 = 0;P44 = 0;P34 = 0;P42 = 0;P35 = 0;
	Row_Cnt ++;
	if(Row_Cnt > 8)
	{
		Row_Cnt = 1;
	}
	P2 = Dot_Tab[Row_Cnt - 1];
	switch(Row_Cnt)
	{
		case	1:P32 = 1;break;
		case	2:P41 = 1;break;
		case	3:P33 = 1;break;
		case	4:P36 = 1;break;
		case	5:P44 = 1;break;
		case	6:P34 = 1;break;
		case	7:P42 = 1;break;
		case	8:P35 = 1;break;
		default:break;
	}
}


void	DotLed_Init(void)
{
	//将P3口配置为推挽输出
	P2M1 = 0X00;
	P2M0 = 0XFF;
	P3M1 = 0X00;
	P3M0 = 0XFF;
	//P32 P41 P33 P36 P44 P34 P42 P35
	
	//互不干涉，使用与操作实现任意位清零，或操作实现任意位置位
	
	P3M1 &= 0xfb;  //1111 1011
	P3M0 |= 0x04;  //0000 0100
	
	P4M1 &= 0xfd;  
	P4M0 |= 0x02;
	
  P3M1 &= 0xf7;  
	P3M0 |= 0x08;
	
	P3M1 &= 0xfb;  
	P3M0 |= 0x40;
	 
	P4M1 &= 0xef;  
	P4M0 |= 0x10;
	
	P3M1 &= 0xef;  
	P3M0 |= 0x10;
	
	P4M1 &= 0xfb;  
	P4M0 |= 0x04;
	
	P3M1 &= 0xdf;  
	P3M0 |= 0x20;
  P2 = 0x00;
	P32 = 0; P41 = 0; P33 = 0; P36 = 0; P44 = 0; P34 = 0; P42 = 0; P35 = 0;
}
void DotLed_new(void)
{
unsigned char i;
unsigned char COUNT;
if(K1_Flag)									//reset
 {
	K1_Flag = 0;
	K2_Flag = 0;
	for(i=0;i<8;i++)
	{
		//Dot_Tab[i] = Love_Tab1[i];
		Dot_Tab[i] = 0xff;
	}
 }
 
 if(K2_Flag)										//
{
	K2_Flag = 0;
	COUNT ++;
}
if(COUNT ==1)
{
	for(i=0;i<8;i++)
	{
		Dot_Tab[i] = Love_Tab1[i];
	}
}
else if(COUNT ==2)
{
	COUNT = 0;
	for(i=0;i<8;i++)
	{
		Dot_Tab[i] = Love_Tab2[i];
	}
}
}
