#include <REGX52.H>
void Delay1ms(int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms){
	i = 12;
	j = 169;
	do
	{
		while (--j);
	} while (--i);
	xms--;
}
}

void main(){
	unsigned char LEDNum=0;//unsigned charΪ8λ��һ���ʾĳ���Ĵ���
	while(1){
		if(P3_1==0){
			Delay1ms(20);
			while(P3_1==0);
			Delay1ms(20);
			
			LEDNum++;
			P2=~LEDNum;
}
