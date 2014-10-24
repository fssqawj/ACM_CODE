#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
bool v[25];
int q[25];
int top;
int n;
bool prime[50];
bool shu[50]={0};
void dfs(int num){
	//cout<<"num = "<<num<<endl;
	if(num==n&&prime[q[top-1]+q[0]]&&q[0]==1){
		printf("%d",q[0]);
		for(int i=1;i<n;i++){
			printf(" %d",q[i]);
		}
		printf("\n");
		return ;
	}
	if(num>=n)return ;
	for(int i=1;i<=n;i++){
		if(!v[i]&&prime[q[top-1]+i]||(top==0)){
			v[i]=true;
			q[top]=i;
			top++;
			dfs(num+1);
			top--;
			v[i]=false;
		}
	}
}
int main(){
	int i,j;
	for(i=2;i<50;i++){
		if(!shu[i]){
			prime[i]=true;
			for(j=i+i;j<50;j+=i){
				shu[j]=true;
			}
		}
	}
	prime[1]=true;
	while(scanf("%d",&n)!=EOF){
		memset(v,false,sizeof(v));
		top=0;
		dfs(0);
	}
	return 0;
}
