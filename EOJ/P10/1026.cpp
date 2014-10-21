#include<stdio.h>
#include<math.h>
#define g 9.8
#define l 1.75
int main()
{int f[18],i;double t[18];
for(i=0;i<18;i++)
{scanf("%d",&f[i]);
if(f[i]==0)break;}
for(i=0;i<18;i++)
{if(f[i]==1||2)
    t[i]=sqrt(2*((f[i]-1)*5.0+l)/g);
if(f[i]>2)
	t[i]=sqrt(2*(10.0+(f[i]-3)*3.0+l)/g);}
for(i=0;i<18;i++)
	if(f[i]!=0)printf("%.3f\n",t[i]);
return 0;}
