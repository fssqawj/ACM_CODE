#include<stdio.h>
int main()
{int t,n,a[105],i,max;
scanf("%d",&t);
while(t--)
{scanf("%d",&n);
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
for(i=1;i<n;i++)
	if(a[i-1]>0)a[i]=a[i]+a[i-1];
max=a[0];
for(i=1;i<n;i++)
	if(a[i]>max)max=a[i];
printf("%d\n",max);
}
return 0;
}
