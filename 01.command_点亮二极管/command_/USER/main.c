#include "STCF5.H"


void Delay500ms(void)		//@11.0592MHz
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


 void main(void)
	{
		while(1)
		{
			P45 = 0;
			Delay500ms();
			P45 = 1;
			Delay500ms();
		}
	}
	