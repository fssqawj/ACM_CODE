#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 1005;
int sg[maxn];
int g[maxn];
void init(){
	sg[0] = sg[1] = 0;
	for(int i = 2;i < maxn;i ++){
		memset(g,0,sizeof(g));
		for(int j = 0;j <= i - 2;j ++){
			g[sg[j]^sg[i - j - 2]] = 1;
		}
		int j;
		for(j = 0;g[j];j ++);
		sg[i] = j;
	}
}
int main(){
	int t;
	scanf("%d",&t);
	init();
	while(t --){
		int s = 0;
		int n,x;
		scanf("%d",&n);
		for(int i = 0;i < n;i ++){
			scanf("%d",&x);
			s ^= sg[x];
		}
		if(s)printf("Win\n");
		else printf("Lost\n");
	}
	return 0;
}
