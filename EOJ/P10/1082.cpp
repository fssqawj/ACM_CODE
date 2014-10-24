#include<stdio.h>
int main()
{int i,a[10],n;
a[0]=1;
for(i=1;i<10;i++)
	a[i]=a[i-1]*i;
scanf("%d",&n);
while(n>=0)
{if(n==0)printf("NO\n");
else {for(i=9;i>=0;i--)
  {if(n>=a[i])n=n-a[i];
   if(n==0)break;}
if(n==0)printf("YES\n");
else printf("NO\n");}
scanf("%d",&n);}
return 0;
}
