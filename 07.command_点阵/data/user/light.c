/*#include "cool.H"

//声明子函数,不写的话程序不认下面的子函数
void Delay100ms();    //clock 0.1s 0.1秒时钟
void Delay200ms();    //clock 0.2s 0.2秒时钟
void Delay500ms();    //clock 0.5s 0.5秒时钟
void light1();        //all lights 0.5s 全部闪三次
void light2();        //P00 to P07 0.2s 从低到高
void light3();        //P07 to P00 0.2s 从高到低
void light4();        //P00 P07 to 0.1s 低到高依次点亮,高到低熄灭
void light5();        //中间扩散

//主函数
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
		P45 = 0;         //系统提示灯提醒你循环一次了,可以不写
		Delay100ms();
		P45 = 1;
		Delay500ms();
	}
}

//定义子函数,为了简洁放在下面而已
void light1(void)   //add function-all lights flash 0.5s 全部闪三次
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

void light2(void)   //add function-P00 to P07 0.2s 从低到高
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
void light3(void)   //P07 to P00 0.2s 从高到低
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
void light4(void)   //P00 P07 to 0.1s 低到高依次点亮,高到低熄灭
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

void light5(void)   //中间扩散
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
	//reset 重置所有灯
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