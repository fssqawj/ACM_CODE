//解线性方程组AX=b的LU分解法
//输入：1）矩阵A的值  2）b的值
//输出：1）矩阵L和矩阵U的值  2）方程组的解X的值
//*******************************************************************
#include <iostream>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;
const int ROW_COL=100;
double A[ROW_COL][ROW_COL];
double b[ROW_COL];
double L[ROW_COL][ROW_COL];
double U[ROW_COL][ROW_COL];
double x[ROW_COL];
double y[ROW_COL];
int main(){
	int n=1;
	cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
          // cout<<"A["<<i<<"]"<<"["<<j<<"]=";
           cin>>A[i][j];
		}
	}
	//cout<<"请输入右端项b的值:"<<endl;
	for(int ii=1;ii<=n;ii++){
		//cout<<"b["<<ii<<"]=";
        cin>>b[ii];
	}
    for(int i=1;i<=n;++i){
       for(int j=1;j<=n;++j){
           L[i][j]=0;
           U[i][j]=0;
	   }
       L[i][i]=1;
	}
   for(int j=1;j<=n;j++){
       U[1][j]=A[1][j];
   }
   for(int i=2;i<=n;i++){
       L[i][1]=A[i][1]/U[1][1];
   }
   double s1=0,s2=0,s3=0,s4=0;
   for(int k=2;k<=n;k++){
      int m=1;
      for(int j=k;j<=n;j++){
         for(m=1;m<=k-1;m++){
            s1+=L[k][m]*U[m][j];
		 }
         U[k][j]=A[k][j]-s1;
         s1=0;
	  }
      for(int i=k+1;i<=n;i++){
         for(m=1;m<=k-1;m++){
            s2+=L[i][m]*U[m][k];
		 }
         L[i][k]=(A[i][k]-s2)/U[k][k];
         s2=0;
	  }
   }
   /*
   cout<<"输出矩阵U的值"<<endl;
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
   {
         cout<<setw(3)<<U[i][j]<<ends;
   }
      cout<<endl;
   }
   cout<<"输出矩阵L的值"<<endl;
   for(int i=1;i<=n;i++)
   {
      for(int j=1;j<=n;j++)
   {
        cout<<setw(3)<<L[i][j]<<ends;
   }
      cout<<endl;
   }
 */
   y[1]=b[1];
   for(int i=2;i<=n;i++){
      for(int j=1;j<=i-1;j++){
         s3+=L[i][j]*y[j];
	  }
      y[i]=b[i]-s3;
      s3=0;
   }
   x[n]=y[n]/U[n][n];
   for(int i=n-1;i>=1;i--){
      for(int j=n;j>=i+1;j--){
         s4+=U[i][j]*x[j];
	  }
      x[i]=(y[i]-s4)/U[i][i];
      s4=0;
   }
   for(int i=1;i<=n;i++){
      printf("%.2lf\n",x[i]);
   }
   return 0;
}
