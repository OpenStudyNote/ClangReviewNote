#include<iostream>
using namespace std;
class Person
{
friend ostream& operator<<(ostream &cout,Person p);//设置全局函数为友元函数
public:
    Person(){}
    Person(int val):data(val)//初始化列表
    {}

private:
    int data;
};

void test1()
{
    Person p1(20);//通过含参构造函数初始化
    cout<<p1<<endl;
}
ostream& operator<<(ostream& cout,Person p)//用全局函数重载左移运算符，成员函数无法重载<<
{
    cout<<p.data;
    return cout;
}
int main()
{
    test1();
    return 0;
}
