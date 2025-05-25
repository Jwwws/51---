#include <REGX52.H>
#include "Timer0.h"
#include "Delay.h"
#include "LCD1602.h"
unsigned char sec,min,hour;
void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"Clock:");
	LCD_ShowString(1,1,"  :  :");
	Timer0_Init();
	while(1)
	{
		LCD_ShowNum(2,1,hour,2);
		LCD_ShowNum(2,4,min,2);
		LCD_ShowNum(2,7,sec,2);
		
	}
	
	
	
}
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TH0=0x18;//每次进中断都要重新赋值初始值，因为每次进中断是因为溢出了，而溢出了之后会导致原先数据重新为0，如果不赋初始值则会导致新的计时不为1ms
	TL0=0xFC;
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{
				min=0;
				hour++;
				if(hour>=24)
					hour=0;
			}
		}		
	}
}