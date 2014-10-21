#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 1005;
const int maxm = 40005;
const int INF = 0x3f3f3f3f;
struct edge{
	int v,w,next;
};
edge e[maxm];
int head[maxn];
int id = 1;
int dis[maxn];
int cnt[maxn];
bool v[maxn];
void add(int x,int y,int w){
	e[id].v = y;
	e[id].w = w;
	e[id].next = head[x];
	head[x] = id ++;
	e[id].v = x;
	e[id].w = w;
	e[id].next = head[y];
	head[y] = id ++;
}
void spfa(int st){
	memset(v,false,sizeof(v));
	memset(dis,0x3f,sizeof(dis));
	v[st] = true;
	dis[st] = 0;
	queue<int>q;
	q.push(st);
	while(!q.empty()){
		int tp = q.front();
		q.pop();
		v[tp] = false;
		for(int i = head[tp];i != -1;i = e[i].next){
			if(dis[e[i].v] > dis[tp] + e[i].w){
				dis[e[i].v] = dis[tp] + e[i].w;
				if(!v[e[i].v]){
					v[e[i].v] = true;
					q.push(e[i].v);
				}
			}
		}
	}
}
int dfs(int now){
	if(cnt[now])return cnt[now];
	if(now == 2)return 1;
	for(int i = head[now];i != -1;i = e[i].next){
		if(dis[e[i].v] < dis[now])cnt[now] += dfs(e[i].v);
	}
	return cnt[now];
}
int main(){
	int n,m;
	while(scanf("%d",&n) && n){
		scanf("%d",&m);
		memset(head,-1,sizeof(head));
		id = 0;
		int x,y,w;
		for(int i = 0;i < m;i ++){
			scanf("%d%d%d",&x,&y,&w);
			add(x,y,w);
		}
		spfa(2);
		memset(cnt,0,sizeof(cnt));
		printf("%d\n",dfs(1));
	}
	return 0;
}
