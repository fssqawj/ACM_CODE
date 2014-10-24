#include<stdio.h>
#include<stdlib.h>
int main()
{int cmp(const void*a,const void*b);
	int a[100][30]={0},i,n,j,k=0,b[3000];
scanf("%d",&n);
for(i=0;i<n;i++)
	for(j=0;j<30;j++)
		{scanf("%d",&a[i][j]);
         if(a[i][j]==-1)break;}
qsort(a,3000,sizeof(int),cmp);
if(a[0][0]!=30)printf("no\n");
else{for(i=0;i<n;i++)
	   { for(j=1;j<30;j++)
{if(a[i][j]!=a[i][j-1]&&a[i][j]>0){b[k]=a[i][j-1];k++;}}
if(a[i][j]<=0)break;}
b[k]=a[i][j];
if(k==29)printf("yes\n");
else printf("no\n");
}
return 0;
}
int cmp(const void*a,const void*b)
{return *(int *)b-*(int *)a;}
