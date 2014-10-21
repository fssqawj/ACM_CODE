#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmpc(const void *a,const void *b){
	return *(char *)a-*(char *)b;
}
int cmpi(const void *a,const void *b){
	return *(int  *)a-*(int  *)b;
}
int main()
{
	char a[110],b[110],c;
	int i,j=0,k=0,p=0 ,a1[110]={0},b1[110]={0};
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s",a,b);
		qsort(a,strlen(a),sizeof(char),cmpc);
		qsort(b,strlen(b),sizeof(char),cmpc);
		if(strlen(a)!=strlen(b))printf("NO\n");
		else {
			for(i=0;i<strlen(a);){
				c=a[i];
				j++;
			    i++;
				while(a[i]==c){
					j++;i++;
				}
				a1[k++]=j;
				j=0;
			}
			for(i=0;i<strlen(b);){
				c=b[i];
				j++;
				i++;
				while(b[i]==c){
					j++;i++;
				}
				b1[p++]=j;
				j=0;
			}
			qsort(a1,k,sizeof(int),cmpi);
			qsort(b1,p,sizeof(int),cmpi);
			for(i=0;i<(k>p?k:p);i++){
				if(a1[i]!=b1[i]){printf("NO\n");break;}
			}
			if(i== (k>p?k:p))printf("YES\n");
		}
		for(i=0;i<101;i++){
			a[i]=b[i]='\0';
			a1[i]=b1[i]=0;
		}
		k=p=j=0;
	}
	return 0;
}
