#ifndef __Uart_H_
#define __Uart_H_

#include "data.H"		//������Ƭ��ͷ�ļ�
#include "command.h"

void UartInit(void);
void SendData(unsigned char dat);
void SendMsg(char *s);


extern volatile  unsigned int Rec_Val;  //����ȫ�ֱ��������ڴ�Ŵ���1���յ�������
#endif  	//����

