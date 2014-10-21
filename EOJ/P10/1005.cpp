#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
struct data{
	int num,t,ts;
};
bool operator < (const data &a,const data &b){
	return (a.t == b.t ? a.num > b.num : a.t > b.t);
}
int main(){
	int t;
	scanf("%d",&t);
	int ca = 1;
	while(t --){
		char s[20];
		int k;
		priority_queue <data> q;
		while(scanf("%s",s)){
			if(s[0] == 'R' && s[1] == 'e'){
				data tp;
				scanf("%d%d",&tp.num,&tp.t);
				tp.ts = tp.t;
				q.push(tp);
			}
			else if(s[0] == 'R'){
				scanf("%d",&k);
				break;
			}
		}
		printf("test case %d:\n",ca ++);
		for(int i = 0;i < k; i++){
			data tp = q.top();
			q.pop();
			printf("%d\n",tp.num);
			tp.t += tp.ts;
			q.push(tp);
		}
		if(t)printf("\n");
	}
	return 0;
}
