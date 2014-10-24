#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    char c[1025],*p;
    int n=0,i=0;
  	while(scanf("%s",&c)!=EOF)
    {
        p=c;
        n = 0;i = 0;
  		while(*(p+i)!='\0'){
	  		i++;
			n++;
		}
    	printf("%d\n",n);
	}
    return 0;
}
