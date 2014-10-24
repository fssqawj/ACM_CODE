#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int sum[maxn][maxn];
int a[maxn][maxn];
int up[maxn][maxn];
int lef[maxn][maxn];
int rig[maxn][maxn];
int getsum(int l,int r,int u,int d){
	return sum[d][r] - sum[u - 1][r] - sum[d][l - 1] + sum[u - 1][l - 1];
}
int main(){
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF){
		memset(sum,0,sizeof(sum));
		for(int i = 1;i <= n;i ++){
			int tem = 0;
			for(int j = 1;j <= m;j ++){
				scanf("%d",&a[i][j]);
				tem += a[i][j];
				sum[i][j] = sum[i - 1][j] + tem;
			}
		}
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++){
				if(i == 1)up[0][j] = 0;
				if(a[i][j] == 0){
					up[i][j] = i;
				}
				else {
					up[i][j] = up[i - 1][j];
				}
			}
		}
		for(int i = 1;i <= n;i ++){
			int id = 1;
			for(int j = 1;j <= m;j ++){
				if(i == 1)lef[0][j] = 1;
				if(a[i][j] == 0){
					lef[i][j] = -1;
					id = j + 1;
				}
				else {
					lef[i][j] = max(id,lef[i - 1][j]);
				}
			}
		}
		for(int i = 1;i <= n;i ++){
			int id = m;
			for(int j = m;j >= 1;j --){
				if(i == 1)rig[0][j] = m;
				if(a[i][j] == 0){
					rig[i][j] = maxn;
					id = j - 1;
				}
				else {
					rig[i][j]  = min(id,rig[i - 1][j]);
				}
			}
		}
		int ans = 0;
		for(int i = 1;i <= n;i ++){
			for(int j = 1;j <= m;j ++){
				if(a[i][j]){
					int l = lef[i][j];
					int r = rig[i][j];
					int u = up[i][j];
					//printf("i = %d j = %d l = %d r = %d u = %d\n",i,j,l,r,u);
					ans = max(ans,getsum(l,r,u + 1,i));
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
