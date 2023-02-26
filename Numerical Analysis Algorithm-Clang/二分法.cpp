#include<iostream.h>
#include<math.h>
#define EPS 5e-6	//根容许的误差
#define DELTA 1e-6  //|f(x)|容许的误差
float Bisection( float a,float b,float (*f)(float) )
{
	float c,fc,fa=f(a),fb=f(b);
	int n=1;
	cout<<"二分次数\tc\tf(c)\n";
	while(1)
	{
		if( fa*fb>0 )
			return 0;
		c =(a+b)/2,fc =f(c);
		if( fabs(fc) < DELTA )
			break;
		else if (fa*fc<0)
		{
			b=c;
			fb=fc;
		}
		else
		{
			a=c;
			fa=fc;
		}
		if( b-a< EPS )
			break;
		cout<<'\t'<<n++<<'\t'<<c<<'\t'<<fc<<endl;
	}
	return c;
}

float f(float x)
{
	return x*x*x+x*x-3*x-3;		//求解的方程
}