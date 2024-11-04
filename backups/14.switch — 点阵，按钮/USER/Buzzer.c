#include "Buzzer.H"//

void Beep_Inte(void)
{
  static unsigned int Time100ms_Cnt = 0;
	if(rad_Valid_Flag)
	{
		P37 = !P37;
		Time100ms_Cnt ++;
		if(Time100ms_Cnt >= 100)
		{
			Time100ms_Cnt = 0;
			rad_Valid_Flag = 0;	
		}
	}
	else 
	{
		P37 = 0;
		Time100ms_Cnt = 0;
	}
}