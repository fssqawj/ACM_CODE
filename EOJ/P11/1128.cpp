#include<stdio.h>
int main()
{int n,i,f[60];
for(i=0;i<5;i++)
	f[i]=i;
for(i=5;i<60;i++)
	f[i]=f[i-1]+f[i-3];
scanf("%d",&n);
while(n>0)
{printf("%d\n",f[n]);
scanf("%d",&n);
}
return 0;
}
