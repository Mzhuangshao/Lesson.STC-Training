/*#include "cool.H"

//�����Ӻ���,��д�Ļ�������������Ӻ���
void Delay100ms();    //clock 0.1s 0.1��ʱ��
void Delay200ms();    //clock 0.2s 0.2��ʱ��
void Delay500ms();    //clock 0.5s 0.5��ʱ��
void light1();        //all lights 0.5s ȫ��������
void light2();        //P00 to P07 0.2s �ӵ͵���
void light3();        //P07 to P00 0.2s �Ӹߵ���
void light4();        //P00 P07 to 0.1s �͵������ε���,�ߵ���Ϩ��
void light5();        //�м���ɢ

//������
void main(void)
{
	while(1)
	{
		light2();
		light1();
		light3();
		light1();
		light4();
		light1();
		light5();
		light1();
		P45 = 0;         //ϵͳ��ʾ��������ѭ��һ����,���Բ�д
		Delay100ms();
		P45 = 1;
		Delay500ms();
	}
}

//�����Ӻ���,Ϊ�˼������������
void light1(void)   //add function-all lights flash 0.5s ȫ��������
{
	P0 = 0xff;
	Delay500ms();
	P0 = 0x00;
	Delay500ms();
	P0 = 0xff;
	Delay500ms();
	P0 = 0x00;
	Delay500ms();
	P0 = 0xff;
	Delay500ms();
	P0 = 0x00;
	Delay500ms();
	P0 = 0xff;
	Delay500ms();
}

void light2(void)   //add function-P00 to P07 0.2s �ӵ͵���
{
	P00 = 0;
	Delay200ms();
	P01 = 0;
	Delay200ms();
	P02 = 0;
	Delay200ms();
	P03 = 0;
	Delay200ms();
	P04 = 0;
	Delay200ms();
	P05 = 0;
	Delay200ms();
	P06 = 0;
	Delay200ms();
	P07 = 0;
	Delay200ms();
}
void light3(void)   //P07 to P00 0.2s �Ӹߵ���
{
	P07 = 0;
	Delay200ms();
	P06 = 0;
	Delay200ms();
	P05 = 0;
	Delay200ms();
	P04 = 0;
	Delay200ms();
	P03 = 0;
	Delay200ms();
	P02 = 0;
	Delay200ms();
	P01 = 0;
	Delay200ms();
	P00 = 0;
	Delay200ms();
}
void light4(void)   //P00 P07 to 0.1s �͵������ε���,�ߵ���Ϩ��
{
	P00 = 0;
	Delay100ms();
	
	P00 = 1;
	P01 = 0;
	Delay100ms();
	
	P01 = 1;
	P02 = 0;
	Delay100ms();
	
	P02 = 1;
	P03 = 0;
	Delay100ms();
	
	P03 = 1;
	P04 = 0;
	Delay100ms();
	
	P04 = 1;
	P05 = 0;
	Delay100ms();
	P05 = 1;
	P06 = 0;
	Delay100ms();
	P06 = 1;
	
	P07 = 0;
	Delay100ms();//
	P07 = 1;
	
	P06 = 0;
	Delay100ms();
	P06 = 1;
	
	P05 = 0;
	Delay100ms();
	P05 = 1;
	P04 = 0;
	Delay100ms();
	P04 = 1;
	P03 = 0;
	Delay100ms();
	P03 = 1;
	P02 = 0;
	Delay100ms();
	P02 = 1;
	P01 = 0;
	Delay100ms();
	P01 = 1;
	P00 = 0;
	Delay100ms();
	P00 = 1;
	Delay100ms();
}

void light5(void)   //�м���ɢ
{
	P0 = 0x7e;
	Delay100ms();
	P0 = 0x3c;
	Delay100ms();
	P0 = 0x18;
	Delay100ms();
	P0 = 0;
	Delay100ms();
	P0 = 0x18;
	Delay100ms();
	P0 = 0x3c;
	Delay100ms();
	P0 = 0x7e;
	Delay100ms();
	//reset �������е�
	P0 = 0xff;
	Delay100ms();
}

void Delay100ms()		//add function-clock 0.1s//@11.0592MHz
{
	unsigned char i, j, k;
	i = 5;
	j = 52;
	k = 195;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay200ms()		//add function-clock 0.2s//@11.0592MHz
{
	unsigned char i, j, k;

	i = 9;
	j = 104;
	k = 139;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void Delay500ms()		//add function-clock 0.5s//@11.0592MHz
{
	unsigned char i, j, k;
	i = 22;
	j = 3;
	k = 227;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}
*/