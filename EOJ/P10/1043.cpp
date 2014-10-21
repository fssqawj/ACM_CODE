#include<iostream>
#include<stdio.h>
#include<math.h>
#include<cmath>
#include<string.h>
using namespace std;
const int maxn = 1000005;
bool v[maxn];
int a[305];
void solve(int k){
	int m = (int)(sqrt(k) + 1);
	for(int i = 1;i < m;i ++){
		if(k % i == 0){
			v[i] = true;
			if(k / i != i)v[k / i] = true;
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t --){
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;i ++){
			scanf("%d",&a[i]);
		}
		memset(v,false,sizeof(v));
		for(int i = 0;i < n;i ++){
			for(int j = i + 1;j < n;j ++){
				int k = abs(a[j] - a[i]);
				solve(k);
			}
		}
		for(int i = 1;i < maxn;i ++){
			if(!v[i]){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
