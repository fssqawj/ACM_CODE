#include<iostream> 
#include<stdio.h>
#include<string.h> 
#include<algorithm>  
using namespace std;  
char array[1005];  
int main(){   
       int t;
       int i,iArraySize;
       scanf("%d",&t);
       while(t--){
       	   scanf("%s",array);
       	   iArraySize=strlen(array);
		   sort(array, array + iArraySize);  
		   do  
		   {  
		      for(int i = 0; i < iArraySize; i++)  
		      {  
		           cout << array[i];   
		      }  
		      cout <<endl;;  
		   } while (next_permutation(array, array + iArraySize));    
	   }
       return 0;  
}
