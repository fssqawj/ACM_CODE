#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct point{
	double x,y;
};
const int maxn = 100050;
point p[maxn];
int tm[maxn];
bool cmpx(point a,point b){
	return a.x < b.x;
}
bool cmpy(int a,int b){
	return p[a].y < p[b].y;
}
double dis(point a,point b){
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double closed(int l,int r){
	if(l == r)return 1e15;
	if(l + 1 == r)return dis(p[l],p[r]);
	int mid = (l + r)>>1;
	double ans = min(closed(l,mid),closed(mid + 1,r));
	int top = 0;
	for(int i = l;i <= r;i ++){
		if(fabs(p[mid].x - p[i].x) < ans)tm[top ++] = i;
	}
	sort(tm,tm + top,cmpy);
	for(int i = 0;i < top;i ++){
		for(int j = i + 1;j < top && p[tm[j]].y - p[tm[i]].y < ans;j ++){
			ans = min(ans,dis(p[tm[i]],p[tm[j]]));
		}
	}
	return ans;
}
int main(){
	int n;
	while(scanf("%d",&n) && n){
		for(int i = 0;i < n;i ++){
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		sort(p,p + n,cmpx);
		printf("%.2lf\n",closed(0,n - 1) / 2);
	}
	return 0;
}
