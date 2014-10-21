#include<iostream>
using namespace std;
int b[50005];
int dp[3][50005];
int n,k;
int main()
{
	int i,j,t,k,a[50005];
	cin>>t;
	while(t--){
		memset(b,0,sizeof(b));
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(i=1;i<=n;i++)
			cin>>a[i];
		cin>>k;
		b[0]=a[0]=0;
		for(i=1;i<=n;i++)
			b[i]=b[i-1]+a[i];
		int num=b[k];
		for(i=k+1;i<=n;i++){
			num+=a[i];
			num-=a[i-k];
			b[i]=num;
		}
		for(i=1;i<=3;i++){
			for(j=k;j<=n;j++){
				dp[i][j]=(dp[i-1][j-k]+b[j])>dp[i][j-1]?(dp[i-1][j-k]+b[j]):dp[i][j-1];
			}
		}
		cout<<dp[3][n]<<endl;
	}
	return 0;
}
