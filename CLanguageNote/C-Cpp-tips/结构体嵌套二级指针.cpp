/*结构体嵌套二级指针*/
#include<bits/stdc++.h>
using namespace std;
struct Teacher
{
    char* name;
    char** students;
};
int allocatedSpace(struct Teacher*** temp)//创建结构体二级指针分配堆空间
{
    if(NULL==temp)
        return -1;//错误码
    struct Teacher** ts=(struct Teacher**)malloc(sizeof(struct Teacher*)*4);
    for(int i=0; i<4; ++i)
    {
        ts[i]=(struct Teacher*)malloc(sizeof(struct Teacher));
        ts[i]->name=(char *)malloc(sizeof(char)*64);
        sprintf(ts[i]->name,"Teacher_%d",i+1);
        ts[i]->students=(char**)malloc(sizeof(char*)*4);
        for(int j=0; j<4; ++j)
        {
            ts[i]->students[j]=(char*)malloc(sizeof(char)*64);
            sprintf(ts[i]->students[j],"%s_Student_%d",ts[i]->name,j+1);

        }
    }
    *temp=ts;
    return 0;
}

int PrintTeachers(struct Teacher** teachers)
{
    if(NULL==teachers)
        return -1;
    for(int i=0; i<4; ++i)
    {
        printf("%s\n",teachers[i]->name);
        for(int j=0; j<4; ++j)
        {
            printf("%s   ",teachers[i]->students[j]);
        }
        printf("\n");
    }
    return 0;
}
void freeSpace(struct Teacher** teachers)//释放空间free
{
    if(NULL==teachers)
        return;
    for(int i=0; i<4; ++i)
    {
        if(teachers[i]==NULL)
            continue;
        if(teachers[i]->name!=NULL)
        {
            free(teachers[i]->name);
            teachers[i]->name=NULL;
        }
        if(teachers[i]->students!=NULL)
        {
            for(int j=0; j<4; ++j)
                if(teachers[i]->students[j]!=NULL)
                {
                    free(teachers[i]->students[j]);
                    teachers[i]->students[j]=NULL;
                }
        }
        free(teachers[i]);
        teachers[i]=NULL;
    }
    free(teachers);
    teachers=NULL;
    return;
}
int main()
{
    struct Teacher** teachers=NULL;
    int ret=allocatedSpace(&teachers);
    if(ret<0)
    {
        printf("allocatedSpace 函数调用出错\n");
        return 0;
    }
    PrintTeachers(teachers);
    freeSpace(teachers);
    teachers=NULL;
    return 0;
}
