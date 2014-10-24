#include<stdio.h>
int main()
{int min=10,max=0,num;
char c[15];
scanf("%d",&num);
getchar();
gets(c);
while(num!=0)
{if(c[4]=='h')
if(num<min)min=num;
if(c[4]=='l')
if(num>max)max=num;
if(c[4]=='t')
{if(num>max&&num<min)printf("Sunny may be honest\n");
else printf("Sunny is dishonest\n");
min=11;max=0;}
scanf("%d",&num);
getchar();
gets(c);
}
return 0;
}
