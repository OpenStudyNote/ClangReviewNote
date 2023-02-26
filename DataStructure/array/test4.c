/*
	编程计算两个正整数的最大公约数,输出最大公约数。
*/

#include<stdio.h>
//输出最大公约数函数
int MaxCommonFactor( int a, int b)
{ 
	int c; 
	if(a<=0||b<=0) 
		return -1; 
	while(b!=0)
	{ 
		c=a%b; 
		a=b;
		b=c;
	} 
	return a; 
}   
int main(void)
{  
	/*********Begin*********/
	int a,b;
	int MaxCommonNum;
	scanf("%d %d",&a,&b);
	MaxCommonNum = MaxCommonFactor(a,b);
	printf("%d",MaxCommonNum);
	/*********End**********/ 
	return 0;
}

