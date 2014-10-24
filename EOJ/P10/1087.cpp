#include<iostream>
using namespace std;
char map[1005][1005];
bool v[1005][1005];
int m[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int c,r;
int ei,ej;
int sum=0,ans=0;
void dfs(int i,int j){
	for(int k=0;k<4;k++){
		int ti=i+m[k][0];
		int tj=j+m[k][1];
		if(ti>=0&&ti<r&&tj>=0&&tj<c&&map[ti][tj]=='.'&&!v[ti][tj]){
			v[i][j]=true;
			sum++;
			if(ans<sum){
				ans=sum;
				ei=ti;
				ej=tj;
			}
			dfs(ti,tj);
			v[i][j]=true;
			sum--;
		}
	}
}
int main()
{
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		memset(map,'\0',sizeof(map));
		scanf("%d%d",&c,&r);
		for(i=0;i<r;i++){
			scanf("%s",map[i]);
		}
		ans=sum=0;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++){
				if(map[i][j]=='.'){
				memset(v,false,sizeof(v));
				v[i][j]=true;
				dfs(i,j);
				break;
				}
			}
			if(map[i][j]=='.')break;
		}
		ans=sum=0;
		memset(v,false,sizeof(v));
		v[ei][ej]=true;
		dfs(ei,ej);
		printf("%d\n",ans);
	}
	return 0;
}
