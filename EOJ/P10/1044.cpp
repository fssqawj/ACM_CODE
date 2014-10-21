#include<iostream>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;
const int maxn = 100005;
int map[maxn][105];
struct data{
	int num,lel;
};
bool v[maxn];
int main(){
	int n,i,j,m;
	while(scanf("%d",&n)!=EOF){
		memset(map,-1,sizeof(map));
		memset(v,false,sizeof(v));
		queue<data> q;
		for(i=0;i<n;i++){
			scanf("%d%d",&j,&m);
			for(j=0;j<m;j++){
				scanf("%d",&map[i][j]);
			}
		}
		int s,t;
		scanf("%d%d",&s,&t);
		data tp;
		tp.num=s;
		tp.lel=0;
		q.push(tp);
		v[s]=true;
		while(!q.empty()){
			tp=q.front();
			q.pop();
			if(tp.num==t){
				break;
			}
			for(i=0;map[tp.num][i]!=-1;i++){
				if(!v[map[tp.num][i]]){
					v[map[tp.num][i]]=true;
					data pp;
					pp.num=map[tp.num][i];
					pp.lel=tp.lel+1;
					q.push(pp);
				}
			}
		}
		printf("%d %d %d\n",s,t,tp.lel-1);
	}
	return 0;
}
