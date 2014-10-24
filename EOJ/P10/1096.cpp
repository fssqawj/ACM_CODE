#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[16][10][10][10][10];
int sum[10][10];
int get(int a,int b,int c,int d){
	return sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
}
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		memset(dp,0x3f,sizeof(dp));
		memset(sum,0,sizeof(sum));
		for(int i = 1;i <= 8;i ++){
			int tem = 0;
			int x = 0;
			for(int j = 1;j <= 8;j ++){
				scanf("%d",&x);
				tem += x;
				sum[i][j] = sum[i - 1][j] + tem;
			}
		}
		for(int i = 1;i <= 8;i ++){
			for(int j = 1;j <= 8;j ++){
				for(int p = i;p <= 8;p ++){
					for(int q = j;q <= 8;q ++){
						dp[0][i][j][p][q] = get(i,j,p,q);
						dp[0][i][j][p][q] *= dp[0][i][j][p][q];
					}
				}
			}
		}
		for(int k = 1;k < n;k ++){
			for(int i = 1;i <= 8;i ++){
				for(int j = 1;j <= 8;j ++){
					for(int p = i;p <= 8;p ++){
						for(int q = j;q <= 8;q ++){
							for(int a = i;a < p;a ++){
								dp[k][i][j][p][q] = min(dp[k][i][j][p][q],min(dp[k - 1][i][j][a][q] + dp[0][a + 1][j][p][q],dp[k - 1][a + 1][j][p][q] + dp[0][i][j][a][q]));
							}
							for(int b = j;b < q;b ++){
								dp[k][i][j][p][q] = min(dp[k][i][j][p][q],min(dp[k - 1][i][j][p][b] + dp[0][i][b + 1][p][q],dp[k - 1][i][b + 1][p][q] + dp[0][i][j][p][b]));
							}
						}
					}
				}
			}
		}
		printf("%.3lf\n",sqrt(dp[n - 1][1][1][8][8] * 1.0 / n - (sum[8][8] * 1.0 / n) * (sum[8][8] * 1.0 / n)));
	}
	return 0;
}
