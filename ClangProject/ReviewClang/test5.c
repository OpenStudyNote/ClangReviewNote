/*
	从键盘输入三个整数按从小到大的顺序输出
	三个数比较大小,需要交换,才按照原变量格式输出。
	a=3,b=2,c=1;
	if(a>b)  a,b交换-->a=2,b=3;
	if(a>c)  a,c交换-->a=1,c=2;
	if(b>c)  b,c交换-->b=2,c=3;
	
	实例要求从键盘输入任意年份的整数 N，通过程序运行判断该年份是否为闰年。
	算法思想
	判断任意年份是否为闰年，需要满足以下条件中的任意一个：
	① 该年份能被 4 整除同时不能被 100 整除；
	② 该年份能被400整除
*/

#include <stdio.h>
void swap(int *p1,int *p2) //交换函数
{
	int p;
	p=*p1;
	*p1=*p2;
	*p2=p;
}
#if 0
int main()
{
	int n1,n2,n3;
	int *p1,*p2,*p3;
	printf("请输入三个整数：");
	scanf("%d %d %d",&n1,&n2,&n3);
	p1=&n1;
	p2=&n2;
	p3=&n3;
	if(n1>n2)
		swap(p1,p2);
	if(n1>n3)
		swap(p1,p3);
	if(n2>n3)
		swap(p2,p3);
	printf("小到大排列为: %d %d %d",n1,n2,n3);
	return 0;
}
#endif


#if 0
int main()
{
	int a,b,c,t;
	printf("请输入三个整数:");
	scanf("%d %d %d",&a,&b,&c);
	if(a>b){
		t=a;
		a=b;
		b=t;
	}
	if(a>c){
		t=a;
		a=c;
		c=t;
	}
	if(b>c){
		t=b;
		b=c;
		c=t;
	}
	printf("从小到大排列为:%d,%d,%d",a,b,c);
	return 0;
}
#endif


#if 0
int main()
{
	
	int year;
	printf("请输入年份:\n");
	scanf("%d",&year);
	if(year%400 == 0){
		printf("%d是闰年！",year);
	}
	else
	printf("%d不是闰年！",year);	
	
	return 0;
}
#endif

#if 0
int main(void)
{  
	/*********Begin*********/
	float x,y;
	printf("分段函数测试 Input x:\n");
	scanf("%f",&x);
	if(x<0&&x!=-3){
		y=x*x+x-6;
	}
	else if(x>=0&&x<10&&x!=2&&x!=3){
		y=x*x-5*x+6;
	}
	else
	{
		y=x*x-x-1;
	}
	
	printf("%.3f",y);
	
	/*********End**********/ 
	return 0;
}

#endif



#if 1

//编写函数
/*********Begin*********/
int fsum(int n)
{
	int sum=0;
	
	for(int i=1;i<=n;i++){
		sum = sum+i;
	}
	
	return sum;
}
/*********End**********/ 
int main(void)
{  
	/*********Begin*********/
	int num;
	int Numsum=0;
	printf("Input Number n:\n");
	scanf("%d",&num);
	Numsum = fsum(num);
	printf("%d",Numsum);
	/*********End**********/ 
	return 0;
}

#endif
