//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int a[100005];
//int cmp(const void *a,const void *b){
//	return *(int *)b-*(int *)a;
//}
//int f(int i){
//	if(i<0)return -i;
//	else return i;
//}
//int main()
//{
//	int sum1=0,sum2=0,i,n;
//	while(scanf("%d",&n)!=EOF){
//		for(i=0;i<n;i++)
//			scanf("%d",&a[i]);
//		qsort(a,n,sizeof(int ),cmp);
//		for(i=0;i<n;i++){
//			if(sum1>sum2)sum2+=a[i];
//			else sum1+=a[i];
//		}
//		printf("%d\n",f(sum1-sum2));
//		sum1=sum2=0;
//	}
//	return 0;
//}
 
 
#include<stdio.h>
int f(int i){
	if(i<0)return -i;
	else return i;
}
int p[2000005],w[100005];
int main()
{
	int n,i,j,sum=0;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&w[i]);
			sum+=w[i];}
		for(i=0;i<n;i++)
			for(j=sum/2;j>=w[i];j--)
				if(p[j]<p[j-w[i]]+w[i])p[j]=p[j-w[i]]+w[i];
		printf("%d\n",f(2*p[sum/2]-sum));
		sum=0;
		for(i=0;i<2000005;i++)
			p[i]=0;
		}
		return 0;
	}
