#include<iostream>
using namespace std;
class Person
{
public:
    Person(int a):age(a){}
    int ageGet()
    {
        return this->age;
    }
private:
    int age;
};
class smartPoint//智能指针
{
public:
    smartPoint(Person* person)
    {
        //cout<<"构造"<<endl;
        this->person=person;
    }
    Person* operator->()//重载->
    {
        return this->person;
    }
    Person& operator*()//重载*
    {
        return *(this->person);
    }
    ~smartPoint()
    {
        //cout<<"析构"<<endl;
        if(this->person!=NULL)
        {
            delete this->person;
            this->person=NULL;
        }
    }
private:
    Person* person;
};
void test()
{
    /***
    Person* p=new Person(10);
    cout<<p->ageGet();
    delete p;
    ***/
    smartPoint sp(new Person(10));
    cout<<sp->ageGet()<<endl;//本来是sp->->，但编译器优化后只要也只能写sp->
    cout<<(*sp).ageGet()<<endl;
}
int main()
{
    test();
    return 0;
}
/***
*智能指针托管Person对象，释放内存就不用操心了
让智能指针管理
*为了让智能指针与普通的Person* 指针一样使用
就要重载->和*
***/
