#include "Buzzer.H"	

void  Beep_Init(void)
{
	P3M1 &= 0x7f;
	P3M0 |= 0x80;
	CCON = 0;
	
	CL = 0;
	CH = 0;
	CMOD = 0x00;
	PCA_PWM2 = 0x00;
	CCAP2H = CCAP2L = 125;
	CCAPM2 = 0x42;
	
	CR	= 1;
}

void  Beep_ON()
{
  CR = 1;
}

void  Beep_OFF()
{
   CR = 0;
}

void  Buzzer_Handle(void)
{
   static unsigned char Time200ms_Cnt = 0;
   static unsigned char Buzzer_Status = 0;
	
	 Time200ms_Cnt ++;
	 if(Time200ms_Cnt >= 20)
	 {
      Time200ms_Cnt = 0;
      Buzzer_Status ++;
		 
		 if(Buzzer_Status >= 5)
		 {
        Buzzer_Status = 0;
     }	 
   }
	 switch(Buzzer_Status)
	 {
     case 0:Beep_ON();break;
		 case 1:Beep_ON();break;
		 case 2:Beep_OFF();break;
		 case 3:Beep_OFF();break;
		 case 4:Beep_OFF();break;	 
   }
	 
	 
}