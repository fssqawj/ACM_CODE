#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	while(t --){
		int n,tm;
		scanf("%d",&n);
		int ans = 0;
		for(int i = 0;i < n;i ++){
			scanf("%d",&tm);
			ans ^= tm;
		}
		if(ans == 0)printf("Lost\n");
		else printf("Win\n");
	}
	return 0;
}
