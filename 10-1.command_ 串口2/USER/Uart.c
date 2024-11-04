#include "Uart.H"		//包含头文件 自己创建的！！！！


volatile  unsigned int Rec_Val = 0;  //定义全局变量，用于存放串口1接收到的数据
static bit busy = 0;  //定义静态全局变量，注意这个全局不怎么全局，只是在文本件中使用

void SendData(unsigned char dat);
void SendMsg(char *s);


void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x01;		//串口1选择定时器2为波特率发生器
	AUXR |= 0x04;		//定时器2时钟为Fosc,即1T
	T2L = 0xE0;		//设定定时初值
	T2H = 0xFE;		//设定定时初值
	AUXR |= 0x10;		//启动定时器2
	
  ES = 1;	      //开放串口1中断
	EA = 1;       //开放总中断
	
	SendMsg("STC15F2K60S2\r\n I am Ready !\r\n 我爱中国！\r\n");//
	
}

/*----------------------------
UART 中断服务程序
-----------------------------*/
void Uart(void) interrupt 4
{
    if (RI)                     //接收到一个数据
    {
        RI = 0;                 //清除RI位
        P0 = SBUF;              //P0显示串口数据
        Rec_Val =  SBUF;        //将接收到数据存入变量，以供其他地方使用
				SBUF = Rec_Val;        //写SBUF，其实就是发送！
//			  if((Rec_Val >= '1')&&(Rec_Val <= '8'))
//				{
//					SBUF = 'Y';
//				}
//				else
//				{
//					SBUF = 'N';
//				}
    }		
    if (TI)                     //一个数据发送完成
    {
        TI = 0;                 //清除TI位
        busy = 0;               //清忙标志
    }
}

/*----------------------------
发送串口数据
----------------------------*/
void SendData(unsigned char dat)
{
    while (busy);               //等待前面的数据发送完成
    busy = 1;
    SBUF = dat;                 //写数据到UART数据寄存器
}

/*----------------------------
发送字符串
----------------------------*/
void SendMsg(char *s)
{
    while (*s)                  //检测字符串结束标志
    {
        SendData(*s++);         //发送当前字符
    }
}
