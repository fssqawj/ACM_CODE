#include <cstdio>  
#include <cstdlib>  
  
char str[110][20];  
char src[20];  
char str0[110][20];  
  
long hash[26] = {2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};  
  
inline void unmap(char& a)  
{  
    a = hash[a-'A'];  
}  
  
int cmpr(const void* aa,const void* bb)  
{  
    char* a = (char*) aa;  
    char* b = (char*) bb;  
    long l = a[0];  
    if (b[0] < l)  
        l = b[0];  
    for (long i=1;i<l+1;i++)  
    {  
        if (a[i] < b[i])  
            return -1;  
        if (a[i] > b[i])  
            return 1;  
    }  
    if (a[0] < b[0])  
        return -1;  
    if (a[0] > b[0])  
        return 1;  
    return 0;  
}  
  
int cmpr2(const char* a,const char* b)  
{  
    long l = a[0];  
    if (b[0] < l)  
        l = b[0];  
    for (long i=1;i<l+1;i++)  
    {  
        if (a[i] < b[i])  
            return -1;  
        if (a[i] > b[i])  
            return 1;  
    }  
    return 0;  
}  
  
bool cmpr3(const char* a,const char* b)  
{  
    long cnt = 0;  
    long l = a[0];  
    if (b[0] < l)  
        l = b[0];  
    for (long i=1;i<l+1;i++)  
    {  
        if (a[i] != b[i])  
        {  
            cnt ++;  
            if (cnt == 2)  
                return false;  
        }  
    }  
    return cnt == 1;  
}  
  
int main()  
{  
    //freopen("phone.in","r",stdin);  
   // freopen("phone.out","w",stdout);  
    long n;  
   while(scanf("%ld",&n) != EOF){  
    for (long i=1;i<n+1;i++)  
    {  
        scanf("%s",str0[i]+1); 
        str0[i][0] = 0; 
        while (str0[i][++str0[i][0]]);str0[i][0]--;  
    }  
    qsort(str0+1,n,sizeof str0[0],cmpr);  
    for (long i=1;i<n+1;i++)  
    {  
        for (long j=1;j<str0[i][0]+1;j++)  
            str[i][j] = hash[str0[i][j]-'A'];  
        str[i][0] = str0[i][0];  
    }  
  
    scanf("%s",src+1);  
    src[0] = 0;
    while (src[++src[0]])  
        src[src[0]] -= '0';  
    src[0]--;  
  
  
    for (long i=1;i<n+1;i++)  
    {  
        if (cmpr(str[i],src)==0)  
        {  
            printf("%s\n",str0[i]+1);  
        }  
    }  
    for (long j=1;j<n+1;++j)  
    {  
        if (cmpr2(str[j],src)==0 && str[j][0]!=src[0])  
        {  
            printf("%s\n",str0[j]+1);  
        }  
    }  
    for (long i=1;i<n+1;i++)  
    {  
        if (cmpr3(str[i],src) && str[i][0]==src[0])  
        {  
            printf("%s\n",str0[i]+1);  
        }  
    }  
    for (long j=1;j<n+1;++j)  
    {  
        if (cmpr3(str[j],src) && str[j][0]!=src[0])  
        {  
            printf("%s\n",str0[j]+1);  
        }  
    }  
}
    return 0;  
}
