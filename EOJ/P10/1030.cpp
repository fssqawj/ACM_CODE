#include<stdio.h>
int main()
{int n,i,f[60];
for(i=0;i<4;i++)
	f[i]=1;
for(i=4;i<60;i++)
	f[i]=f[i-1]+f[i-3];
scanf("%d",&n);
while(n>0)
{printf("%d\n",f[n]);
scanf("%d",&n);
}
return 0;
}
