#include "Timer.H"		//����ͷ��ʱ��ͷ�ļ�
#include "SysLed.H"		//����ϵͳ��ͷ�ļ�
#include "Buzzer.H"	
#include "DotLed.H"
#include "LSD.H"      //������ˮ��ͷ�ļ�
#include "Uart.H"
#include "command.H"
//������
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