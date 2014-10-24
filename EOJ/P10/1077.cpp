#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
int a[1005][10];
bool inlib[100005];
int bto[100005];
int cnt[1005];
int temp[10];
int cmp(const void *a,const void *b){
	return *(int *)b-*(int *)a;
}
int main()
{
	int m,n,ui,bi;
	int t;
	char c[2];
	while(scanf("%d%d",&m,&n)!=EOF){
		memset(a,0,sizeof(a));
		memset(bto,0,sizeof(bto));
		memset(cnt,0,sizeof(cnt));
		memset(temp,0,sizeof(temp));
		memset(inlib,true,sizeof(inlib));
		if(n==0&&m==0)break;
		scanf("%d",&t);
		while(t--){
			scanf("%s",c);
			if(c[0]=='B'){
				scanf("%d%d",&ui,&bi);
				if(!inlib[bi])printf("The book is not in the library now\n");
				else if(cnt[ui]==9)printf("You are not allowed to borrow any more\n");
				else {
					printf("Borrow success\n");
					cnt[ui]++;
					inlib[bi]=false;
					bto[bi]=ui;
					for(int i=0;i<10;i++){
						if(a[ui][i]==0){
							a[ui][i]=bi;
							break;
						}
					}
				}
			}
			else if(c[0]=='R'){
				scanf("%d",&bi);
				if(inlib[bi])printf("The book is already in the library\n");
				else {
					printf("Return success\n");
					inlib[bi]=true;
					for(int i=0;i<10;i++){
						if(a[bto[bi]][i]==bi)a[bto[bi]][i]=0;
					}
					cnt[bto[bi]]--;
					bto[bi]=0;
				}
			}
			else if(c[0]=='Q'){
				scanf("%d",&ui);
				if(cnt[ui]==0)printf("Empty\n");
				else {
					for(int i=0;i<10;i++)
						temp[i]=a[ui][i];
					qsort(temp,10,sizeof(int),cmp);
					printf("%d",temp[cnt[ui]-1]);
					for(int i=cnt[ui]-2;i>=0;i--){
						printf(" %d",temp[i]);
					}
					printf("\n");
				}
			}
		}
		printf("\n");
	}
	return 0;
}
