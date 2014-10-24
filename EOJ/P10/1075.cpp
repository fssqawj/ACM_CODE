#include<stdio.h>
int main()
{
	__int64 sum[1005];
	int i,n;
	sum[0]=1;
	sum[1]=2;
	for(i=1;i<1005;i++)
		 sum[i]=sum[i-1]+i*(i-1)/2+1;
	while(scanf("%d",&n)&&n)
	{printf("%I64d\n",sum[n]);
	}
	return 0;
}
