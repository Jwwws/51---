#include <REGX52.H>
/**
  * @brief  定时器0初始化，1ms
  * @param 	无
  * @retval 
  */

void Timer0_Init()
{
	//TMOD=0x01; 不使用直接赋值代码，因为如果有其他的程序编辑了定时器1，直接操作会导致定时器1的配置被直接抹除掉
	TMOD=TMOD&0xF0;//高4位保持不变，第四位清零
	TMOD=TMOD|0x01;//TOMD最低位置1
	TF0=0;
	TR0=1;
	TH0=0x18;
	TL0=0xFC;//为什么时64535？因为总共可计时时间位65535ns，差1000ns即1ms即可进行跳转
	ET0=1;
	EA=1;
	PT0=0;
}

/* TIMER0中断模板
void Timer0_Routine() interrupt 1
{
	static unsigned int T0Count;
	TH0=0x18;//每次进中断都要重新赋值初始值，因为每次进中断是因为溢出了，而溢出了之后会导致原先数据重新为0，如果不赋初始值则会导致新的计时不为1ms
	TL0=0xFC;
	T0Count++;
	if(T0Count>=1000)
	{
		T0Count=0;
	}
}*/
