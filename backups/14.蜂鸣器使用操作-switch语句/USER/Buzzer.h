#ifndef __Buzzer_H_
#define __Buzzer_H_

#include "STC15F.H"		//包含单片机头文件
#include "Timer.H"	

void  Beep_Init(void);
void  Beep_ON();
void  Beep_OFF();
void  Buzzer_Handle(void);
#endif  	//结束

