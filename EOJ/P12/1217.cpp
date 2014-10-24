#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
bool v[10005];
int main(){
	int a = 1,b = 2;
	memset(v,false,sizeof(v));
	for(;b < 10005;){
		v[b] = true;
		int c = b;
		b = a + b;
		a = c;
	}
	int n;
	while(scanf("%d",&n) != EOF){
		if(v[n])printf("Lost\n");
		else printf("Win\n");
	}
	return 0;
}
