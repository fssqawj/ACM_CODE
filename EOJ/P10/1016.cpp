#include<iostream>
using namespace std;
int a[100005];
int sum[100005];
int dp[100005];
int num[100005];
int main()
{
	int n,f;
	scanf("%d%d",&n,&f);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=0;f+i<=n;i++){
		if(i==0||(sum[f+i]-sum[i])*1.0/f>(dp[f+i-1]+a[f+i])*1.0/(num[f+i-1]+1)){
			dp[f+i]=sum[f+i]-sum[i];
			num[f+i]=f;
		}
		else {
			dp[f+i]=dp[f+i-1]+a[f+i];
			num[f+i]=num[f+i-1]+1;
		}
	}
	int ans=-1;
	for(int i=0;f+i<=n;i++){
		if(dp[f+i]*1000/num[f+i]>ans){
			ans=dp[f+i]*1000/num[f+i];
		}
	}
	printf("%d\n",ans);
	return 0;
}
