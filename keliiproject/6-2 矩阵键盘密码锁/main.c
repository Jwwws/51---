#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,Count;
void main(){
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while(1)
	{
		KeyNum=MatrixKey();
		if(KeyNum)
		{
			if(KeyNum<=10)  //s1-s10密码区
			{
				if(Count<4)
					{
					Password*=10;	//密码左移1位
					Password+=KeyNum%10;	//获取一位密码
					Count++;	
					}
				LCD_ShowNum(2,1,Password,4);	
			}
			if(KeyNum==11)	//如果s11按键按下，表示确认
		{
			if(Password==2345)	//如果密码等于正确密码，显示ok
			{
				LCD_ShowString(1,14,"OK ");
				Password=0;
				Count=0;
				LCD_ShowNum(2,1,Password,4);
			}
			else {
				LCD_ShowString(1,14,"ERR");
				Password=0;
				Count=0;
				LCD_ShowNum(2,1,Password,4);
			}
		}
		if(KeyNum==12)
		{
			Password=0;
			Count=0;
			LCD_ShowNum(2,1,Password,4);
		}
		}

}
}
