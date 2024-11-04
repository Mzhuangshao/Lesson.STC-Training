#ifndef __KEY_H_
#define __KEY_H_

#include "data.h"
#include "Timer.h"
#include "Bleep.h"
#include "BitMap.h"

#define KEY1 P54
#define KEY2 P55
extern volatile bit trigger_KEY_control;
extern volatile bit trigger_KEY1;
extern volatile bit trigger_KEY2;

void KEY1_CHECK();
void KEY2_CHECK();

#endif

