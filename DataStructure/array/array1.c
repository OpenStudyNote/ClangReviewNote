#include <stdio.h>
#include <stdlib.h>
/*
数组：构造类型变量  相同数据类型构成的新类型 
数组在内存中存储是连续的
int arr[10]={1,2,3,4,5,6,7,8,9,0}; 
arr[N]  范围为0~N-1  
访问或者初始化赋值是循环使用
for(i=0;i<N;i++)
结构体  构造类型变量  不同数据类型构成的新类型
struct {
	int a;
	char b;
	float f;
}
数组的逻辑是一维的，对于其成员的访问，即读写，往往通过一重循环来实现。
*/
/*
    
	基本数据类型 	1 字节= 8位
	类型			存储大小    值范围
	char			1 字节		-128 到 127 或 0 到 255
	unsigned char	1 字节		0 到 255
	signed char		1 字节		-128 到 127
	int				2 或 4 字节	-32,768 到 32,767 或 -2,147,483,648 到 2,147,483,647
	unsigned int	2 或 4 字节	 0到 65,535 或 0 到 4,294,967,295
	short			2 字节		-32,768 到 32,767
	unsigned short	2 字节		0 到 65,535
	long			4 字节		-2,147,483,648 到 2,147,483,647
	unsigned long	4 字节		0 到 4,294,967,295
*/
/*
	在32位操作系统下：
1：整形
      int                    4字节
      long int               4字节
      short int              2字节  (short)
      unsigned int           4字节
      unsigned long int      4字节
      unsigned short int     2字节  (unsigned short)
2：字符型
      char                 1字节
      unsigned char        1字节
3：浮点型
      float           		  4字节
      double                  8字节
      long double             8字节
      unsigned long double    8字节
      unsigned double         4字节
4：字符串型
      string                           32字节
5：指针类型
      所有类型的指针都是 4字节
*/

/*
凡是构造类型,要么在初始化的时候初始化,要么对集合中的每个元素单独初始化。
构造类型定义以后,不可以再以初始化的方式初始化。
凡是基础数据类型,既可以在定义的时候初始化,也可以先定义后初始化。	
*/

/*
	不指定数组的大小初始化 
	int arr[]={12,44,55,66,77,88,10,34,8};
	使用sizeofs计算数组长度 
	sizeof是C语言中保留关键字，也可以认为是一种运算符，单目运算符。用于判断变量或数据类型的字节大小。
	sizeof使用形式：sizeof(type);  注：数据类型必须用括号括住。如sizeof（int）。
	length = sizeof(arr)/sizeof(arr[0])
	int arr[]={12,44,55,66,77,88,10,34,8};
	unsigned char length;
	length  = sizeof(arr)/sizeof(arr[0]);
	printf("%d",length);
*/

/*
	变长数组variable-length array
	//所谓变长数组，就是运行开始，有一次改变大小的机会。在其后的运行其间不可以改变大小。
	//且vla不可以初始化。
	int var=5;
	int arr[var]={1,2,3,4,5};//错误使用方法，不能初始化
	int arr[var];//正确使用方法
	//demo
	
*/
int main(void)
{
	#if 0  //计算数组的长度
	int arr[]={12,44,55,66,77,88,10,34,8};
	unsigned char i =0;
	for(;i<sizeof(arr)/sizeof(arr[0]);i++){
		printf("arr[%d]=%d \r\n",i,arr[i]);
	}
	return 0;
	#endif
	
	#if 0 //数组的连续
	int array[10];
	for(int i=0; i<10; i++) //所以 for 循环的书写，常写为左闭右开的形式
	{
		printf("&array[%d] = %p\n",i,&array[i]);
	}
	return 0;
	
	/* 
	&array[0] = 000000376d3ffc70
	&array[1] = 000000376d3ffc74
	&array[2] = 000000376d3ffc78
	&array[3] = 000000376d3ffc7c
	&array[4] = 000000376d3ffc80
	&array[5] = 000000376d3ffc84
	&array[6] = 000000376d3ffc88
	&array[7] = 000000376d3ffc8c
	&array[8] = 000000376d3ffc90
	&array[9] = 000000376d3ffc94
	*/
	#endif
	
	#if 0 //所谓变长数组，就是运行开始，有一次改变大小的机会。在其后的运行其间不可以改变大小。
	int len; 
	
	scanf("%d",&len);
	int array[len];
	
	printf("sizeof(array) = %d\n",sizeof(array));
	
	scanf("%d",&len);
	printf("sizeof(array) = %d\n",sizeof(array));
	
	return 0;
	#endif
}
