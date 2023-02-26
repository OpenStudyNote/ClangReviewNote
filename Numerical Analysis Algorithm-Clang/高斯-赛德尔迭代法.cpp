#include<iostream.h>
#include<math.h>
#define N 100

void main()
{
	int i;
	float *x;
	float c[12]={8.0,-3.0,2.0,20.0,
				 4.0,11.0,-1.0,33.0,
				 6.0,3.0,12.0,36.0};	//here must be modifed
	float *GauseSeidel(float *,int);
	x=GauseSeidel(c,3);
	for( i=0;i<=2;i++ )
		cout<<"x["<<i<<"]="<<x[i]<<endl;
}


float *GauseSeidel(float *a,int n)
{
	
	int	  i,j,nu=0;
	float *x,dx;
	x =new	float[n*sizeof(float)];
	for( i=0;i<=n-1;i++ )
		x[i]=0.0;
	do
	{	
		for( i=0;i<=n-1;i++ )
		{
			dx=0.0;
			for( j=0;j<=n-1;j++ )					
				dx+=*(a+i*(n+1)+j)*x[j];			
			dx=(*(a+i*(n+1)+n)-dx)/(*(a+i*(n+1)+i));
			x[i]+=dx;
		}		
		if( nu>N )
		{
			cout<<"µü´ú·¢É¢\n";
			return 0;
		}
		nu++;
	}
	while(fabs(dx)>1e-6);
	return x;
}

