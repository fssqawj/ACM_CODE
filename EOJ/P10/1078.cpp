#include<stdio.h>
int main()
{int t,m,d,y;
scanf("%d",&t);
while(t--)
{scanf("%d%d",&m,&d);
if(m>10||m==10&&d>21)printf("What a pity, it has passed!\n");
else if(m==10&&d==21)printf("It's today!!\n");
else if(m==10&&d<21)printf("%d\n",21-d);
else if(m==9)printf("%d\n",21-d+30);
else if(m==8)printf("%d\n",21-d+30+31);
else if(m==7)printf("%d\n",21-d+30+31+31);
else if(m==6)printf("%d\n",21-d+30+31+31+30);
else if(m==5)printf("%d\n",21-d+30+31+31+30+31);
else if(m==4)printf("%d\n",21-d+30+31+31+30+31+30);
else if(m==3)printf("%d\n",21-d+30+31+31+30+31+30+31);
else if(m==2)printf("%d\n",21-d+30+31+31+30+31+30+31+28);
else if(m==1)printf("%d\n",21-d+30+31+31+30+31+30+31+28+31);
}
return 0;
}
