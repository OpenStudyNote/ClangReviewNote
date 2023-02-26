#include <stdio.h>


//1010 1010  0101 0101
//0000 0000  0111 1000
//0000 0000  0000 1010


void binDis(int data)
{
	int i= 32;
	while(i--)
	{
		if(data & (1<<i))
			printf("1");
		else
			printf("0");
		if(i%8==0)
			putchar(' ');
	}
	putchar(10);
}

int main()
{
	int mask = 0xf;
	int data = 0xaa55;
	
	data >>=3;
	
	data &= mask;
	
	printf("%d",data);
}

int main1(void)
{
	int mask = 1<<6 |1<<5|1<<4|1<<3;
	int data = 0xaa55;
	binDis(data);
	binDis(mask);
	
	data &= mask;
	binDis(data);
	
	data >>=3;
	
	binDis(data);
	
	printf("%d",data);
	
	
	
	
	return 0;
}

#if 0

0100 0000
0010 0000
0001 0000
0000 1000

#endif


