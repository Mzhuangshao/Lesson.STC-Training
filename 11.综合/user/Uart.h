#ifndef __Uart_H_
#define __Uart_H_

#include "data.H"		//包含单片机头文件
#include "command.h"

void UartInit(void);
void SendData(unsigned char dat);
void SendMsg(char *s);


extern volatile  unsigned int Rec_Val;  //定义全局变量，用于存放串口1接收到的数据
#endif  	//结束

