#include<stdio.h>
#include<string.h>
int main()
{
	char s[85],a[85];
	int len,i,m=0;
	while(1){
		gets(s);
		if(s[0]=='T'&&s[1]=='H'&&s[2]=='E'&&s[3]==' '&&s[4]=='E'&&s[5]=='N'&&s[6]=='D'&&s[7]=='.'&&s[8]=='\0')break;
		len=strlen(s);
		memset(a,0,sizeof(a));
		m=0;
		for(i=0;i<len;i++){
			if(s[i]>='a'&&s[i]<='z')a[m++]=s[i];
			else if(s[i]>='A'&&s[i]<='Z')a[m++]=s[i]+32;
		}
			for(i=0;i<m/2;i++){
				if(a[i]==a[m-1-i])continue;
				else break;
			}
			if(i>=m/2)printf("Yes\n");
			else printf("No\n");
		}
	return 0;
}
