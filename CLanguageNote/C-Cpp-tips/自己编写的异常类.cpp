#include<iostream>
#include<string>
using namespace std;
class MyOutOfRangeException :public exception//exception基类
{
public:
    MyOutOfRangeException(string  errorInfo)
    {
        this->ErrorInfo = errorInfo;
    }

    virtual ~MyOutOfRangeException() {}
    virtual const char* what() const
    {
        //返回错误信息 string转char*
        return this->ErrorInfo.c_str();
    }
    string ErrorInfo;
};
class Person
{
public:
    Person(string name, int age)
    {
        this->Name = name;
        this->Age = age;
        if (age < 0 || age>200)
        {
            throw MyOutOfRangeException(string("年龄越界异常"));
        }
    }
    string Name;
    int Age;
};
void test()
{
    try
    {
        Person p("小明", 300);
    }
    catch (MyOutOfRangeException& e)
    {
        cout << e.what() << endl;
    }
}
int main()
{
    test();
    return 0;
}
