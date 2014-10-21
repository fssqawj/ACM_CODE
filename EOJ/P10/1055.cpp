#include<stdio.h>
int main()
{int a,b,c,t;
while(scanf("%d%d",&a,&b)!=EOF)
{if(a<b)t=a,a=b,b=t;
  while(a%b!=0)
  {c=a%b;
  a=b;
  b=c;}
printf("%d\n",b);
}
return 0;
}
