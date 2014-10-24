#include<iostream>
using namespace std;
const int INF = 0x3f3f3f3f;
int dp[10005];
int main()
{
	int t,e,f,i,j;
	int n;
	int v[505],w[505];
	cin>>t;
	while(t--){
		memset(dp,0x3f,sizeof(dp));
		dp[0]=0;
		cin>>e>>f;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>v[i]>>w[i];
		}
		for(i=1;i<=n;i++){
			for(j=w[i];j<=f-e;j++){
				dp[j]=dp[j]<(dp[j-w[i]]+v[i])?dp[j]:(dp[j-w[i]]+v[i]);
			}
		}
		if(dp[f-e]==INF)cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<dp[f-e]<<"."<<endl;
	}
	return 0;
}
