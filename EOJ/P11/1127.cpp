#include<iostream>
#include<stdio.h>
using namespace std;
struct point{
	double x,y;
};
point p[105];
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		double s;
		s=p[0].y*(p[n-1].x-p[1].x);
		for(int i=1;i<n;i++){
			s+=p[i].y*(p[i-1].x-p[(i+1)%n].x);
		}
		printf("%.1lf\n",s/2);
	}
	return 0;
}
