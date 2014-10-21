#include <stdio.h>
int main()
{
int N,M,i;
__int64 a[51],n;
while(scanf("%d%d",&N,&M)!=EOF)
{
if(N<M) n=1<<N;
else
{
a[0]=1;
for(i=1;i<M;i++) a[i]=2*a[i-1];
a[i]=2*a[i-1]-1;
i++;
for(;i<=N;i++) a[i]=2*a[i-1]-a[i-M-1];
n=a[N];
}
printf("%I64d\n",n);
}
return 0;
}
