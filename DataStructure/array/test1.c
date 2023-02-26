#include<stdio.h>
int main(void)
{  
	/********* Begin *********/
	int a,b,c,max;
	scanf("%d,%d,%d",&a,&b,&c);
	if(a>b&&a>c)
	{
		max =a;
	}
	else if(b>a&&b>c)
	{
		max = b;
	}
	else
	{
		max = c;
	}
	
	printf("max=%d",max);
	/********* End *********/
	return 0;
}

/*
任务描述
本关任务：下列程序是不用第三个变量，实现将两个数进行对调的操作。
测试说明
平台会对你编写的代码进行测试，若是与预期输出相同，则算通关。
输入：3 4
输出：
a=3 b=4
a=4  b=3

输入：7 85
输出：
a=7 b=85
a=85  b=7
程序代码如下：

	#include<stdio.h>
	int main(void)
	{  
	  int a,b;
      scanf("%d%d",&a,&b); 
      printf("a=%d b=%d\n",a,b);
	  a=a+b;
	  b=a-b;
	  a=a-b;
	  printf("a=%d  b=%d\n",a,b);  
	  
	  return 0;
	}





*/
