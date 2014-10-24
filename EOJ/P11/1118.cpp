#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
const double pi = 3.1415927;
int main(){
	double a,b,c;
	int ca = 1;
	while(scanf("%lf%lf%lf",&a,&b,&c) && b != 0){
		double d = pi * (a / 12 / 5280) * b;
		printf("Trip #%d: %.2lf %.2lf\n",ca ++,d,d / (c / 3600));
	}
	return 0;
}
