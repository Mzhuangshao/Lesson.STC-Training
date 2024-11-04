#ifndef __rad_H_
#define __rad_H_

#include "DotLed.H"
#include "Timer.H"
#include "STC15F.H"                //包含单片机头文件



//预定义
#define  K1  P55
#define  K2  P54

extern	volatile bit  rad_Valid_Flag;
extern volatile bit  K1_Flag;
extern volatile bit  K2_Flag;


void  K1_Check(void);
void  K2_Check(void);

#endif        // 结束

