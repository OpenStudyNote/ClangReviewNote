/*
输入
从键盘输入一个成绩，成绩可以使浮点数。

输出
(1)如果输入数据在0到100范围内：一个字符，表示成绩等级。
(2)如果输入数据不在0~100范围内，请输出一行：“Score is error!”
*/
#include<stdio.h>

int main(void)
{  

	float Score;
	printf("分数测试 Input Score:\n");
	scanf("%f",&Score);
	if(Score>=0&&Score<=100)
	{
		if(Score>=90)
			printf("A");
		else if(Score>=80&&Score<=89)
			printf("B");
		else if(Score>=70&&Score<=79)
			printf("C");
		else if(Score>=60&&Score<=69)
			printf("D");
		else
			printf("E");
	}

	else
	{
		printf("Score is error!");
	}
	

	return 0;
}
