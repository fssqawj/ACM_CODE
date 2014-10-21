#include<iostream>
#include<algorithm>
using namespace std;
int a[105];
int ans;
int summ;
int n;
void dfs(int i,int sum){
	if(sum==summ){
		ans++;
		return ;
	}
	if(i==n||sum>summ)return ;
	int temp=sum+a[i];
	dfs(i+1,temp);
	dfs(i+1,sum);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&summ);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		ans=0;
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}
