#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct data{
	int x,y;
};
char map[200][200];
int lel[200][200];
int move[4][2]={1,0,0,1,-1,0,0,-1};
int n,m;
void getdis(){
	queue<data>q;
	data tp;
	memset(lel,-1,sizeof(lel));
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < m;j ++){
			if(map[i][j] == '1'){
				tp.x = i;
				tp.y = j;
				q.push(tp);
				lel[i][j] = 0;
			}
		}
	}
	while(!q.empty()){
		tp = q.front();
		q.pop();
		for(int i = 0;i < 4;i ++){
			data pp;
			pp.x = tp.x + move[i][0];
			pp.y = tp.y + move[i][1];
			if(pp.x >= 0 && pp.x <n && pp.y >= 0 && pp.y < m && lel[pp.x][pp.y] == -1){
				lel[pp.x][pp.y] = lel[tp.x][tp.y] + 1;
				q.push(pp);
			}
		}
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i = 0;i < n;i ++){
			scanf("%s",map[i]);
		}
		getdis();
		for(int i = 0;i < n;i ++){
			printf("%d",lel[i][0]);
			for(int j = 1;j < m;j ++){
				printf(" %d",lel[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
