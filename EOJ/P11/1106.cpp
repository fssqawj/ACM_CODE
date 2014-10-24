#include<stdio.h>
int main()
{
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&a,&b);
		if(a==b){
			printf("%d\n",a%2==1?2*a-1:2*a/*,b%2==1?2*b-2:2*b-3*/);
		}
		else if(a-2==b){
			printf("%d\n",a%2==0?2*a-2:2*a-3);
		}
		else {
			printf("No Number\n");
		}
	}
	return 0;
}
