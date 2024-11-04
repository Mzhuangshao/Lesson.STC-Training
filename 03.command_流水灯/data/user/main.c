#include "LSD.H"

void Delay80ms(); 					//clock-50ms

 void main(void)
 {
	 while(1)
	 {
		 P00 = 1;
		 Delay80ms();
		 P01 = 1;
		 Delay80ms();
		 P02 = 1;
		 Delay80ms();
		 P03 = 1;
		 Delay80ms();
		 P04 = 1;
		 Delay80ms();
		 P05 = 1;
		 Delay80ms();
		 P06 = 1;
		 Delay80ms();
		 P07 = 1;
		 Delay80ms();
		 P00 = 0;
		 Delay80ms();
		 P01 = 0;
		 Delay80ms();
		 P02 = 0;
		 Delay80ms();
		 P03 = 0;
		 Delay80ms();
		 P04 = 0;
		 Delay80ms();
		 P05 = 0;
		 Delay80ms();
		 P06 = 0;
		 Delay80ms();
		 P07 = 0;
		 Delay80ms();
	 }
 }
 

void Delay80ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 4;
	j = 93;
	k = 155;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


