#include<iostream>
using namespace std;
class MyPrint
{
public:
   void operator()(string text)
   {
       cout<<text<<endl;
   }
};

void test()
{
    MyPrint myprint;
    myprint("hello");//myprint(）仿函数
    MyPrint()("world");//使用匿名对象
}
int main()
{
    test();
    return 0;
}
