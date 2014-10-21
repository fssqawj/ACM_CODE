#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 105;
bool v[10005];
int main(){
	int n,m;
	while(scanf("%d",&n) && n){
		int a;
		scanf("%d",&m);
		memset(v,false,sizeof(v));
		for(int i = 0;i < n;i ++){
			scanf("%d",&a);
			v[a] = true;
		}
		bool flag = true;
		for(int i = 0;i < m;i ++){
			int cnt,num;
			scanf("%d%d",&cnt,&num);
			int res = 0,b;
			for(int j = 0;j < cnt;j ++){
				scanf("%d",&b);
				if(v[b])res ++;
			}
			if(res < num){
				flag = false;
				//break;
			}
		}
		printf("%s\n",flag ? "yes" : "no");
	}
	return 0;
}
