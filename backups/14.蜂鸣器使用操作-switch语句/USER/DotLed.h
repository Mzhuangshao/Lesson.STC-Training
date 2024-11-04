#ifndef __DotLed_H_
#define __DotLed_H_

#include "STC15F.H"		//包含单片机头文件


extern	volatile	unsigned char Dot_Tab[8];//定义点阵显示数组，或者称之为缓冲，并初始化为显示心形

void	DotLed_Init(void);

void	DotLed_Display(void);
void  DotLed_Renew(void);

#endif  	//结束

