#include "DotLed.H"		//包含头文件，定时器有关 自己创建的！！！！

/*
** 点阵驱动函数
** 每隔1ms调用一次，共8行，所以8ms刷新一遍
** 这个一个共阳点阵，行给1对应行工作，列对应位给0则对应行对应的点被点亮
*/

static	unsigned char Love_Tab1[] = {0xff,0x93,0x6d,0x7d,0xbb,0xd7,0xef,0xff};
static  unsigned char Love_Tab2[] = {0xff,0x93,0x01,0x01,0x83,0xc7,0xef,0xff};

volatile	unsigned char Dot_Tab[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,};//定义点阵显示数组，或者称之为缓冲，并初始化为显示心形


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

//有点暴力，只顾点阵，不顾他人
void	DotLed_Init(void)
{
	//将P3口配置为推挽输出
	P3M1 = 0x00;
	P3M0 = 0x7f;
	
	P4M1 = 0x00;
	P4M0 = 0xff;
	
	P2M1 = 0x00;
	P2M0 = 0xff;
	
}

void  DotLed_Renew(void)   //更新点阵显示的内容
{
  static	unsigned char	Time1s_Cnt = 0;
          unsigned char i;
  static  bit  Love_Flag = 0;

  Time1s_Cnt ++;
	if(Time1s_Cnt >= 100)
	{
  Time1s_Cnt = 0;
	Love_Flag = !	Love_Flag;
  }

	if(Love_Flag)//空心
	{
     for(i=0;i<8;i++)
     {
      Dot_Tab[i] = Love_Tab1[i];
     }
  }
  else//实心
	{
    for(i=0;i<8;i++)
    {
      Dot_Tab[i] = Love_Tab2[i];
    }
  }	

}




