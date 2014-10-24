#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const double pi = acos(-1.0);
int main(){
	double D,d,s;
	int t;
	scanf("%d",&t);
	while(t --){
		scanf("%lf%lf%lf",&D,&d,&s);
		double t1 = (D - d) / 2;
		double t2 = (d + s) / 2;
		//printf("t1 = %lf t2 = %lf\n",t1,t2);
		double a = asin(t2 / t1) * 2;
		//printf("a = %lf\n",a);
		int ans = floor(2 * pi / a);
		printf("%d\n",ans);
	}
	return 0;
}
