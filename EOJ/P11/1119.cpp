#include<iostream>
#include<stdio.h>
using namespace std;
int a[10005];
int main(){
	int n;
	while(scanf("%d",&n)&&n){
		for(int i = 0;i < n;i ++){
			scanf("%d",&a[i]);
		}
		int ca = 0;
		while(1){
			ca ++;
			int t = a[n-1]>>1;
			for(int i = 0;i < n;i ++){
				int tem = a[i]>>1;
				a[i] = tem + t;
				t = tem;
				if(a[i]%2 == 1)a[i]++;
			}
			int i;
			for(i = 1;i < n;i ++){
				if(a[i] != a[i-1])break;
			}
			if(i == n){
				printf("%d %d\n",ca,a[0]);
				break;
			}
		}
	}
	return 0;
}
