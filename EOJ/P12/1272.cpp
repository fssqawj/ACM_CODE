#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
const double pi = acos(-1);
int main(){
	double x1,y1,x2,y2,x3,y3;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF){
		double a=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
		double b=sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
		double c=sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
		double p=(a+b+c)/2.0;
		double s=sqrt(p*(p-a)*(p-b)*(p-c));
		double r=a*b*c/(s*4);
		printf("%.2lf\n",2*pi*r);
	}
	return 0;
}
