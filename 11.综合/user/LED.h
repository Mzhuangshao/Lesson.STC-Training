#ifndef __LED_H_
#define __LED_H_

#include "data.h"
#include "KEY.h"

void main_LED();
//void nor_LED();
void light1();        //all lights 0.5s ȫ��������
void light2();        //P00 to P07 0.2s �ӵ͵���
void light3();        //P07 to P00 0.2s �Ӹߵ���
void light4();        //P00 P07 to 0.1s �͵������ε���,�ߵ���Ϩ��
void light5();        //�м���ɢ
void light6();				//0x55 0xaa
void light_test();


#endif