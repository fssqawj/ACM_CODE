#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
long long a[40];
long long b[40];
void init(){
	a[0] = a[1] = 1;
	b[0] = 0;
	for(int i = 1;i < 40;i ++){
		a[i] = 0;
		for(int j = 0;j < i;j ++){
			a[i] += a[j] * a[i - j - 1];
		}
		b[i] = a[i] + b[i - 1];
		//cout<<"i = "<<i<<" a = "<<a[i]<<" b = "<<b[i]<<endl;
	}
}
void dfs(long long n){
	if(n == 1)printf("X");
	else {
	        int k,i;
	        for(k = 1;;k ++){
	                if(b[k] >= n)break;
	        }
	        n -= b[k - 1];
	        for(i = 0;i < k;i ++){
	        	if(n - a[i] * a[k - i - 1] > 0)n -= a[i] * a[k - i - 1];
	        	else break;
	        }
	        if(i != 0){
			printf("(");
			dfs(b[i - 1] + 1 + (n - 1) / a[k - 1 - i]);
			printf(")");  
		}  
		printf("X");  
		if(i != k - 1){  
			printf("(");  
			dfs(b[k - 2 - i] + 1 + (n - 1) % a[k - 1 - i]);  
			printf(")");  
		}  
	}
}
int main(){
	long long n;
	init();
	while(scanf("%lld",&n) && n){
		dfs(n);
		printf("\n");
	} 
	return 0;
}
