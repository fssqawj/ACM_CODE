#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
bool map[105][105];
int lin[105];
bool v[105];
int n,m;
bool search(int k){
	int i;
	for(i=1;i<=m;i++){
		if(map[k][i]&&!v[i]){
			v[i]=true;
			if(lin[i]==0||search(lin[i])){
				lin[i]=k;
				return true;
			}
		}
	}
	return false;
}
int match(){
	int ans=0;
	memset(lin,0,sizeof(lin));
	for(int i=1;i<=n;i++){
		memset(v,false,sizeof(v));
		if(search(i))ans++;
	}
	return ans;
}
int main(){
	int i;
	while(scanf("%d%d",&n,&m)!=EOF){
		int a,b;
		memset(map,false,sizeof(map));
		for(i=0;;i++){
			scanf("%d%d",&a,&b);
			if(a==0&&b==0)break;
			map[a][b]=true;
		}
		int temp=n-match();
		if(temp>1)printf("%d000000000000000000000000\n",temp-1);
		else printf("CHY\n");
	}
	return 0;
}
