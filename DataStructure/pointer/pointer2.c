#include <stdio.h>
#include <stdlib.h>


void mystrcopy(char* dest,const char* src)
{
	while((*dest++  = *src++) !='\0');	
}

int main()
{

    char s1[32] = "hello";
    char s2[32] = "123456789";
	mystrcopy(s2,s1);
	printf("%s\n",s2);
	return 0;
	
}
