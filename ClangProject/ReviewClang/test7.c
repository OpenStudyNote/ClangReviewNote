/*
编写一个计算机快递费的程序
（1） 起重（首重）1公斤按起重资费计算（不足1公斤，按1公斤计算）
	  超过首重的重量，按公斤（不足1公斤，按1公斤计算）收取续重费；
（2） 同城起重资费10元，续重3元/公斤；
（3） 寄往1区（江浙两省）的邮件，起重资费10元，续重4元；
（4） 寄往其他地区的邮件，起重资费统一为15元。
	而续重部分，不同区域价格不同：2区的续重5元/公斤，3区的续重6.5元/公斤，4区的续重10元/公斤。
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
