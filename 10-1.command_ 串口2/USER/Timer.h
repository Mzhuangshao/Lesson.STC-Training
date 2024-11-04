#ifndef __Timer_H_
#define __Timer_H_

#include "STC15F.H"		//包含单片机头文件


void Timer0Init(void);		//1毫秒@11.0592MHz  在各自的头文件中声明，可在其他地方调用

void Timer1Init(void);		//10毫秒@11.0592MHz 在各自的头文件中声明，可在其他地方调用

//请自行脑补extern的作用 
//特么重要：声明变量的时候，不能初始化变量
extern	volatile	bit		Flag_1ms,Flag_10ms;//定义2个全局变量，每隔相应的定时到达时，设为1！表示时间到了

#endif  	//结束

