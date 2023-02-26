#include<bits/stdc++.h>
using namespace std;
typedef struct bb
{
    int id;             //[0]....[3]
    double weight;      //[8].....[15]
    float height;      //[16]..[19],总长要为８的整数倍,补齐[20]...[23]
}A;
typedef struct aa
{
    char name[3];     //[0]...[2]
    double score;     //[8]...[15]
    int  id;         //[16]...[19]
    A b;             //[24]......[47]
    short grade;    //[48],[49],总长要为8的整数倍,补齐[50]...[55]

}B;

int main()
{
  cout<<sizeof(A)<<"  "<<sizeof(B)<<endl;
  return 0;
}
