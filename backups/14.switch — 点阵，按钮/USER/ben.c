#include "ben.H"//包含头文件，定时器有关

void ben_Mode1(void)
{
	static unsigned char Time200ms_Cnt = 0;
	static unsigned char ben_status = 0;
	
	Time200ms_Cnt ++;
	if(Time200ms_Cnt >= 20)
	{
		Time200ms_Cnt = 0;
		ben_status ++;
		
	}
	switch(ben_status)
	{
		case  0:P0 = 0xff; break;
    case  1:P0 = 0xfe; break;
		case  2:P0 = 0xfd; break;
		case  3:P0 = 0xfb; break;
	  case  4:P0 = 0xf7; break;
		case  5:P0 = 0xef; break;
	  case  6:P0 = 0xdf; break;
		case  7:P0 = 0xbf; break;
		case  8:P0 = 0x7f;ben_status = 0; break;	
	}
}