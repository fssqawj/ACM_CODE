#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
int f[1500],g[1500];
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n) != EOF){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		int t;
		for(int i = 1;i <= n;i ++){
			scanf("%d",&t);
			int maxj = min(i,m);
			for(int j = 1;j <= maxj;j ++){
				f[j] = max(f[j],g[j - 1]) + t;
				g[j - 1] = max(f[j - 1],g[j - 1]);
				//printf("i = %d j = %d f = %d g = %d\n",i,j,f[j],g[j - 1]);
			}
			g[maxj] = max(f[maxj],g[maxj]);
		}
		printf("%d\n",g[m]);
	}
	return 0;
}
