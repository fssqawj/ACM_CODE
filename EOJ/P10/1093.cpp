#include<stdio.h>
int main()
{
	int n,i,m=0,a[100];
	while(scanf("%d",&n)!=EOF){
		if(n==0)printf("10\n");
		else if(n==1)printf("1\n");
		else {
			for(i=9;i>=2;i--){
				while(n%i==0){
					a[m++]=i;
					n=n/i;
				}
			}
			if(n>1){
				printf("-1\n");
			}
			else {
				for(i=m-1;i>=0;i--)
					printf("%d",a[i]);
				printf("\n");
			}
		}
		m=0;
	}
		return 0;
	}
