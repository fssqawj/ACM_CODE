#include<stdio.h>
int main()
{int yb,ws,es,s,w,e,y,n,t,yu;
scanf("%d",&t);
while(t--)
{scanf("%d",&n);
yb=n/100;
yu=n%100;
ws=yu/50;
yu=yu%50;
es=yu/20;
yu=yu%20;
s=yu/10;
yu=yu%10;
w=yu/5;
yu=yu%5;
e=yu/2;
yu=yu%2;
y=yu;
printf("%d %d %d %d %d %d %d\n",yb,ws,es,s,w,e,y);}
return 0;
}
