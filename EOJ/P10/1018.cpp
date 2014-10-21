#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[300];
char a[105][150];
int dp[300];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		memset(dp,0x3f,sizeof(dp));
		scanf("%s",s);
		scanf("%d",&n);
		for(int i = 0;i < n;i ++){
			scanf("%s",a[i]);
		}
		int len = strlen(s);
		dp[0] = 0;
		for(int i = 0;i <= len;i ++){
			for(int j = 0;j < n;j ++){
				int lenn = strlen(a[j]);
				if(lenn > i)break;
				bool flag = true;
				for(int k = i - lenn,p = 0;p < lenn;p ++,k ++){
					if(s[k] != a[j][p]){
						flag = false;
						break;
					}
				}
				if(flag)dp[i] = min(dp[i],dp[i-lenn] + 1);
			}
		}
		printf("%d\n",dp[len]);
	}
	return 0;
}
