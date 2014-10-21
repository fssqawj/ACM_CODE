#include<stdio.h>
int shu[1000005]={0},su[1000005]={0};
int main()
{int i,j,m=0,a,b;
for(i=2;i<1000000;i++)
	{if(shu[i]==0)su[m++]=i;
       for(j=i;j<1000000;j=j+i)
		   shu[j]=1;
    }
while(scanf("%d%d",&a,&b)!=EOF)
{for(i=0;su[i]<a&&su[i]>0;i++);
for(j=0;su[j]<b&&su[j]>0;j++);
if(su[j]==b)printf("%d\n",j-i+1);
else printf("%d\n",j-i);
}
return 0;
}
