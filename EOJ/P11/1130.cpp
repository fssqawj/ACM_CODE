#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int vr[10],vc[10],vv1[20],vv2[20];
int n;
int ans;
void dfs(int num,int r){
	if(num==0){
		ans++;
		return ;
	}
	for(;r<n;r++){
		for(int i=0;i<n;i++){
			if(!vr[r]&&!vc[i]&&!vv1[r+i]&&!vv2[r-i+10]){
				vr[r]=true;
				vc[i]=true;
				vv1[r+i]=true;
				vv2[r-i+10]=true;
				//cout<<"r = "<<r<<" i = "<<i<<" r + i = "<<r+i<<endl;
				dfs(num-1,r);
				//cout<<"##############\nr = "<<r<<" i = "<<i<<" r + i = "<<r+i<<endl;
				vr[r]=false;
				vc[i]=false;
				vv1[r+i]=false;
				vv2[r-i+10]=false;
			}
		}
	}
}
int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		for(int i=0;i<t;i++){
			scanf("%d",&n);
			memset(vr,false,sizeof(vr));
			memset(vc,false,sizeof(vc));
			memset(vv1,false,sizeof(vv1));
			memset(vv2,false,sizeof(vv2));
			ans=0;
			dfs(n,0);
			printf("%d\n",ans);
		}
	}
	return 0;
}
