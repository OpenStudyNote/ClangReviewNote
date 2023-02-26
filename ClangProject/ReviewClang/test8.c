/*
所谓回文数，就是说一个数字从左边读和从右边读的结果是一模一样的，例如12321。
判断给出的整数是否是回文数；若是，则输出该整数各位数字之和；否则输出该数不是一个回文数。

原理：任何一个数除以10的余数就是该数最后一位；
任何一个数除以10的商就是排除掉最后一位后的数；1234 就可以通过这种方法得到 123 和 4；
接下来对 123 进行同样的操作，就得到 12 和 3；接下来得到 1 和 2；接着得到 0 和 1；
整个过程是个循环，当商不是0的时候就一直如此；每次拿到一个余数，都用来构造新数，新数=新数*10+余数；
所以经过四次循环后，我们得到新数 4321 ，如果是回文，那么新数应该等于原数，否则，说明不是回文。
*/
#include<stdio.h>
#include<string.h>              //strlen函数的头文件 
#if 0
int main(void)
{  


	

	return 0;
}

#endif


#if 0
//判断一个数是否是回文数

int main()
{
	int num,s,y=0;
	printf("Please input numbers: ");
	scanf("%d", &num);
	s=num;
	while(s>0){
		y=y*10+s%10;
		s=s/10;
	}
	if(y==num){
		printf("%d是一个回文数!\n", num);
	}else{
		printf("%d不是一个回文数!\n", num);
	}
	
	return 0;
}
#endif


#if 1
//判断一下一个字符串是否为回文数

int main() 
{ 
	int j,i,n; 
	char a[999],b[999]; 
	printf("Please input string: ");
	scanf("%s",a);              //输入字符串 
	n=strlen(a);                //用strlen函数读取字符串长度（长度到\0停止） 
	for(i=0,j=n-1;i<n;i++,j--)  //循环将字符串a逆序赋值给b 
		b[j]=a[i];
	for(i=0;i<n;i++) 
	{ 
		if(b[i]!=a[i]) 
			break;                 //判断是否回文 
	} 
	if(i==n) printf("是一个回文数!\n");     //如果从第1位到n都相同 则输出回文数 
	else printf("不是一个回文数!\n"); 
	return 0; 
} 

#endif
