#ifndef __Timer_H_
#define __Timer_H_

#include "STC15F.H"                  //包含单片机头文件


void Timer0Init(void);		//1毫秒@11.0592MHz

void Timer1Init(void);		//010毫秒@11.0592MHz



extern  volatile bit Flag_1ms ,Flag_10ms  ;//定义1个全局变量，每隔相应的定时到达时，设为1！表示时间到了


#endif        // 结束

