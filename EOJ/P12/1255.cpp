#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
char s[maxn];
int dp[maxn][maxn];
int op[maxn][maxn];
char opc(char c){
	if(c == '[')return ']';
	if(c == ']')return '[';
	if(c == '(')return ')';
	if(c == ')')return '(';
}
void path(int i,int j){
	if(i > j)return ;
	if(i == j){
		if(s[i - 1] == '(' || s[i - 1] == ')')printf("()");
		else printf("[]");
		return ;
	}
	if(op[i][j] == 0){
		printf("%c",s[i - 1]);
		path(i + 1,j - 1);
		printf("%c",s[j - 1]);
	}
	else {
		path(i,op[i][j]);
		path(op[i][j] + 1,j);
	}
}
int main(){
	while(scanf("%s",s) != EOF){
		int n = strlen(s);
		memset(dp,0x3f,sizeof(dp));
		for(int i = 1;i <= n;i ++){
			dp[i][i - 1] = 0;
			dp[i][i] = 1;
		}
		for(int l = 2;l <= n;l ++){
			for(int i = 1;i <= n - l + 1;i ++){
				int j = i + l - 1;
				dp[i][j] = INF;
				if(s[i - 1] == '(' && s[j - 1] == ')' || s[i - 1] == '[' && s[j - 1] == ']'){
					dp[i][j] = dp[i + 1][j - 1];
					op[i][j] = 0;
				}
				for(int k = i;k < j;k ++){
					if(dp[i][j] > dp[i][k] + dp[k + 1][j]){
						dp[i][j] = dp[i][k] + dp[k + 1][j];
						op[i][j] = k;
					}
				}
			}
		}
		path(1,n);
		printf("\n");
	}
	return 0;
}
