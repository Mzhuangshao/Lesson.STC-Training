#include "SysLed.h"			//P45系统灯头文件			

void SysLED()
{
	{
	static unsigned int SysLED_Count = 0;
	 SysLED_Count ++;
		if(SysLED_Count >= 25)
		{
			SysLED_Count = 0;
			P45 = !P45;
		}
	}
}