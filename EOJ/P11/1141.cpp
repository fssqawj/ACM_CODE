#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct data{
	int id;
	bool v[10];
	int cnt[10];
	int t[10];
	int sum;
	int num;
};
data d[105];
bool sub[105];
void init(){
	memset(sub,false,sizeof(sub));
	for(int i = 1;i < 105;i ++){
		d[i].id = i;
		for(int j = 0;j < 10;j ++){
			d[i].v[j] = false;
			d[i].cnt[j] = 0;
		}
		d[i].sum = 0;
		d[i].num = 0;
	}
}
bool cmp(data a,data b){
	if(a.num == b.num){
		if(a.sum == b.sum){
			return a.id < b.id;
		}
		return a.sum < b.sum;
	}
	return a.num > b.num;
}
int main(){
	int id,p,t;
	char s[3];
	init();
	while(scanf("%d%d%d%s",&id,&p,&t,s) != EOF){
		if(s[0] == 'I'){
			if(!d[id].v[p])d[id].cnt[p] ++;
		}
		else if(s[0] == 'C'){
			if(!d[id].v[p]){
				d[id].v[p] = true;
				d[id].num ++;
				d[id].t[p] = t;
			}
		}
		sub[id] = true;
	}
	for(int i = 1;i < 105;i ++){
		if(sub[i]){
			for(int j = 1;j < 10;j ++){
				if(d[i].v[j]){
					d[i].sum += d[i].cnt[j] * 20 + d[i].t[j];
				}
			}
		}
	}
	sort(d,d + 105,cmp);
	for(int i = 0;i < 105;i ++){
		if(sub[d[i].id]){
			printf("%d %d %d\n",d[i].id,d[i].num,d[i].sum);
		}
	}
	return 0;
}
