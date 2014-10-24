#include<iostream>
using namespace std;
int a[105][105];
int main()
{
	int n,i,j;
	int k=1;
	a[1][1]=1;
	for(j=1;j<105;j++)
		a[j][1]=0.5*j*j-0.5*j+1;
	for(i=1;i<105;i++){
		for(j=2;j<105;j++){
			a[i][j]=a[i][j-1]+i+j-1;
		}
	}
	while(scanf("%d",&n)&&n>0){
		if(k==1)printf("Case %d:\n",k++);
		else printf("\nCase %d:\n",k++);
		for(i=1;i<=n;i++){
			for(j=1;j<=n-i+1;j++){
				if(j==1)printf("%d",a[i][j]);
				else printf(" %d",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
