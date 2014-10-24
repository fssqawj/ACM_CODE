#include<stdio.h>
#include<stdlib.h>
int m(int a,int b)
{return a>b?b:a;}
int cmp(const void *a,const void *b)
{return *(int *)a-*(int *)b;}
int main()
{int m(int a,int b);
int cmp(const void *a,const void *b);
	int t,n,a[100][100]={0},i,j,sum[100][100]={0};
scanf("%d",&t);
while(t--)
{scanf("%d",&n);
for(i=0;i<n;i++)
	for(j=0;j<=i;j++)
		scanf("%d",&a[i][j]);
	sum[0][0]=a[0][0];
for(i=1;i<n;i++)
	for(j=0;j<=i;j++)
	{if(j==0)sum[i][j]=a[i][j]+sum[i-1][j];
	else if(j==i)sum[i][j]=a[i][j]+sum[i-1][j-1];
	else sum[i][j]=a[i][j]+m(sum[i-1][j],sum[i-1][j-1]);}
qsort(sum[n-1],n,sizeof(int),cmp);
printf("%d\n",sum[n-1][0]);
for(i=0;i<100;i++)
	for(j=0;j<100;j++)
		sum[i][j]=0;
}
return 0;
}
