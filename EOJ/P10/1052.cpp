#include <stdio.h>
int p[100000];
int main()
{int t,n,m,j,i,w[100000],v[100000];
 scanf("%d",&t);
 while(t--)
 {scanf("%d%d",&n,&m);
 for(j=1;j<=n;j++)
scanf("%d%d",&w[j],&v[j]);
 for(i=1;i<=n;i++)
   for(j=m;j>=w[i];j--)
   {
   if( p[j-w[i]]+v[i]>p[j])
   {p[j]=p[j-w[i]]+v[i];
     }
    }   
printf("%d\n",p[m]);
for(i=0;i<100000;i++)
	p[i]=0;
  }
return 0;
}
