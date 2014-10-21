#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct point{
	double x,y;
};
bool cmp1(point a,point b){
	return a.x < b.x;
}
bool cmp2(point a,point b){
	return a.y < b.y;
}
point p[30005];
double dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i = 0;i < n ;i ++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		double ans = 0.0;
		sort(p,p+n,cmp1);
		for(int i = 0;i < n && i < 3000;i ++){
			for(int j = n-1;j >=0 && j >= n-3001; j--){
				ans = max(ans,dis(p[i],p[j]));
			}
		}
		sort(p,p+n,cmp2);
		for(int i = 0;i < n && i < 3000;i ++){
			for(int j = n-1;j >= 0 && j >= n-3001; j--){
				ans = max(ans,dis(p[i],p[j]));
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
