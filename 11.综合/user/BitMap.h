#ifndef __BitMap_H_
#define __BitMap_H_

#include "data.h"
#include "KEY.h"
sbit BitMap1 = P3^2;  //P32
sbit BitMap2 = P4^1;  //P41
sbit BitMap3 = P3^3;  //P33
sbit BitMap4 = P3^6;  //P36
sbit BitMap5 = P4^4;  //P44
sbit BitMap6 = P3^4;  //P34
sbit BitMap7 = P4^2;  //P42
sbit BitMap8 = P3^5;  //P35
//unsigned char code Heart0[];
//unsigned char code Heart1[];
extern volatile unsigned int BitMapTab[8];

void BitMap_Display(void);
void BitMap_Init(void);
void main_BitMap(void);
#endif