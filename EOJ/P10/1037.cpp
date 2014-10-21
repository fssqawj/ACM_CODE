#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool v[33][3];
int ans[33];
int n;
/*void dfs(int cnt){
	//printf("cnt = %d\n",cnt);
	if(cnt == 3 * n){
		ans ++;
		return ;
	}
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < 3;j ++){
			if(j + 1 < 3 && !v[i][j] && !v[i][j + 1]){
				//printf("i = %d j = %d\n",i,j);
				v[i][j] = v[i][j + 1] = true;
				dfs(cnt + 2);
				v[i][j] = v[i][j + 1] = false;
			}
			if(i + 1 < n && !v[i][j] && !v[i + 1][j]){
				//printf("i = %d j = %d\n",i,j);
				v[i][j] = v[i + 1][j] = true;
				dfs(cnt + 2);
				v[i][j] = v[i + 1][j] = false;
				return ;
			}
			//return ;
		}
	}
}*/
int main(){
	int n;
	ans[0] = 1;
	ans[2] = 3;
	ans[4] = 11;
	ans[6] = 41;
	ans[8] = 153;
	ans[10] = 571;
	ans[12] = 2131;
	ans[14] = 7953;
	ans[16] = 29681;
	ans[18] = 110771;
	ans[20] = 413403;
	ans[22] = 1542841;
	ans[24] = 5757961;
	ans[26] = 21489003;
	ans[28] = 80198051;
	ans[30] = 299303201;
	while(scanf("%d",&n) && n != -1){
		if(n & 1)printf("0\n");
		else printf("%d\n",ans[n]);
	}
	return 0;
}
