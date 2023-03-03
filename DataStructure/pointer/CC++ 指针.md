# C/C++ 指针

```c

#include <stdio.h>

/*
整型指针变量p，存储的值是整型变量age的内存地址
符号&是取地址符，那么&age = 00000033d07ff67c;
由于指针变量本身也是一个变量，所以p也有一个自己的地址
对其取地址操作&p=00000033d07ff670;
而*p则是获取指针变量p存储的值对应内存地址中存储的值。
*/

int main()
{
	//指针和指针变量的区别
	//变量是用来存放数据的，指针是内存地址，指针变量就是用来存放内存地址的变量。
	// 声明一个整型变量age，值是17
	int age = 2022;
	// 声明一个整型指针，指向变量age的地址， &符号可以理解为 <取地址符号>
	int *p = &age;  
	/*
		p是一个整型指针变量，存放的是age的地址  p=&age
		'*'作用于指针时表示访问指针所指向的对象  取该地址对应的内容
		*p = &age  --》 取该age地址对应的内容 17
	*/
	printf("age的值：%d\n", age);
	printf("*p的值：%d\n", *p);
	printf("变量 age的地址：%p\n", &age);
	printf("指针p指向的地址：%p\n", p);
	printf("指针p自身的地址：%p\n", &p);	
	
	
	if((*p)==age){
		printf(" *p = age ok \n");
	}
	else
		printf(" error \n");
	
}

/*
	age的值：2022
	*p的值：2022
	变量 age的地址： 00000033d07ff67c
	指针p指向的地址：00000033d07ff67c
	指针p自身的地址：00000033d07ff670
*/




```

```c
/*
		int *p = &age;  
		&age  变量age的地址
		p  	  指针p指向的地址
	    p=^&age  等同
		&p    指针p自身的地址 
		*p = age  等同
		int *p=&age; 定义指针变量 与 *p = age 不一样
		
		int age;//定义变量，内存就会分配地址 例如age地址208,p地址64 
		int *p; //定义指针变量
		p = &age; //p指针指向a地址
		age = 5;	//赋值

		printf("变量age的地址：%p\n", &age); //&age
		printf("指针p指向的地址：%p\n", p);   // p = &a; //p指针指向a地址
		printf("指针p自身的地址：%p\n", &p); //&p   指针变量p的地址
		printf("*p的值：%d\n", *p);			//(*p)  //指针变量所指向地址处的内容值
		printf("age的值：%d\n", age);		//age	//变量a
		
		if make *p = 100 --> age=100  //对*p进行赋值，修改变量值

		
		int a = 10;
		int *p; //定义指针变量
		p = &a; //p指针指向a地址
		// Pointer arithmetic
		printf("%d\n", p);    // 204
		printf("%d\n", *p);    // a=*p=10
		print("%d\n", p+1);   // 208
		printf("%d\n", *(p+1));    // *(p+1)该地址所指向的内容不确定,系统会随机生成值
		//要使用*(p+1),必须提前定义



*/ 
```

```c
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
```

```c
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
```

```c
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
	
	return 0;
}

#endif
```

### 堆（Heap）、栈（Stack）

在计算机中，程序的 Code Data(global and static variables) Stack是固定的，

[![stack_heap](https://s1.ax1x.com/2023/03/03/ppAmkZR.jpg)

堆（Heap）、栈（Stack）在不同的场景下，代表不同的含义。

（1）程序内存布局场景下，堆（Heap）、栈（Stack）代表两种内存管理方式；

（2）数据结构场景下，堆（Heap）、栈（Stack）表示两种常用的数据结构；

  ***Code、Data、BSS——在编译时确定；保存基本代码和数据的区域。***

***BSS：保存未初始化的数据；***

***Data：保存初始化数据***

### 堆(Heap)

![Heap](https://s1.ax1x.com/2023/03/03/ppAmAd1.jpg)

堆(Heap)内存放的数据地址是不连续的；

堆(Heap)中的地址是由低到高的；

堆(Heap)由程序员分配和释放；如果没有被人工释放，程序结束时由OS回收；所以堆heap中存储的数据如果没有被释放，则其生命周期等同于程序的声明周期。

堆(Heap)由程序员使用内存分配函数（**malloc 函数**）来申请任意多少的内存，使用完之后再由程序员自己负责使用内存释放函数（ **free 函数**）来释放内存。

也就是说，动态内存的整个生存期是由程序员自己决定的。

频繁分配和释放（malloc / free）不同大小的堆Heap空间势必会造成内存空间的不连续，从而造成大量碎片，导致程序效率降低。

堆(Heap)上内存法分配过程：

- 操作系统有一个记录空闲内存地址的链表     
- 当系统收到程序的申请时会遍历此链表，寻找第一个空间>所申请空间的堆heap节点
-  然后将该节点从空闲链表中删除
- 将该节点的空间分配给程序   

 注意：

（1）对于大多数系统，会在这块内存空间中的首地址处记录本次分配的大小。这样，代码中的delete语句才能正确释放本内存空间；

（2）找到的堆heap节点大小不一定正好=申请的大小，系统会自动地将多余的那部分重新放入空闲链表中。

### 栈（Stack）

栈（Stack）按分配方式分为两种：静态栈和动态栈；

- 静态栈：由编译器分配完成，比如局部变量
- 动态栈：由*alloca()函数*进行分配，由编译器进行释放。（alloca函数可移植性很差）

栈（Stack）内存中存放着函数的参数值、局部变量等；

栈（Stack）中存储的数据生命周期随着函数的执行完成而结束；

栈（Stack）内存地址是由高到低的；



### 总结

堆Heap与栈Stack是操作系统对进程占用内存空间的两种管理方式，它们的区别主要如下：

（1）管理方式不同：栈Stack由系统自动分配释放，无需人工控制；堆Heap由程序员申请和释放，容易产生内存内存泄露；

（2）空间大小不同：每个进程拥有的栈Stack大小远远小于堆Heap的大小；程序员可申请的堆Heap大小为系统的虚拟内存大小；

（3）地址顺序不同：堆Heap内存地址由低到高，栈Stack内存地址由高到低；

（4）存放内容不同



[![stack](https://s1.ax1x.com/2023/03/03/ppAmiL9.md.png)](https://imgse.com/i/ppAmiL9)

### 函数调用 值传递 指针传递 引用传递

| 传递方式 | 函数定义    | 函数调用 | 函数内对a修改的影响 |
| -------- | ----------- | -------- | ------------------- |
| 值传递   | fun(int a)  | fun(x)   | 外部x不变           |
| 指针传递 | fun(int *a) | fun(&x)  | 外部x同步更改       |
| 引用传递 | fun(int &a) | fun(x)   | 外部x同步更改       |

### 值传递

函数内部使用这个参数，对这个参数的修改对函数外的原始数据不起作用。

```c
#include <stdio.h>
 
void swap(int a, int b)
{
    printf("swap enter\n");
    printf("a = %d, ptr = %p\n", a, &a);
    printf("b = %d, ptr = %p\n", a, &b);
 
    int tmp = b;
    b = a;
    a = tmp;
 
    printf("a = %d, ptr = %p\n", a, &a);
    printf("b = %d, ptr = %p\n", b, &b);
    printf("swap leave\n");
}
 
int main() 
{
    int x = 1;
    int y = 2;
    printf("x = %d, ptr = %p\n", x, &x);
    printf("y = %d, ptr = %p\n", y, &y);
 
    swap(x, y);
 
    printf("x = %d, ptr = %p\n", x, &x);
    printf("y = %d, ptr = %p\n", y, &y);
 
    return 0;
}
```

### 指针传递（地址传递）

形参为指向实参地址的指针，当对形参的指向操作时，就相当于操作实参本身。

```c
#include <stdio.h>
 
void swap(int *a, int *b)
{
    printf("swap enter\n");
    printf("a = %d, ptr = %p\n", *a, a);
    printf("b = %d, ptr = %p\n", *a, b);
 
    int tmp = *b;
    *b = *a;
    *a = tmp;
 
    printf("a = %d, ptr = %p\n", *a, a);
    printf("b = %d, ptr = %p\n", *b, b);
    printf("swap leave\n");
}
 
int main() 
{
    int x = 1;
    int y = 2;
    printf("x = %d, ptr = %p\n", x, &x);
    printf("y = %d, ptr = %p\n", y, &y);
 
    swap(&x, &y);
 
    printf("x = %d, ptr = %p\n", x, &x);
    printf("y = %d, ptr = %p\n", y, &y);
 
    return 0;
}

```

[![array](https://s1.ax1x.com/2023/03/03/ppAnR4P.md.jpg)](https://imgse.com/i/ppAnR4P)

```c
	int array[5]={2,4,5,8,1};
	int *p;
	//p = array;
	 p = &array; //数组名就是首地址 p = array[0]
	printf("%d\n",array);
	printf("%d\n",*array);
	printf("%d\n",array+1);
	printf("%d\n",*(array+1));
	
/*
    获取地址 
    address    &array[i]  or (array+i)
    获取值
    value	 	array[i]  or *(array+i)
    1988099200
    2
    1988099204
    4
*/
	int array1[5]={2,4,6,8,10};
	int *pi;
	pi = array1;//or p = &array; 
	printf("%d\n",array1);	 //打印首地址
	printf("%d\n",&array1[0]); //打印首地址
	printf("%d\n",array1[0]);	 //打印数组第一个元素
	printf("%d\n",*array1); 	//打印数组第一个元素

/*
	pi++ 合法  指针变量自加
	array1++ 不合法 数组名不能自加
    656406672
    656406672
    2
    2
*/
```

