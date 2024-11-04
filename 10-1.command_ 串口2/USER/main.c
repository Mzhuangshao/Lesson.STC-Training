#include "Timer.H"		//包含头定时器头文件
#include "SysLed.H"		//包含系统灯头文件
#include "Buzzer.H"	
#include "DotLed.H"
#include "LSD.H"      //包含流水灯头文件
#include "Uart.H"
#include "command.H"
//主函数
void	main(void) 
{
	Timer0Init();
	Timer1Init();
	DotLed_Init();
	UartInit();
	Beep_Init();
	
	while(1)		
	{
		
		if(Flag_1ms)
		{
			Flag_1ms = 0;
			
			DotLed_Display();
			
		}
		if(Flag_10ms)
		{
			Flag_10ms = 0;
			
			poem();
			SysLed_Display();
			DotLed_Renew();
	    Lsd_Led();
			Buzzer_Handle();
			
		}
	}
}