#include<iostream>
using namespace std;
int main()
{
    char ch;
    char buf[1024];
    cin>>ch//不会接收空白字符,如空格,回车,tab
    cin>>buf;//不会接收空白字符,如空格,回车,tab
    /***
    *读取一个字符串，
    *不会读取空格，空格留在缓冲区
    *不会读取换行符，换行符留在缓冲区
    ***/
    ch=cin.get();//读取一个字符，
    //相当与getchar() ,不会放过任何一个字符
    cin.get(buf,1024);
    /***
    *读取一个字符串，
    *会读取空格，
    *不会读取换行符，换行符留在缓冲区
    ***/
    cin.getline(buf,1024);
    /***
    *读取一个字符串
    *会读取空格，
    *会读取换行符并扔掉
    ***/
    cin.ignore(2);//忽略两个字符，没有参数默认为1
    ch=cin.peek();//偷看一个字符，再放回缓冲区
    cin.putback();//放回一个字符到缓冲区
    return 0;
}
