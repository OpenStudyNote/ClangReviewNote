#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class Person
{
public:
    Person(const char* name)
    {
        this->pName = new char[strlen(name) + 1];
        strcpy(this->pName, name);
    }
    Person& operator=(const Person& p)
    {
        if (this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }
        this->pName = new char[strlen(p.pName) + 1];
        strcpy(this->pName, p.pName);
        return *this;
    }
    string pNameGet()
    {
        return pName;
    }
    ~Person()
    {
        if (this->pName != NULL)
        {
            delete[] this->pName;
            this->pName = NULL;
        }
    }
private:
    char* pName;
};

void test()
{
    Person p1("哈哈哈");
    Person p2("呵呵呵");
    p2 = p1;
    cout << p2.pNameGet();
}
int main()
{
    test();
    return 0;
}
