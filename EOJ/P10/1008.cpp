#include<stdio.h>
int main()
{
	int n,t,i,sum=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=5;n/i>0&&i<=1220703125;i*=5)
			sum+=n/i;
		printf("%d\n",sum);
		sum=0;
	}
	return 0;
}
