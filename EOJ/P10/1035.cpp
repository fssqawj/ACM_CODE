#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 1005;
bool v[maxn];
int n;
int d[maxn];
bool can(int s,int t,int step){
	while(!v[s] && s != t){
		v[s] = true;
		s += step;
		if(s > n)s -= n;
	}
	return s == t;
}
int main(){
	int t,m;
	while(scanf("%d%d%d",&n,&t,&m) != EOF){
		int a;
		for(int i = 0;i < m;i ++){
			scanf("%d",&d[i]);
		}
		int i;
		for(i = 1;i < n;i ++){
			memset(v,false,sizeof(v));
			for(int j = 0;j < m;j ++){
				v[d[j]] = true;
			}
			if(can(1,t,i))break;
		}
		printf("%d\n",i);
	}
}
