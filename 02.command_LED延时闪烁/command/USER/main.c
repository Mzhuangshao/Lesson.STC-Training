#include "STCF5.H"
		
void Delay100ms(void)									//set colock-100ms @11.0592MHz
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


 void main(void)                     // LED
	{
		while(1)
		{
			P45 = 0;
			Delay100ms();
			P45 = 1;
			Delay100ms();
		}
			do
			{
				while(1)
				{
					P0 = 0xfe;
					Delay100ms();
					P0 = 0xdf;
					Delay100ms();
				}
			}
	}