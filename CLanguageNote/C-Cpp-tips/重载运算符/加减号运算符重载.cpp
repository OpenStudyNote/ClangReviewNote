#include<iostream>
using namespace std;
class Person
{
public:
    Person(){}
    Person(int val):data(val)//初始化列表
    {}
    Person operator+(Person& p)//用成员函数重载加号
    {
        Person tmp;
        tmp.data=this->data+p.data;
        return tmp;
    }
    void dataSet(int data)
    {
        this->data=data;
    }
    int dataGet()
    {
        return this->data;
    }
private:
    int data;
};
Person operator-(Person& p1,Person& p2)//用全局函数重载减号
{
    Person tmp;
    tmp.dataSet(p1.dataGet()-p2.dataGet());
    return tmp;
}
void test1()
{
    Person p1(20);//通过含参构造函数初始化
    Person p2;
    p2.dataSet(15);//通过成员函数初始化
    Person p3=p1+p2;
    cout<<p3.dataGet();
}
void test2()
{
    Person p1(20);//通过含参构造函数初始化
    Person p2;
    p2.dataSet(11);//通过成员函数初始化
    Person p3=p1-p2;
    cout<<p3.dataGet();
}
int main()
{
    test2();
    return 0;
}
