#include<iostream>
using namespace std;
class Person
{
public:
    Person(string s):str(s){}
   bool operator==(const Person& p)
   {
       if(this->str==p.str)
        return true;
       return false;
   }
    bool operator!=(const Person& p)
   {
       if(this->str==p.str)
        return false;
       return true;
   }
private:
    string str;
};

void test()
{
    Person p1("aaa");
    Person p2("aaa");
    if(p1==p2)
        cout<<"相同";
    if(p1!=p2)
        cout<<"不相同";
}
int main()
{
    test();
    return 0;
}
