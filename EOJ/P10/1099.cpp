#include<iostream>
#include<stdio.h>
 
using namespace std;
 
bool px(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
     if((y2-y1)*(x4-x3)==(y4-y3)*(x2-x1))return true;
     return false;
}
 
bool px_in(int x1,int y1,int x2,int y2,int x3,int y3){
     if((x2-x1)*(y3-y2)==(x3-x2)*(y2-y1))return true;
     return false;
}
 
int main()
{
    int n;
    int x1,x2,x3,x4,y1,y2,y3,y4;
    scanf("%d",&n);
    cout<<"INTERSECTING LINES OUTPUT"<<endl;
    while(n--){
         scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
         if(px(x1,y1,x2,y2,x3,y3,x4,y4)){
            if(px_in(x1,y1,x2,y2,x3,y3)){
               cout<<"LINE"<<endl;
            }
            else cout<<"NONE"<<endl;
         }
         else {
             double x,y,k1,k2,b1,b2;
             if(x1==x2){
                x=x1;
                k2=(y4-y3)*1.0/(x4-x3);
                b2=y3-k2*x3;
                y=k2*x+b2;
             }
             else if(x3==x4){
                x=x3;
                k1=(y2-y1)*1.0/(x2-x1);
                b1=y2-k1*x2;
                y=k1*x3+b1;
             }
             else {
                k1=(y2-y1)*1.0/(x2-x1);
                b1=y2-k1*x2;       
                k2=(y4-y3)*1.0/(x4-x3);
                b2=y3-k2*x3;
                x=(b1-b2)/(k2-k1);
                y=k1*x+b1;
             }
             printf("POINT %.2lf %.2lf\n",x,y);
        }
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
