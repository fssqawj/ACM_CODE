#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 35;
int dp[maxn][maxn];
int rt[maxn][maxn];
int src[maxn];
int n;
void p_path(int l,int r){
	if(l > r)return;
	if(l == 1 && r == n)printf("%d",rt[1][n]);
	else printf(" %d",rt[l][r]);
	p_path(l,rt[l][r] - 1);
	p_path(rt[l][r] + 1,r);
}
int main(){
	while(scanf("%d",&n) != EOF){
		for(int i = 1;i <= n;i ++){
			scanf("%d",&src[i]);
			rt[i][i] = i;
			dp[i][i] = src[i];
		}
		//memset(dp,0,sizeof(dp));
		for(int l = 2;l <= n;l ++){
			for(int i = 1;i <= n - l + 1;i ++){
				int j = i + l - 1;
				for(int k = i;k <= j;k ++){
					int tem;
					if(k == i)tem = dp[k + 1][j] + src[k];
					else if(k == j)tem = dp[i][k - 1] + src[k];
					else tem = dp[i][k - 1] * dp[k + 1][j] + src[k];
					if(tem > dp[i][j]){
						dp[i][j] = tem;
						rt[i][j] = k;
					}
				}
			}
		}
		printf("%d\n",dp[1][n]);
		p_path(1,n);
		printf("\n");
	}
	return 0;
}
