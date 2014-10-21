#include<stdio.h>
#include<stdlib.h>
 int a[100005],m[50005],count[1000005],num[1000005],k=0;
int main()
{int cmp(const void *a,const void *b);
int find(int a);
	int n,n1,m1[50005]={0},i,j,l=1;
scanf("%d%d",&n,&n1);
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
for(i=0;i<n1;i++)
	scanf("%d",&m[i]);
qsort(a,n,sizeof(int),cmp);
for(i=0;i<n-1;i++)
	{if(a[i]==a[i+1])l++;
	else count[k]=l,num[k]=a[i],k++,l=1;}
count[k]=l;
num[k]=a[n-1];
for(j=0;j<n1;j++)
  m1[j]=find(m[j]);
for(i=0;i<n1;i++)
	printf("%d\n",m1[i]);
return 0;
}
int cmp(const void *a,const void *b)
{return *(int *)a-*(int *)b;}
int find(int a)
{ int low=0,high=k,mid;
        while(low<=high){ 
          mid=(low+high)/2;
          if(a==num[mid]) return count[mid];
          if(num[mid]>a)
             high=mid-1;
          else
             low=mid+1;
         }
    return 0;
   }
