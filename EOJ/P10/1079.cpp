#include<stdio.h>
int main()
{int a[30][30],i,j,n;
a[1][0]=1;a[1][1]=1;
for(i=0;i<30;i++)
	a[i][0]=1;
for(i=0;i<30;i++)
	for(j=0;j<30;j++)
	if(i==j)a[i][j]=1;
for(i=2;i<30;i++)
	for(j=1;j<i;j++)
		a[i][j]=a[i-1][j-1]+a[i-1][j];
scanf("%d",&n);
while(n!=0)
{for(i=0;i<n;i++)
  {if(i!=0)printf("\n");
    for(j=0;j<i;j++)printf("%d ",a[i][j]);
	printf("%d",a[i][j]);
   }
printf("\n\n");
scanf("%d",&n);
}
return 0;
}
