#ifndef __Timer_H_
#define __Timer_H_

#include "STC15F.H"		//������Ƭ��ͷ�ļ�


void Timer0Init(void);		//1����@11.0592MHz  �ڸ��Ե�ͷ�ļ������������������ط�����

void Timer1Init(void);		//10����@11.0592MHz �ڸ��Ե�ͷ�ļ������������������ط�����

//�������Բ�extern������ 
//��ô��Ҫ������������ʱ�򣬲��ܳ�ʼ������
extern	volatile	bit		Flag_1ms,Flag_10ms;//����2��ȫ�ֱ�����ÿ����Ӧ�Ķ�ʱ����ʱ����Ϊ1����ʾʱ�䵽��

#endif  	//����

