#include<stdio.h>
int main()
{int a,b,c,t,d,e;
while(scanf("%d%d",&a,&b)!=EOF)
{d=a;e=b;
if(a<b)t=a,a=b,b=t;
  while(a%b!=0)
  {c=a%b;
  a=b;
  b=c;}
printf("%d\n",d*e/b);
}
return 0;
}
