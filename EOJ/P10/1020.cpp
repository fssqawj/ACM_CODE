#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int get(char c){
	if(c == 'A')return 11;
	if(c == 'T' || c == 'J' || c == 'Q' || c == 'K')return 10;
	return c - '0';
}
int cnt[13];
int main(){
	int n;
	while(scanf("%d",&n) && n){
		char s[3][3];
		memset(cnt,0,sizeof(cnt));
		scanf("%s%s%s",s[0],s[1],s[2]);
		int p = get(s[1][0]) + get(s[2][0]);
		int d = get(s[0][0]);
		cnt[get(s[0][0])] ++;
		cnt[get(s[1][0])] ++;
		cnt[get(s[2][0])] ++;
		if(p == 22)p = 12;
		int ans = 0;
		for(int i = 2;i <= 11;i ++){
			int t = d + i;
			if(t == 22)t = 12;
			if(t < p){
				if(i == 10)ans += 16 * n - cnt[10];
				else ans += 4 * n - cnt[i];
			}
		}
		printf("%.3lf",ans * 100.0 / (52 * n - 3));
		puts("%");
	}
	return 0;
}
