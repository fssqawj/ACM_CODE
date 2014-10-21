#include<iostream>
using namespace std;
int main()
{
	int a[1005];
	int t,w,i,j;
	int dp[1005][35];
	cin>>t>>w;
	for(i=1;i<=t;i++){
		cin>>a[i];
	}
	if(a[1]==1){
		dp[1][0]=1;
		dp[1][1]=0;
	}
	if(a[1]==2){
		dp[1][1]=1;
		dp[1][0]=0;
	}
	for(i=2;i<=t;i++){
		for(j=0;j<=w;j++){
			dp[i][j]=dp[i-1][j]>dp[i-1][j-1]?dp[i-1][j]:dp[i-1][j-1];
			if(j%2+1==a[i])dp[i][j]++;
		}
	}
	int temp=dp[t][0];
	for(i=0;i<=w;i++){
		if(temp<dp[t][i])temp=dp[t][i];
	}
	cout<<temp<<endl;
}
