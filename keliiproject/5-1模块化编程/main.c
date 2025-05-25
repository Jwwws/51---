#include <REGX52.H>
#include "Delay.h"//自己写的一般使用双引号
#include "Nixie.h"
void main()
{
	while(1)
	{
		Nixie(1,1);
		Nixie(2,2);
		Nixie(3,3);
	}
}