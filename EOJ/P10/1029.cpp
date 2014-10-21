#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
bool v[13][13];
long long ans[12][12];
/*void dfs(int cnt){
	//printf("cnt = %d\n",cnt);
	if(cnt == m * n){
		ans ++;
		return ;
	}
	for(int i = 0;i < n;i ++){
		for(int j = 0;j < m;j ++){
			bool f = false;
			if(j + 1 < m && !v[i][j] && !v[i][j + 1]){
				//printf("i = %d j = %d\n",i,j);
				v[i][j] = v[i][j + 1] = true;
				f = true;
				dfs(cnt + 2);
				v[i][j] = v[i][j + 1] = false;
				//return ;
			}
			if(i + 1 < n && !v[i][j] && !v[i + 1][j]){
				//printf("i = %d j = %d\n",i,j);
				v[i][j] = v[i + 1][j] = true;
				dfs(cnt + 2);
				v[i][j] = v[i + 1][j] = false;
				return ;
			}
			if(f)return ;
		}
	}
}*/
int main(){
	//int n;
	/*ans[0] = 1;
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
	ans[30] = 299303201;*/
	ans[1][1] = ans[1][1] = 0;
	ans[2][1] = ans[1][2] = 1;
	ans[3][1] = ans[1][3] = 0;
	ans[4][1] = ans[1][4] = 1;
	ans[5][1] = ans[1][5] = 0;
	ans[6][1] = ans[1][6] = 1;
	ans[7][1] = ans[1][7] = 0;
	ans[8][1] = ans[1][8] = 1;
	ans[9][1] = ans[1][9] = 0;
	ans[10][1] = ans[1][10] = 1;
	ans[11][1] = ans[1][11] = 0;
	ans[2][2] = ans[2][2] = 2;
	ans[3][2] = ans[2][3] = 3;
	ans[4][2] = ans[2][4] = 5;
	ans[5][2] = ans[2][5] = 8;
	ans[6][2] = ans[2][6] = 13;
	ans[7][2] = ans[2][7] = 21;
	ans[8][2] = ans[2][8] = 34;
	ans[9][2] = ans[2][9] = 55;
	ans[10][2] = ans[2][10] = 89;
	ans[11][2] = ans[2][11] = 144;
	ans[3][3] = ans[3][3] = 0;
	ans[4][3] = ans[3][4] = 11;
	ans[5][3] = ans[3][5] = 0;
	ans[6][3] = ans[3][6] = 41;
	ans[7][3] = ans[3][7] = 0;
	ans[8][3] = ans[3][8] = 153;
	ans[9][3] = ans[3][9] = 0;
	ans[10][3] = ans[3][10] = 571;
	ans[11][3] = ans[3][11] = 0;
	ans[4][4] = ans[4][4] = 36;
	ans[5][4] = ans[4][5] = 95;
	ans[6][4] = ans[4][6] = 281;
	ans[7][4] = ans[4][7] = 781;
	ans[8][4] = ans[4][8] = 2245;
	ans[9][4] = ans[4][9] = 6336;
	ans[10][4] = ans[4][10] = 18061;
	ans[11][4] = ans[4][11] = 51205;
	ans[5][5] = ans[5][5] = 0;
	ans[6][5] = ans[5][6] = 1183;
	ans[7][5] = ans[5][7] = 0;
	ans[8][5] = ans[5][8] = 14824;
	ans[9][5] = ans[5][9] = 0;
	ans[10][5] = ans[5][10] = 185921;
	ans[11][5] = ans[5][11] = 0;
	ans[6][6] = ans[6][6] = 6728;
	ans[7][6] = ans[6][7] = 31529;
	ans[8][6] = ans[6][8] = 167089;
	ans[9][6] = ans[6][9] = 817991;
	ans[10][6] = ans[6][10] = 4213133;
	ans[11][6] = ans[6][11] = 21001799;
	ans[7][7] = ans[7][7] = 0;
	ans[8][7] = ans[7][8] = 1292697;
	ans[9][7] = ans[7][9] = 0;
	ans[10][7] = ans[7][10] = 53175517;
	ans[11][7] = ans[7][11] = 0;
	ans[8][8] = ans[8][8] = 12988816LL;
	ans[9][8] = ans[8][9] = 108435745LL;
	ans[10][8] = ans[8][10] = 1031151241LL;
	ans[11][8] = ans[8][11] = 8940739824LL;
	ans[9][9] = ans[9][9] = 0;
	ans[10][9] = ans[9][10] = 14479521761LL;
	ans[11][9] = ans[9][11] = 0;
	ans[10][10] = ans[10][10] = 258584046368LL;
	ans[10][11] = ans[11][10] = 3852472573499LL;
 
	//while(scanf("%d",&n) && n != -1){
	//	if(n & 1)printf("0\n");
	//	else printf("%d\n",ans[n]);
	//}
	/*for(n = 8;n < 12;n ++){
		for(m = n;m < 12;m ++){
			ans = 0;
			//m = 2,n = 11;
			memset(v,false,sizeof(v));
			if((m * n) % 2 == 0)dfs(0);
			//if(m == 4 || m == 5)ans /= 2;
			//if(m == 6 || m == 7)ans /= 6;
			//if(m == 9 || m == 8)ans /= 24;
			//if(m == 10 || m == 11)ans /= 120;
			printf("ans[%d][%d] = ans[%d][%d] = %lld;\n",m,n,n,m,ans);
		}
	}*/
	int n,m;
	while(scanf("%d%d",&n,&m) && n){
		printf("%lld\n",ans[n][m]);
	}
	return 0;
}
