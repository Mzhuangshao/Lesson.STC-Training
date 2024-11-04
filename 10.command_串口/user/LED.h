#ifndef __LED_H_
#define __LED_H_

#include "data.h"

unsigned char code light1_Tab[];
//unsigned char code light2_Tab[];
//unsigned char code light3_Tab[];
unsigned char code light4_Tab[];
//unsigned char code light5_Tab[];
//unsigned char code light_P45[];
//extern volatile unsigned char lightCount ;

void LED_Display();
//void nor_LED();
//void light1();        //all lights 0.5s 全部闪三次
//void light2();        //P00 to P07 0.2s 从低到高
//void light3();        //P07 to P00 0.2s 从高到低
//void light4();        //P00 P07 to 0.1s 低到高依次点亮,高到低熄灭
//void light5();        //中间扩散


#endif