
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


