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
#if 0
int main()
{
	
	int x = 5;
	int* p = &x;
	*p = 6;
	int** q = &p;     
	int*** r = &q; 
	printf("%d \n", *p); //6  *p=x
	printf("%d\n", *q); //225   q = &p *q表示取p的地址内容
	printf("%d\n", *(*q)); //6   *(*q)表示取p指向x的地址内容
	printf("%d\n", *(*r)); //225  r = &q;*(*r)表示取p的地址内容
	printf("%d\n", *(*(*r))); //6 *(*(*r))表示取p指向x的地址内容
	/*
		
		int* p = &x;    p->x  *p=x
		int** q = &p;	q->p  *q=p,**q=*p=x
		int*** r = &q;  r->q  *r=q,**r=*q=p,***r=**q=*p=x
		p是x的地址,*q是p的地址,*q=p,**q =*p
		p是x的地址,*r是q的地址,*r=q,**r =p,***r=*p
		
		r->q->p->x 重点是搞清楚指针指向
		
		6
		1134556980
		6
		1134556980
		6
	*/
	
}


#endif
/*
	自定义函数的变量存储在栈里，临时的，运行完就消失，
	主函数的的变量存储在堆里,调用函数之后,主函数变量不发生改变，即对于堆里面的变量无影响。
*/

#if 1
void Increment(int a)
{
	a = a+1;
	printf("address Increment  a = %d\n",&a);
}

int increment(int a)
{
	a = a+1;
	
	return a;
}

int main()
{
	
	int a,b;
	a = 10;
	b = 11;
	Increment(a);
	increment(a);
	printf("addtress Mian a = %d\n",&a);
	printf("a = %d\n",a);
	printf("b = %d\n",b);
	
	
	int array[5]={2,4,5,8,1};
	int *p;
	//p = array;
	 p = &array; //数组名就是首地址 p = array[0]
	printf("%d\n",array);
	printf("%d\n",*array);
	printf("%d\n",array+1);
	printf("%d\n",*(array+1));
	
	
	int array1[5]={2,4,6,8,10};
	int *pi;
	pi = array1;//or p = &array; 
	printf("%d\n",array1);	 //打印首地址
	printf("%d\n",&array1[0]); //打印首地址
	printf("%d\n",array1[0]);	 //打印数组第一个元素
	printf("%d\n",*array1); 	//打印数组第一个元素
	
	return 0;
}


#endif
