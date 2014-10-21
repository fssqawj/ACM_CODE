#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const long long INF = 1LL<<60;
struct data{
	long long x,y;
};
data d[55];
long long dp[55][55];
int main(){
	int t;
	scanf("%d",&t);
	while(t --){
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;i ++){
			scanf("%lld%lld",&d[i].x,&d[i].y);
		}
		memset(dp,0,sizeof(dp));
		for(int p = 1;p < n;p ++){
			for(int i = 0;i < n - p;i ++){
				int j = i + p;
				dp[i][j] = INF;
				for(int k = i;k <= j - 1;k ++){
					if(dp[i][j] > dp[i][k] + dp[k+1][j] + d[i].x*d[k].y*d[j].y){
						dp[i][j] = dp[i][k] + dp[k+1][j] + d[i].x*d[k].y*d[j].y;
					}
				}
			}
		}
		printf("%lld\n",dp[0][n-1]);
	}
	return 0;
}
