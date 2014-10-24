#include<stdio.h>
int num[100005]={0};
int main()
{int n,a,b,i,m=0;
while(scanf("%d",&n)!=EOF&&n!=0)
{for(i=0;i<n;i++)
	{scanf("%d%d",&a,&b);
 num[a]++;
 num[b+1]--;}
m=num[1];
printf("%d",m);
for(i=2;i<=n;i++)
{m=m+num[i];
printf(" %d",m);}
printf("\n");
for(i=0;i<100005;i++)
	num[i]=0;
m=0;
}
return 0;
}
