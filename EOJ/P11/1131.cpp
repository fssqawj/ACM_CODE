#include<stdio.h>
#include<string.h>
int findindex(char * b,char c){
	int i;
	for(i=0;i<strlen(b);i++){
		if(b[i]==c)return i;
	}
	return -1;
}
void build(char *a,int abegin,int aend,char*b,int bbegin,int bend){
	char root;
	int rootindex;
	if(bbegin>bend)return;
	if(bbegin==bend){printf("%c",b[bbegin]);return ;}
	root=a[abegin];
	rootindex=findindex(b,root);
	build(a,abegin+1,abegin+rootindex-bbegin,b,bbegin,rootindex-1);
	build(a,abegin+rootindex-bbegin+1,aend,b,rootindex+1,bend);
	printf("%c",root);
}
int main()
{
	char a[30],b[30];
	int len;
	while(scanf("%s%s",a,b)!=EOF){
		len=strlen(a);
		build(a,0,len-1,b,0,len-1);
		printf("\n");
	}
	return 0;
}
