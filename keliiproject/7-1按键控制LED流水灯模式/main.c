#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.h>
unsigned char KeyNum,LedMode;
void main()
{
	P2=0xFE;
	Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			if(KeyNum==1)
			{
				LedMode++;
				if(LedMode>=2)LedMode=0;
			}
		
	}
	
}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TH0=0x18;//每次进中断都要重新赋值初始值，因为每次进中断是因为溢出了，而溢出了之后会导致原先数据重新为0，如果不赋初始值则会导致新的计时不为1ms
	TL0=0xFC;
	T0Count++;
	if(T0Count>=500)
	{
		T0Count=0;
		if(LedMode==0)
			P2=_crol_(P2,1);//_crol_函数在INTRINS头文件中，实现循环左移，在不会将数字移出，而是会实现循环的移动
		if(LedMode==1)
			P2=_cror_(P2,1);//_cror_实现循环右移
	}
}