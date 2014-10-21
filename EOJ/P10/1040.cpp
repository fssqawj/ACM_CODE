#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
const int  MAXN = 20;
double a[MAXN][MAXN+1],b[MAXN];
int main(){
	int n;
	double temp,m;
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		for(int j = 1;j <= n;j ++){
			scanf("%lf",&a[i][j]);
		}
	}
	for(int i = 1;i <= n;i ++){
		scanf("%lf",&a[i][n + 1]);
	}
	for(int i = 1;i <= n - 1;i ++){
		int p = i;
		for(int j = i + 1;j <= n;j ++){
			if(fabs(a[j][i]) > fabs(a[p][i]))p = j;
		}
		for(int k = i;k <= n + 1;k ++){
			m = a[i][k];
			a[i][k] = a[p][k];
			a[p][k] = m;
		}
		for(int j = i + 1;j <= n;j ++){
			temp = a[j][i] / a[i][i];
			for(int k = i;k <= n + 1;k ++){
				a[j][k] = a[j][k] - a[i][k] * temp;
			}
		}
	}
	for(int i = n;i >= 1;i --){
		for(int p = n;p > i;p --){
			a[i][n + 1] = a[i][n + 1] - b[p] * a[i][p];
		}
		b[i]=a[i][n + 1] / a[i][i];
	}
	for(int i = 1;i <= n;i ++){ 
		printf("%.2lf\n",b[i]);
	}
	return 0;
}
