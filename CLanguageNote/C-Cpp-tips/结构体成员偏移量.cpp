#include<bits/stdc++.h>
using namespace std;
struct A
{
    int a;
    double b;
};
struct B
{
    char a;
    int b;
    struct A c;
};
void test()
{
    struct B b={'s',53,12,4.34};
    int off1=offsetof(struct B,c);
    int off2=offsetof(struct A,b);
    printf("%lf\n",b.c.b);
    printf("%lf\n",*(double*)(((char*)&b+off1)+off2));
    printf("%lf",((struct A*)((char*)&b+off1))->b);
}
int main()
{
    test();
    return 0;
}
