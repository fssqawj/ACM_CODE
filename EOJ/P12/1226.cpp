#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n) != EOF){
		if(n == 1)printf("Win\n");
		else if(n == 2)printf("Lost\n");
		else {
			int tem = (n - 3) % 7;
			if(tem == 0)printf("Win\n");
			else if(tem == 1)printf("Win\n");
			else if(tem == 2)printf("Win\n");  
			else if(tem == 3)printf("Win\n");
			else if(tem == 4)printf("Lost\n");
			else if(tem == 5)printf("Win\n");
			else if(tem == 6)printf("Lost\n");   
		}
	}
	return 0;
}
