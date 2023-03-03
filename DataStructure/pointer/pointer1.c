#include <stdio.h>
#include <stdlib.h>
/*
	int *px=&x;	表示px指针所指向的变量x  int* px ;表示定义一个指针  *px=100;*px表示取该地址的内容的数值
*/

int main()
{
	int x=3,y1=0,*px=&x;
	y1 = *px+5;   //*px 就是x
	y1 = ++*px;    //++*pointer 表示px指针所指向的变量的数值加加1
	y1 = *px++; 	 //*px++表示地址加1 (加了4个字节)//先把*px的值复制给y1,然后自己地址加有1
	//y1 = (*px)++;  //(*px)++ 表示px指针所指向的变量的数值加加1
	printf("%d \n",y1);
	return 0;
	
}
