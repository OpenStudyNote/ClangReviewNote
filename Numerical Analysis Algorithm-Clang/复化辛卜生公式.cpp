#include<iostream.h>
#include<math.h>
void main()
{
	int i,n=2;
	float s;
	float f(float);
	float Simpson(float (*)(float),float,float,int );
	for( i=0;i<=2;i++ )
	{
		s=Simpson(f,0,1,n);
		cout<<"s("<<n<<")="<<s<<endl;
		n*=2;
	}
}
float Simpson(float (*f)(float),float a,float b,int n)
{
	int k;
	float s,s1,s2=0.0;
	float h=(b-a)/n;
	s1=f(a+h/2);
	for(k=1;k<=n-1;k++)
	{
		s1+=f(a+k*h+h/2);
		s2+=f(a+k*h);
	}
	s=h/6*(f(a)+4*s1+2*s2+f(b));
	return s;
}
float f(float x)
{
	return 1/(1+x*x);
/*	if(x==0)
		return 1;
	else
		return sin(x)/x;*/
}

