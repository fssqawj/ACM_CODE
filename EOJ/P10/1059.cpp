#include<iostream>
using namespace std;
int main()
{
	int q,d,n,p,c;
	int maxm,i,j,k,l;
	int nq,nd,nn,np;
	bool flag=false;
	while(cin>>q>>d>>n>>p>>c&&(q||d||n||p||c)){
		maxm=q+d+n+p;
		flag=false;
		for(i=0;i<=q;i++){
			for(j=0;j<=d;j++){
				for(k=0;k<=n;k++){
					for(l=0;l<=p;l++){
						if(i*25+j*10+k*5+l==c){
							flag=true;
   							if(i+j+k+l<=maxm){
							nq=i;
							nd=j;
							nn=k;
							np=l;
							maxm=i+j+k+l;
							}
						}
					}
				}
			}
		}
		if(flag)printf("Dispense %d quarters, %d dimes, %d nickels, and %d pennies.\n",nq,nd,nn,np);
		else printf("Cannot dispense the desired amount.\n");
	}
	return 0;
}
