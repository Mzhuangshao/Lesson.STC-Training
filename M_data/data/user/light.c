//#include "data.H"

//void wdnmd(void);

//void Delay100ms()		//add function-clock 0.1s//@11.0592MHz
//{
//	unsigned char i, j, k;
//	i = 5;
//	j = 52;
//	k = 195;
//	do
//	{
//		do
//		{
//			while (--k);
//		} while (--j);
//	} while (--i);
//}


//void Delay500ms()		//add function-clock 0.5s//@11.0592MHz
//{
//	unsigned char i, j, k;
//	i = 22;
//	j = 3;
//	k = 227;
//	do
//	{
//		do
//		{
//			while (--k);
//		} while (--j);
//	} while (--i);
//}


//void wd(void)
//{
//	P45 = 0;
//		Delay100ms();
//	  P45 = 1;
//	  Delay100ms();
//		wdnmd();
//	while(1)
//	{
//  }
//}

//void wdnmd(void)
//{
//  P0 = 0xff;
//	Delay100ms();
//	P0 = 0x55;
//	Delay500ms();
//}