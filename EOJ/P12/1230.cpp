#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int maxn = 10005;
int a[105];
int dp[maxn];
bool v[maxn];
int n;
void init(){
	memset(dp,0,sizeof(dp));
	for(int i = 0;i < maxn;i ++){
		memset(v,false,sizeof(v));
		for(int j = 0;j < n;j ++){
			if(a[j] <= i)v[dp[i - a[j]]] = true;
		}
		for(int j = 0;j < maxn;j ++){
			if(!v[j]){
				dp[i] = j;
				break;
			}
		}
	}
}
int main(){
	while(scanf("%d",&n) && n){
		for(int i = 0;i < n;i ++){
			scanf("%d",&a[i]);
		}
		init();
		int m;
		scanf("%d",&m);
		for(int i = 0;i < m;i ++){
			int s = 0,x,k;
			scanf("%d",&k);
			for(int j = 0;j < k;j ++){
				scanf("%d",&x);
				s ^= dp[x];
			}
			printf(s ? "W" : "L");
		}
		printf("\n");
	}
}
