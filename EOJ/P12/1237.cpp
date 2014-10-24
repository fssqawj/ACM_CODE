#include<stdio.h>
int main()
{
	int n,i,j,t=0,max=0,dp1[1005],dp2[1005];
	double a[1005];
	scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf",&a[i]);
		dp1[0]=1;
		for(i=1;i<n;i++){
			t=0;
			for(j=0;j<i;j++){
				if(a[i]>a[j]&&dp1[j]>t)t=dp1[j];
			}
			dp1[i]=t+1;
		}
		dp2[n-1]=1;
		for(i=n-2;i>=0;i--){
			t=0;
			for(j=n-1;j>i;j--){
				if(a[i]>a[j]&&dp2[j]>t)t=dp2[j];
			}
			dp2[i]=t+1;
		}
		for(i=0;i<n-1;i++)
			for(j=i+1;j<n;j++)
				if(dp1[i]+dp2[j]>max)max=dp1[i]+dp2[j];
		printf("%d\n",n-max);
	return 0;
}
