/* 数组指针三种定义方式 */ 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	typedef int(Array_Type)[10];//先定义数组类型，再用这个类型定义数组指针变量 
	Array_Type* aArray = NULL;
	
	typedef int(*Array_Pointer)[10];//直接定义数组指针类型，再定义数组指针变量 
	Array_Pointer bArray = NULL;
	
	int (*cArray)[10];//直接定义数组指针变量 
	cArray = NULL; 
	return 0;
}
