#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
const int mod = 50003;
const int maxn = 4007;
int a[maxn][4];
vector<int>num[100006];
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < 4;j ++){
				scanf("%d",&a[i][j]);
			}
		}
		for(int i = 0;i < mod * 2;i ++){
			num[i].clear();
		}
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < n;j ++){
				int tm = -1 *(a[i][0] + a[j][1]);
				int id = tm % mod + mod;
				num[id].push_back(tm);
			}
		}
		long long ans = 0;
		for(int i = 0;i < n;i ++){
			for(int j = 0;j < n;j ++){
				int tm = a[i][2] + a[j][3];
				int id = tm % mod + mod;
				for(int k = 0;k < num[id].size();k ++){
				//	printf("tm = %d n = %d\n",tm,num[id][k]);
					if(tm == num[id][k])ans ++;
				}
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}
