#ifndef __DotLed_H_
#define __DotLed_H_

#include "STC15F.H"		//������Ƭ��ͷ�ļ�


extern	volatile	unsigned char Dot_Tab[8];//���������ʾ���飬���߳�֮Ϊ���壬����ʼ��Ϊ��ʾ����

void	DotLed_Init(void);

void	DotLed_Display(void);
void  DotLed_Renew(void);

#endif  	//����

