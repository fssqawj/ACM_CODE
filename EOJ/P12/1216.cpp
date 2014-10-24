#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		if(n < 7 || n == 14){
			printf("Draw\n");
			continue;
		}
		if(n % 2 == 1)printf("First Win\n");
		else {
			if(n > 14)printf("Second Win\n");
			else printf("Draw\n");
		}
	}
	return 0;
}
