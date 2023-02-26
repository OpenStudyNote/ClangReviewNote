/*
1. 输入：一个三位数
输出：输出该数字的百位，十位，个位，数字之间用一个空格隔开。
样例输入：
123
样例输出：
1 2 3


2. 编程求从键盘上输入一个学生的五门成绩，计算出该学生的总成绩和平均成绩
样例输入：
60 70 80 90 100

样例输出
400 80.00
3.编程求以a、b、c为边长的三角形的面积area 海伦公式
4.设圆半径r，圆柱高h ,求圆周长C1，半径为r的圆球表面积Sb,圆半径r，圆柱高为h的圆柱体积Vb。 
用scanf输入数据，输出计算结果，输出时取小数点后两位数字。 PI＝3.14
*/


#include<stdio.h>
#include<math.h>

#define Pi 3.14


int main(void)
{
#if 0
	int num[5],sum=0;
	float average=0;
	for(int i=0;i<=4;i++)
	{
		scanf("%d ",&num[i]);
	}
	for(int i=0;i<=5;i++){
		printf("%d ",num[i]);
	}
	for(int i=0;i<=4;i++){
		sum = sum+num[i];
	}
	average = sum/5;
	printf("%d %.2f\n",sum,average);
	return 0;
	
#endif
	
	
#if 0
	int num,a,b,c;
	scanf("%d",&num);
	a = num/100;
	b= 	num%100/10;
	c=  num%100%10;
	printf("%d %d %d\n",a,b,c);
	return 0;
#endif
	
#if 0	
	int sum=0;
	float average =0;
	int n1,n2,n3,n4,n5;
	scanf("%d %d %d %d %d",&n1,&n2,&n3,&n4,&n5);
	sum = n1+n2+n3+n4+n5;
	average = sum/5.00; //注意转换浮点数
	printf("%d %.2f",sum,average);
#endif	

#if 0
	float a,b,c;
	float area=0;
	float s ;
	scanf("%f %f %f",&a,&b,&c);
	s=(a+b+c)/2.0;
	area = sqrt(s*(s-a)*(s-b)*(s-c));
	printf("%.3f",area);
#endif	
	
	/*
		当使用scanf对 double和float输入时：
		double对应的是 %lf float对应的是 %f
		注：%f与%lf不可混用
		当使用printf对double和float输出时：%f 和 %lf 能够混用。
	*/
	double r,h;
	double C1;
	double Sb;
	double Vb;
	scanf("%lf %lf",&r,&h); //double 浮点数类型 输出输出格式为lf
	C1 =2*Pi*r;
	Sb = (4.0)*Pi*pow(r,2);
	Vb = Pi*pow(r,2)*h;
	printf("%.2f\n%.2f\n%.2f\n",C1,Sb,Vb);
	
	
}


