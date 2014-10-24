#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		if(n == 1){
			printf("Win\n");
			continue;
		}
		while(n % 2 == 0)n /= 2;
		if(n == 1)printf("Lost\n");
		else printf("Win\n");
	}
	return 0;
}
