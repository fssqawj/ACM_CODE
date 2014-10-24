#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn = 6005;
struct edge{
	int v;
	int next;
};
edge e[maxn];
int id = 0;
int head[maxn];
int dp[maxn][2];
int val[maxn];
bool v[maxn];
void add(int x,int y){
	e[id].v = y;
	e[id].next = head[x];
	head[x] = id ++;
}
void dfs(int root){
	int f = 0,t = 0;
	for(int i = head[root];i != -1;i = e[i].next){
		//printf("root = %d v = %d\n",root,e[i].v);
		dfs(e[i].v);
		f += max(dp[e[i].v][0],dp[e[i].v][1]);
		t += dp[e[i].v][0];
	}
	dp[root][0] = f;
	dp[root][1] = t + val[root];
	//printf("root = %d f = %d t = %d\n",root,dp[root][0],dp[root][1]);
}
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 1;i <= n;i ++){
			scanf("%d",&val[i]);
		}
		memset(head,-1,sizeof(head));
		memset(dp,0,sizeof(dp));
		memset(v,false,sizeof(v));
		id = 0;
		int a,b;
		while(scanf("%d%d",&a,&b) && !(a == 0 && b == 0)){
			add(b,a);
			v[a] = true;
		}
		for(int i = 1;i <= n;i ++){
			if(!v[i]){
				dfs(i);
				printf("%d\n",max(dp[i][0],dp[i][1]));
				break;
			}
		}
	}
	return 0;
}
