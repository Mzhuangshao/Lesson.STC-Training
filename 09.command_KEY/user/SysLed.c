#include "SysLed.h"

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