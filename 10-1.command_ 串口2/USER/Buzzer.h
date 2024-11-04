#ifndef __Buzzer_H_
#define __Buzzer_H_

#include "STC15F.H"		//包含单片机头文件
#include "Timer.H"	
#include "Uart.H"		//包含头文件 自己创建的！！！！

void	Beep_Init(void);
void	Buzzer_Handle(void);//函数声明，注意1ms调用一次


#endif  	//结束

