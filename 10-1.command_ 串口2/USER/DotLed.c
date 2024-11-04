#include "DotLed.H"	
static	unsigned char code Love_Tab1[] = {0xff,0x93,0x6d,0x7d,0xbb,0xd7,0xef,0xff};//空心心形
static	unsigned char code Love_Tab2[] = {0xff,0x93,0x01,0x01,0x83,0xc7,0xef,0xff};//实心心形

volatile	unsigned char Dot_Tab[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};//定义点阵显示数组，或者称之为缓冲，并初始化为显示心形

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
	P3M1 = 0x00;
	P3M0 = 0x7f;
	
	P4M1 = 0x00;
	P4M0 = 0xff;
	
	P2M1 = 0x00;
	P2M0 = 0xff;
	
}
void  DotLed_Renew(void)
{
//	static	unsigned char Time1s_Cnt = 0;
//	
//	unsigned char i;
//	static  bit Love_Flag = 0;
//	
//	Time1s_Cnt ++;
//	if( Time1s_Cnt >=100)
//	{
//		 Time1s_Cnt = 0;
//		
//		 Love_Flag = !Love_Flag;
//	}
//	
//	
//	if( Love_Flag)//空心
//	{
//		for(i=0;i<8;i++)
//		{
//			Dot_Tab[i] = 	Love_Tab1[i];
//		}
//	}
//	else//实心
//	{
//		for(i=0;i<8;i++)
//		{
//			Dot_Tab[i] =  Love_Tab2[i];
//		}	
//		
//	}
//	
  unsigned char i;
	
  if(Rec_Val == 0x55)
	{
		Rec_Val = 0;
		for(i=0;i<8;i++)
		{
	  	Dot_Tab[i] = 	Love_Tab1[i];
	  }
	}
	if(Rec_Val == 0xaa)
	{
		Rec_Val = 0;
		for(i=0;i<8;i++)
		{
	  	Dot_Tab[i] = 	Love_Tab2[i];
	  }
	}
}