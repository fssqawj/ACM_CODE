#include<stdio.h>
#include<string.h>
int main()
{
	int i,j,ans,m=0;
	int l1,l2;
	char s1[15],s2[15];
	while(scanf("%s%s",s1,s2)!=EOF){
		if(s1[0]=='0'&&s2[0]=='0'&&s1[1]=='\0'&&s2[1]=='\0')break;
		ans=m=0;
		l1=strlen(s1);
		l2=strlen(s2);
		for(i=l1-1,j=l2-1;j>=0&&i>=0;i--,j--){
			if(s1[i]-'0'+s2[j]-'0'+m>=10){
				ans++;
				m=1;
			}
			else m=0;
		}
		if(m==1){
			for(;i>=0;i--){
				if(s1[i]-'0'+m>=10){
					ans++;
					m=1;
				}
				else m=0;
			}
			for(;j>=0;j--){
				if(s2[j]-'0'+m>=10){
					ans++;
					m=1;
				}
				else m=0;
			}
		}
		if(ans==0)printf("No carry operation.\n");
		else {
			if(ans==1)printf("%d carry operation.\n",ans);
			else printf("%d carry operations.\n",ans);
		}
	}
	return 0;
}
