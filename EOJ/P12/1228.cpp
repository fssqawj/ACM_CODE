#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int a[105][105];
int sum[105];
int ans[105][105];
int f(int i){
	return i>0?i:-i;
}
int main(){
	int t;
	int n,m,i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&m,&n);
		memset(sum,0,sizeof(sum));
		memset(ans,0,sizeof(ans));
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				scanf("%d",&a[i][j]);
			}
		}
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				sum[i]+=a[j][i];
			}
			//cout<<"sum["<<i<<"] = "<<sum[i]<<endl;
		}
		int ansmin=1<<30;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				for(k=0;k<m;k++){
					ans[i][0]+=(f(i-j)+k)*a[j][k];
				}
			}
			//cout<<"ans["<<i<<"][0] = "<<ans[i][0]<<endl;
			if(ans[i][0]<ansmin){
				ansmin=ans[i][0];
			}
			for(j=1;j<m;j++){
				ans[i][j]=ans[i][j-1];
				for(k=0;k<m;k++){
					if(k<j)ans[i][j]+=sum[k];
					else ans[i][j]-=sum[k];
				}
				if(ans[i][j]<ansmin){
					ansmin=ans[i][j];
				}
			}
		}
		printf("%d blocks\n",ansmin);
	}
	return 0;
}
