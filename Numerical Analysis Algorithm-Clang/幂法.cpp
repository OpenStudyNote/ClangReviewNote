#include<iostream.h>
#include<math.h>
#define N 3
#define EPS 1e-6
#define KM 30
 
void PowerMethod(float *A)
{
	float MaxValue(float *,int );
	float U[N],V[N],r2,r1;
	float temp;
	int i,j,k=0;
	for (i=0;i<N;i++)
		U[i]=1;
	while(k<KM)
	{
		k++;
		for(i=0;i<N;i++)
		{
			temp=0;
			for(j=0;j<N;j++)
				temp+=*(A+i*N+j)*U[j];
			V[i]=temp;
		}
		for (i=0;i<N;i++)
			U[i]=V[i]/MaxValue(V,N);
		if(k==1)
		{			//书上程序有bug，这里就加入下面两句
			r1=MaxValue(V,N);
			continue;
		}
		r2=MaxValue(V,N);
		if(fabs(r2-r1)<EPS)
			break;
		r1=r2;
	}
	cout<<"\nr="<<r2<<endl;
	for (i=0;i<N;i++)
		cout<<"\nx["<<i+1<<"]="<<U[i];
}
float MaxValue(float *x,int n)
{
	float Max=x[0];
	int i;
	for (i=1;i<n;i++)
		if(fabs(x[i])>fabs(Max)) 
			Max=x[i];
		return Max;
}
void main()
{
	float A[N][N]={{2,-1,0},{-1,2,-1},{0,-1,2}};
	PowerMethod(A[0]);
}
		
