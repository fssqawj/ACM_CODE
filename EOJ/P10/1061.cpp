#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
//int id[10] = {0,1,2,3,4,5,6,7,8,9};
char s[12][12];
int p[12][12];
int n;
int fet(char a[],char b[]){
	int la = strlen(a);
	int lb = strlen(b);
	int ans = 0;
	for(int i = 0;i < la;i ++){
		int tem = 0;
		int j = 0;
		int ii = i;
		while(j < lb && ii < la){
			if(a[ii] == b[j])tem ++;
			ii ++;j ++;
		}
		ans = max(ans,tem);
	}
	for(int i = 0;i < lb;i ++){
		int tem = 0;
		int j = 0;
		int ii = i;
		while(j < la && ii < lb){
			if(b[ii] == a[j])tem ++;
			ii ++;j ++;
		}
		ans = max(ans,tem);
	}
	return ans;
}
void init(){
	memset(p,0,sizeof(p));
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < n;j ++){
			p[i][j] = p[j][i] = fet(s[i],s[j]);
			//printf("i = %d j = %d dp = %d\n",i,j,p[i][j]);
		}
	}
}
int res = 0;
bool v[12];
void dfs(int now,int sum,int cnt){
	if(cnt == n){
		res = max(res,sum);
		return ;
	}
	if(res > sum + (n - cnt) * 10)return ;
	for(int i = 0;i < n;i ++){
		if(!v[i]){
			v[i] = true;
			dfs(i,sum + (now >= 0 ? p[now][i] : 0),cnt + 1);
			v[i] = false;
		}
	}
}
int main(){
	
	while(scanf("%d",&n) && n){
		for(int i = 0;i < n;i ++){
			scanf("%s",s[i]);
		}
		init();
		res = 0;
		dfs(-1,0,0);
		printf("%d\n",res);
	}
	return 0;
}
