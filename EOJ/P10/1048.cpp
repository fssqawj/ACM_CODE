#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{return *(int *)a-*(int *)b;}
int main()
{int cmp(const void *a,const void *b);
	int t,n,i,a[10000];
_int64 sum=0;
scanf("%d",&t);
while(t--)
{scanf("%d",&n);
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
qsort(a,n,sizeof(int),cmp);
for(i=0;i<n-1;i++)
	sum=sum+a[i]*(n-1-i);
printf("%I64d\n",sum);
sum=0;
}
return 0;
}
