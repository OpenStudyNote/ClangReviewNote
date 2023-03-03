#include <stdio.h>
#include <stdlib.h>
/*
	int *px=&x;	表示px指针所指向的变量x  int* px ;表示定义一个指针  *px=100;*px表示取该地址的内容的数值
*/
/*
	对于int类型 一般使用4个字节 4byte =32 bit
				byte3 	 byte2 	  byte1   byte0 
	符号位——>00000000 00000000 00000100 00000001  
				207    206      205       204
			p->a 指向是首地址204 然后一直导207
	不同类型的指针在解引用时，所读取的字节数与指针所指向的数据类型相关。
	比如：如果为int*则读取该地址及后面共4个字节存储的数据，指针变量+1则地址数值+4；
	如果为char*则读取该地址1个字节存储的数据，指针变量+1则地址数值+1，可以通过sizeof关键字确定类型大小。
	
*/
int main()
{
	int a = 1025;
	int* p = &a;
	char* p0;
	p0 = (char*)p; // typecasting  //强制转换  把整形指针变量p转换成字符char指针变量
	printf("%d %d\n", p, *p); 
	printf("%d %d\n", p+1, *(p+1)); 
	printf("%d,%d\n", p0, *p0); 
	printf("%d,%d\n", p0+1, *(p0+1));
	/* 
		1025= 00000000 00000000 00000100 00000001
		-2141193940 1025
		-2141193936 -2141193940
		-2141193940,1
		-2141193939,4
	*/
	
}
