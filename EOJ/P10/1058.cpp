#include<iostream>
using namespace std;
double x[1005],y[1005];
int main(){
	int n;
	double v;
	while(scanf("%d",&n)!=EOF&&n>=3){
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&x[i],&y[i]);
		}
		scanf("%lf",&v);
		double s=0.0;
		for(int i=0;i<n-1;i++){
			s+=(x[i]*y[i+1]-x[i+1]*y[i]);
		}
		s+=x[n-1]*y[0]-x[0]*y[n-1];
		printf("BAR LENGTH: %.2lf\n",-2*v/s);
	}
	return 0;
}
