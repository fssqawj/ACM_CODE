#include <iostream>  
#include <stdio.h>  
using namespace std;  
const int N=2200000;  
bool ans[N];  
char sym[N],a[N];  
int p[N],end,top;  
void cal(char c)  
{  
    if(c=='!')  
        ans[top]=!ans[top];  
    else if(c=='|')  
        ans[top-1]=ans[top-1]|ans[top],top--;  
    else if(c=='&')  
        ans[top-1]=ans[top-1]&ans[top],top--;  
    //cout<<top<<endl<<endl;  
}  
int main()  
{  
    p['!']=3;  
    p['&']=2;  
    p['|']=1;  
    int kk=1;  
    while(gets(a))  
    {  
        int i;  
        top=end=0;  
        for(i=0;a[i];i++)  
        {  
            if(a[i]=='(')  
                sym[++end]='(';  
            else if(a[i]==')')  
                while(sym[end--]!='(')  
                    cal(sym[end+1]);  
            else if(a[i]=='V')  
                ans[++top]=true;  
            else if(a[i]=='F')  
                ans[++top]=false;  
            else if(p[a[i]])  
            {  
                while(end&&p[a[i]]<=p[sym[end]]&&a[i]!='!')  
                    cal(sym[end--]);  
                sym[++end]=a[i];  
            }  
        }  
        while(end)  
            cal(sym[end--]);  
        printf("Expression %d: ",kk++);  
        puts(ans[1]?"V":"F");  
    }  
    return 0;  
}
