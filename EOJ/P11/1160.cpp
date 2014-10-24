#include<stdio.h>
int main()
{
	double n,m,t;
	while(scanf("%lf%lf%lf",&m,&n,&t)!=EOF){
		if(n-m<=0)printf("0.000\n");
		else if(t>=n-m)printf("0.500\n");
		else printf("%.3lf\n",((n-m)*(n-m)/2-(n-m-t)*(n-m-t)/2)/((n-m)*(n-m)));
	}
	return 0;
}
