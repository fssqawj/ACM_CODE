#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{return *(int *)a-*(int *)b;}
int main()
{int cmp(const void *a,const void *b);
	int i,j,con,a[12],b[12]={0};
for(i=0;i<12;i++)
	scanf("%d",&a[i]);
qsort(a,12,sizeof(int),cmp);
if(a[0]==a[1]&&a[1]==a[2]&&a[2]==a[3]&&a[4]==a[5]&&a[5]==a[6]&&a[6]==a[7]&&a[8]==a[9]&&a[9]==a[10]&&a[10]==a[11])
	printf("POSSIBLE\n");
else printf("IMPOSSIBLE\n");
return 0;
}
