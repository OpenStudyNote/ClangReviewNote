#include<iostream>
using namespace std;

int main()
{
    int a=10;
    int* const pa=&a;
    *pa=12;
    cout<<*pa<<endl;
    /***********
    指针常量 指针类型的常量
    自身的值不变，是一个常量
    指向的地址也不变
    必须初始化(引用必须初始化的原因)
    ***********/

    int b=20;
    int c=30;
    const int* pb=&b;
    pb=&c;
    cout<<*pb<<endl;
    /**************
    常量指针 指向常量的指针
    指针指向的地址上的内容是不可改变的
    **************/

}
