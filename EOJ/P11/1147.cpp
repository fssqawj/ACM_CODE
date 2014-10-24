#include<stdio.h>
#include<math.h>
int main()
{int n,jz,i;int sh,a[100]={0};
scanf("%d",&n);
while(n--)
{scanf("%d%d",&sh,&jz);
if(sh==0)printf("0\n");
else if(sh<0){sh=-sh;
    for(i=99;i>=0;i--)
	 {a[i]=sh%jz;
     sh=sh/jz;}
	 printf("-");
	 for(i=0;i<100;i++){if(a[i]==0);else break;}
     for(i;i<100;i++)
	{if(a[i]<10)printf("%d",a[i]);
    if(a[i]>9)printf("%c",a[i]+55);}
     printf("\n");}
else if(sh>0)
     {for(i=99;i>=0;i--)
	{a[i]=sh%jz;
    sh=sh/jz;}
    for(i=0;i<100;i++){if(a[i]==0);else break;}
     for(i;i<100;i++)
	{if(a[i]<10)printf("%d",a[i]);
    if(a[i]>9)printf("%c",a[i]+55);}
    printf("\n");}
}
return 0;
}
