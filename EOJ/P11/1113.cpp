#include <stdio.h>
int p[20005]={0};
int main()
{int n,m,j,i,v[20005];
 while(scanf("%d",&n)!=EOF)
 {scanf("%d",&m);
 for(j=1;j<=m;j++)
scanf("%d",&v[j]);
 for(i=1;i<=m;i++)
   for(j=n;j>=v[i];j--)
	   if(p[j-v[i]]+v[i]>p[j])p[j]=p[j-v[i]]+v[i];
printf("%d\n",n-p[n]);
for(i=0;i<20005;i++)
	p[i]=0;
  }
return 0;
}
