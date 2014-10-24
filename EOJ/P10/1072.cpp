#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
	int n,i;
	string s;
	set<string>w;
	set<string>::iterator it;
	while(cin>>n){
		for(i=0;i<n;i++){
			cin>>s;
			w.insert(s);}
		for(it=w.begin();it!=w.end();it++){
			cout<<*it<<endl;
		}
		w.clear();
	}
	return 0;
}
