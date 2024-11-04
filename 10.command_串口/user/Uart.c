#include "Uart.h"

volatile unsigned char Uart_Val = 0;
static bit WORKING = 0;

void Send_Data(unsigned char dat);
void SendMsg(char *s);

void UartInit(void)		//9600bps@11.0592MHz
{
	SCON = 0x50;	
	AUXR |= 0x01;
	AUXR &= 0xFB;	
	T2L = 0xE8;	
	T2H = 0xFF;
	AUXR |= 0x10;	
	
	ES = 1;
	EA = 1;
	
	//SendMag("STC15F2K60S2\r\n READY \r\n ESM \r\n");
}

void Uart(void) interrupt 4
{
	if(RI)
	{
		RI = 0;
		P0 = SBUF;
		Uart_Val = SBUF;
	}
	if(TI)
	{
		TI = 0;
		WORKING = 0;
	}
}

void Send_Data(unsigned char dat)
{
	while(WORKING);
	WORKING = 1;
	SBUF = dat;
}

void SendMsg(char *s)
{
	while(*s)
	{
		Send_Data(*s++);
	}
}