#include <stdio.h>
__int64 p[1000002];
 
int main(int nn,char*mm[])
{
	__int64 a,b,t,num=0,i,n;
    p[1]=1;
	for(i=1;i<1000001;i++)
    {n=i;
     while(n!=1)
          {if(n%2==1)n=3*n+1;
           else n=n/2;
           num++;
           if(n<1000001&&p[n]>0){p[i]=p[n]+num;break;}
          }
    p[1]=1;
    num=0;}
	while(scanf("%I64d%I64d",&a,&b) != EOF)
	{
		printf("%I64d %I64d ", a, b);
		if (a>b)
		{
			t=a;a=b;b=t;
		}
		t=0;
		for (i=a; i<=b; i++)
		{
			if (t<p[i])
			{
				t=p[i];
			}
		}
		printf("%I64d\n", t);
	}
	return 0;
}
