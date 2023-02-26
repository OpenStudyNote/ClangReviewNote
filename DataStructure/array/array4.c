#include<stdio.h>
#include<string.h>
#define N 100
int main()
{
	int i, j, L[N];
	char m[N], n[N];
	scanf("%s %s", m, n);
	int len1 = strlen(m);
	int len2 = strlen(n);
	memset(L, 0, sizeof(L));//初始化为0
	//第一步
	for(i = 0; i < len1; i++)
		for(j = 0; j < len2; j++)
			L[i+j] += (m[len1 - i - 1] - '0') * (n[len2 - j - 1] - '0');//乘运算
	//第二步
	for(i = 0; i < len1 + len2; i++)
		if(L[i] >= 10)
	{
		L[i+1] += L[i] / 10;//进位
		L[i] %= 10;//取余
	}
	//第三步
	while(L[i] == 0)//去零
		i--;
	//输出答案
	while(i >= 0)
		printf("%d", L[i--]);
	return 0;
}

