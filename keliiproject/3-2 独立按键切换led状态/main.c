#include <REGX52.H>

void Delay20ms()		
{
	unsigned char i, j;

	i = 39;
	j = 230;
	do
	{
		while (--j);
	} while (--i);
}

void main()
{
	while(1)
	{
		if(P3_0==0)
		{
			Delay20ms();
			while(P3_0==0);
			Delay20ms();
			P2_0=~P2_0;
			
		}
		
	}
}
