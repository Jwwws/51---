#include <REGX52.H>
#include "Delay.h"
/**
  * @brief  获取独立按键键码
  * @param 无
  * @retval 按下按键的键码，范围0-4.
  */
unsigned char Key()
{
	unsigned char KeyNumber=0;
	if(P3_1==0)
	{delay(20);
		while(P2_1==0);
		delay(20);
		KeyNumber=1;
	}
	if(P3_0==0)
	{delay(20);
		while(P2_0==0);
		delay(20);
		KeyNumber=2;
	}
	if(P3_2==0)
	{delay(20);
		while(P2_2==0);
		delay(20);
		KeyNumber=3;
	}
	if(P3_3==0)
	{delay(20);
		while(P2_3==0);
		delay(20);
		KeyNumber=4;
	}
	
	
	
	
	return KeyNumber;
}