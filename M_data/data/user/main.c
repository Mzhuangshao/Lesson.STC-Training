#include "data.H"
sbit BitMap1 = P3^2;  //P32
sbit BitMap2 = P4^1;  //P41
sbit BitMap3 = P3^3;  //P33
sbit BitMap4 = P3^6;  //P36
sbit BitMap5 = P4^4;  //P44
sbit BitMap6 = P3^4;  //P34
sbit BitMap7 = P4^2;  //P42
sbit BitMap8 = P3^5;  //P35
sbit S1 = P5^4;
sbit S2 = P5^5;
unsigned char code tab[]={0xfe,0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f,0xff};
static unsigned char code Heart0[] = {0x00,0x36,0x49,0x41,0x22,0x14,0x08,0x00};//空心
static unsigned char code Heart1[] = {0x00,0x36,0x7f,0x7f,0x3e,0x1c,0x08,0x00};//实心
volatile unsigned int BitMapTab[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
bit M1 = 0;
unsigned char KEY1_COUNT = 0;

void buttonCheck();
void button();
void button1();
void BitMap_Display();
void BitMap_Init();
void BitMap();

 void main(void)
	{
		BitMap_Init();
		P0 = 0xff;
		while(1)
		{
			button1();
			BitMap();
			BitMap_Display();
			
		}
}

void buttonCheck(void)
{
	unsigned char i, j;
	for(i=0;i<100;i++)
	{	
		for(j=0;j<200;j++);
	}
}
void button1()
{
	if(S1==0)
	{
		buttonCheck();
		 if(S1==0)
			{ 
				M1 = !M1;
				KEY1_COUNT ++;
				while(S1==0);
			}
			if(KEY1_COUNT >= 2)
			{
				KEY1_COUNT == 0;
			}
	 }
}
void BitMap_Display()		
{
	static unsigned char accept_count = 0;
	BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
	accept_count++;
	if(accept_count > 8)
	{
		accept_count = 1;
	}
	P2 = BitMapTab[accept_count - 1];
	switch(accept_count)
	{
		case 1:BitMap1 = 1;break;
		case 2:BitMap2 = 1;break;
		case 3:BitMap3 = 1;break;
		case 4:BitMap4 = 1;break;
		case 5:BitMap5 = 1;break;
		case 6:BitMap6 = 1;break;
		case 7:BitMap7 = 1;break;
		case 8:BitMap8 = 1;break;
		default:break;
	}
}
void BitMap()
{
	unsigned char i ;
	if(M1)										//触发器检测
	{
		for(i=0;i<8;i++)									//空心
		{
		BitMapTab[i] = ~Heart0[i] ;
		}
	}
	else
	{
		for(i=0;i<8;i++)									//实心
		{
		BitMapTab[i] = ~Heart1[i] ;
		}
	}
}
void BitMap_Init()  //推挽输出
{
	P2M1 &= 0x00;
	P2M0 |= 0xff;
	
	P3M1 &= 0xfb;
	P3M0 |= 0x04;
	
	P4M1 &= 0xfd;
	P4M0 |= 0x02;
	
	P3M1 &= 0xf7;
	P3M0 |= 0x08;
	
	P3M1 &= 0xbf;
	P3M0 |= 0x40;
	
	P4M1 &= 0xef;
	P4M0 |= 0x10;
	
	P3M1 &= 0xef;
	P3M0 |= 0x10;
	
	P4M1 &= 0xfb;
	P4M0 |= 0x04;
	
	P3M1 &= 0xdf;
	P3M0 |= 0x20;
	
	P2 = 0x00;
	BitMap1 = 0;BitMap2 = 0;BitMap3 = 0;BitMap4 = 0;BitMap5 = 0;BitMap6 = 0;BitMap7 = 0;BitMap8 = 0;
}