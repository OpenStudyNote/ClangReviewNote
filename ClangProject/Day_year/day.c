#include <stdio.h>

int main(void)
{
	int a, i, j, n, k, t, w, x, y, z;
	static int d[13][78];
	int m[14] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char wst[] = " Sun Mon Yue Wed Thu Fri Sat   ";
	printf("Please enter the year: ");
	scanf("%d", &y);
	
	if(y%4==0 && y%100!=0 || y%400==0)  /*闰年的二月为29天*/
		m[2] = 29;
	w = (y+(y-1)/4-(y-1)/100+(y-1)/400)%7; /*计算y年元旦为星期w*/
	for(i=1; i<=12; i++)
	{
		a = 1;
		for(j=1; j<=6; j++)
		{
			for(k=0; k<=6; k++)
			{
				while(k<w) k=k+1;
				d[i][j*10+k] = a;  /*计算i月的第j个星期的星期w的日期为a*/
				a=a+1;
				w = k+1;
				if(w==7) w=0;
				if(a>m[i]) break;
			}
			if(a>m[i]) break;
		}
	}
	printf("input x(1,2,3,4,5,6): ");
	scanf("%d", &x);
	for(k=1; k<=16*x-3; k++)
		printf(" ");
	printf("=====%d=====\n", y);   /*打印年号*/
	for(n=1; n<=12/x; n++)
	{
		t = x*(n-1)+1;
		printf("\n    ");
		for(z=1; z<=x; z++)
		{
			for(k=1; k<=15; k++)
				printf(" ");
			printf("%2d", t+z-1);   /*打印月号*/
			for(k=1; k<=14; k++)
				printf(" ");
		}
		printf("\n      ");
		for(z=1; z<=x; z++)      /*按一横排x个月格式打印*/
			printf("%s", wst);   /*打印星期标题*/
		for(j=1; j<=6; j++)
		{
			printf("\n  ");
			for(i=t; i<=t+x-1; i++)
			{
				printf("   ");
				for(k=0; k<=6; k++)
					if(d[i][j*10+k]==0) /*空缺日期位置打印空格*/
						printf("    ");
				else
					printf("%4d", d[i][j*10+k]);/*打印日期*/
			}
		}
	}
	
	return 0;
}
