#include<iostream.h>
#define N 4

void Difference(float *x,float *y,int n)
{
	float *f;
	int k,i;
	f =new float[(n*sizeof(float))];	
	for(k=1;k<=n;k++)
	{
		f[0]=y[k];
		for(i=0;i<k;i++)
			f[i+1]=(f[i]-y[i])/(x[k]-x[i]);
		y[k]=f[k];
	}
	cout<<endl;
	return ;
}

void main()
{
	int i;
	float varx =0.895,b;
	float x[N+1] ={0.4,0.55,0.65,0.8,0.9};
	float y[N+1] ={0.41075,0.57815,0.69675,0.88811,1.02652};
	Difference(x,(float *)y,N);
	b =y[N];
	for (i=N-1;i>=0;i--)	
	{b = b*(varx-x[i])+y[i];
	cout<<b<<endl;
	}
	cout<<"Nn("<<varx<<")="<<b<<endl;	
}