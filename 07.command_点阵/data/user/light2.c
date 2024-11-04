#include "cool.H"

//�����Ӻ���,��д�Ļ�������������Ӻ���
void Delay100ms();    //clock 0.1s 0.1��ʱ��
//void Delayx100ms(2);    //clock 0.2s 0.2��ʱ��
//void Delayx100ms(5);    //clock 0.5s 0.5��ʱ��
void Delayx100ms(unsigned char x100ms);
void light1();        //all lights 0.5s ȫ��������
void light2();        //P00 to P07 0.2s �ӵ͵���
void light3();        //P07 to P00 0.2s �Ӹߵ���
void light4();        //P00 P07 to 0.1s �͵������ε���,�ߵ���Ϩ��
void light5();        //�м���ɢ
unsigned char code light1_Tab[] = {0xff,0x00,0xff,0x00,0xff,0x00,0xff};
unsigned char code light2_Tab[] = {0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00,0xff};
unsigned char code light3_Tab[] = {0x7f,0x3f,0x1f,0x0f,0x07,0x03,0x01,0x00,0xff};
unsigned char code light4_Tab[] = {0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe,0xff};
unsigned char code light5_Tab[] = {0x7e,0x3c,0x18,0x00,0x18,0x3c,0x7e,0xff};
unsigned char code light_P45[] = {0,1};
//
//������
//
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
		Delayx100ms(6);
		P45 = 1;
		Delayx100ms(3);
	}
}
//
//
//�����Ӻ���
void light1(void)   //add function-all lights flash 0.5s ȫ��������
{
	unsigned int i;
	i = 7;
	while(i>0)
	{
	 P0 = light1_Tab[7-i];
	 Delayx100ms(3);
	 i--;
	}
}
void light2(void)   //add function-P00 to P07 0.2s �ӵ͵���
{
  unsigned int i;
	for(i=9;i>0;i--)
	{
		P0 = light2_Tab[9-i];
		Delayx100ms(2);
	}
}
void light3(void)   //P07 to P00 0.2s �Ӹߵ���
{
 unsigned int i;
	for(i=0;i<8;i++)
	{
		P0 = light3_Tab[i];
		Delayx100ms(2);
	}
}
void light4(void)   //P00 P07 to 0.1s �͵������ε���,�ߵ���Ϩ��
{
	 unsigned int i;
	for(i=16;i>0;i--)
	{
		P0 = light4_Tab[16-i];
		Delayx100ms(2);
	}
}

void light5(void)   //�м���ɢ
{
	unsigned int i;
	for(i=0;i<8;i++)
	{
		P0 = light5_Tab[i];
		Delayx100ms(3);
	}
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

void Delayx100ms(unsigned char x100ms)
{
	while(x100ms)
	{
		Delay100ms();
		x100ms --;
	}
}

