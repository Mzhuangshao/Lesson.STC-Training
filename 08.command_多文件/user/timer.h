#ifndef __timer_H_
#define __timer_H_

#include "data.h"

void Timer0Init(void);
void Timer1Init(void);
void Timer2Init(void);
extern volatile bit trigger_1ms, trigger_10ms, trigger_250us ;

#endif

