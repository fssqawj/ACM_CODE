#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 55;
double x[maxn],y[maxn];
int id[maxn];
double get(int n){
	double s = x[id[n - 1]] * y[0] - x[id[0]] * y[id[n - 1]];
	for(int i = 0;i < n - 1;i ++){
		s += x[id[i]] * y[id[i + 1]] - x[id[i + 1]] * y[id[i]];
	}
	return fabs(s / 2);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t --){
		int n;
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++){
			scanf("%lf%lf",&x[i],&y[i]);
		}
		int m;
		int ans = -1;
		double maxx = 0;
		scanf("%d",&m);
		for(int i = 0;i < m;i ++){
			int k;
			scanf("%d",&k);
			for(int j = 0;j < k;j ++){
				scanf("%d",&id[j]);
			}
			double res = get(k);
			if(res > maxx){
				maxx = res;
				ans = i + 1;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
