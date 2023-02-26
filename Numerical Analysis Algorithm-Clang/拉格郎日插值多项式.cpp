#include<iostream.h>

float Lagrange(float *x,float *y,float xx,int n)
{
	int i,j;
	float *a,yy=0.0;
	a =new float[(n*sizeof(float))];
	for( i=0;i<=n-1;i++ )
	{
		a[i]=y[i];
		for( j=0;j<=n-1;j++ )
			if(j!=i)
				a[i]*=(xx-x[j])/(x[i]-x[j]);
			yy+=a[i];
	}
	delete[] a;
	return yy;
}

void main()
{
	float x[4]={0.56160,0.56280,0.56401,0.56521};
	float y[4]={0.82741,0.82659,0.82577,0.82495};
	float xx=0.5635,yy;
	float Lagrange(float *,float *,float ,int);
	yy =Lagrange(x,y,xx,4);
	cout<<"x="<<xx<<'\t'<<"y="<<yy<<endl;
}