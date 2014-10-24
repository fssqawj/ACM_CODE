#include<stdio.h>
int main()
{
	int n,k,i,num=0,sum=0,flag=0,a[1025];
	scanf("%d%d",&n,&k);
	for(i=0;i<k;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		if(a[i]>n){flag=1;break;}
		else if(sum>=n){
			num++;
			if(sum>n){
				sum=a[i];
			}
			else sum=0;
		}
	}
	if(flag)printf("No Solution!\n");
	else printf("%d\n",num);
}
