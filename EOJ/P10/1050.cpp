#include<iostream>
using namespace std;
int a[105][105];
int b[105][105];
int ans[105][105];
int main(){
	int t,n;
	int i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&b[i][j]);
			}
		}
		memset(ans,0,sizeof(ans));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<n;k++){
					ans[i][j]+=a[i][k]*b[k][j];
				}
			}
		}
		for(i=0;i<n;i++){
			printf("%d",ans[i][0]);
			for(j=1;j<n;j++){
				printf(" %d",ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
