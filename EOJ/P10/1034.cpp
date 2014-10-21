#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int base = 10000;
const int width = 4;
const int N = 200000;
struct bint{
	int ln,v[N];
	bint (int r = 0){
		for(ln = 0;r > 0;r /= base)v[ln++] = r % base;
	}
	bint& operator = (const bint& r){
		memcpy(this,&r,(r.ln + 1) * sizeof(int));
		return *this;
	}
};
bint MOD;
bool read(bint& b,char buf[]){
	if(scanf("%s",buf) != 1)return 0;
	int w,u,ln = strlen(buf);
	memset(&b,0,sizeof(bint));
	if(buf[0] == '0' && buf[1] == 0)return 1;
	for(w = 1,u = 0;ln ; ){
		u += (buf[--ln] - '0') * w;
		if(w * 10 == base){
			b.v[b.ln++] = u;
			u = 0;
			w = 1;
		}
		else w *= 10;
	}
	if(w != 1)b.v[b.ln++] = u;
	return 1;
}
void write(const bint& v){
	int i;
	//cout<<"ln = "<<v.ln<<endl;
	printf("%d", v.ln == 0 ? 0 : v.v[v.ln - 1]);
	for(i = v.ln - 2;i >= 0;i --){
		printf("%04d",v.v[i]);
	}
	printf("\n");
}
bool operator < (const bint& a,const bint& b){
	int i;
	if(a.ln != b.ln) return a.ln < b.ln;
	for(i = a.ln - 1;i >= 0 && a.v[i] == b.v[i];i --);
	return i < 0 ? 0 : a.v[i] < b.v[i];
}
bool operator <= (const bint& a,const bint& b){
	return !(b < a);
}
bint operator + (const bint& a,const bint& b){
	bint res;
	int i,cy = 0;
	for(i = 0;i < a.ln || i < b.ln || cy > 0;i ++){
		if(i < a.ln)cy += a.v[i];
		if(i < b.ln)cy += b.v[i];
		res.v[i] = cy % base;
		cy /= base;
	}
	res.ln = i;
	return res;
}
bint operator - (const bint& a,const bint& b){
	bint res;
	int i,cy = 0;
	for(res.ln = a.ln,i = 0;i < res.ln;i ++){
		res.v[i] = a.v[i] - cy;
		if(i < b.ln)res.v[i] -= b.v[i];
		if(res.v[i] < 0) cy = 1,res.v[i] += base;
		else cy = 0;
	}
	while(res.ln > 0 && res.v[res.ln - 1] == 0)res.ln --;
	return res;
}
bint operator * (const bint& a,const bint& b){
	bint res;
	res.ln = 0;
	if(0 == b.ln){
		res.v[0] = 0;
		return res;
	}
	int i,j,cy;
	for(i = 0;i < a.ln;i ++){
		for(j = cy = 0;j < b.ln || cy > 0;j ++,cy /= base){
			if(j < b.ln) cy += a.v[i] * b.v[j];
			if(i + j < res.ln) cy += res.v[i + j];
			if(i + j >= res.ln) res.v[res.ln++] = cy % base;
			else res.v[i + j] = cy % base;
		}
	}
	return res;
}
bint operator / (const bint& a,const bint& b){
	bint tem,mod,res;
	int i,lf,rg,mid;
	mod.v[0] = mod.ln = 0;
	for(i = a.ln - 1;i >= 0;i --){
		mod = (mod * base + a.v[i]);
		for(lf = 0,rg = base - 1;lf < rg;){
			mid = (lf + rg + 1) / 2;
			if(b * mid <= mod)lf = mid;
			else rg = mid - 1;
		}
		res.v[i] = lf;
		mod = mod - b * lf;
	}
	res.ln = a.ln;
	while(res.ln > 0 && res.v[res.ln - 1] == 0)res.ln --;
	//write(res);
	MOD = mod;
	return res;
}
int digits(bint& a){
	if(a.ln == 0)return 0;
	int l = (a.ln - 1) * 4;
	for(int t = a.v[a.ln - 1];t;++ l,t /= 10);
	return l;
}
bint f(bint k){
	bint ans = 1;
	for(int i = 0;i < k;i ++){
		ans = ans * 2;
	}
	return ans;
}
bint jf(int k){
	bint ans = k;
	for(int i = k - 1;i >= 2;i --){
		ans = ans * i;
	}
	return ans;
}
bint num;
int ans[22];
int main(){
	int year;
	ans[0] = 3;
	ans[1] = 5;
	ans[2] = 8;
	ans[3] = 12;
	ans[4] = 20;
	ans[5] = 34;
	ans[6] = 57;
	ans[7] = 98;
	ans[8] = 170;
	ans[9] = 300;
	ans[10] = 536;
	ans[11] = 966;
	ans[12] = 1754;
	ans[13] = 3210;
	ans[14] = 5910;
	ans[15] = 10944;
	ans[16] = 20366;
	ans[17] = 38064;
	ans[18] = 71421;
	ans[19] = 134480;
	ans[20] = 254016;
 
	//freopen("out","w",stdout);
	//while(scanf("%d",&year) && year != 0){
	//int i = 1;
	//for(year = 1960;year <= 2160;year += 10){
	//	int k = (year - 1960) / 10 + 2;
		//num = f(f(k));
		//write(num);
		//int l = 10000,r = 100000;
		//while(l <= r){
		//	int mid = (l + r)>>1;
		//	if(jf(mid) < num)l = mid + 1;
		//	else r = mid - 1;
		//}
	//	k = 1<<k;
	//	int ans = 2;
	//	double sum = 0;
	//	while(sum <= k){
	//		sum += log(ans) / log(2);
			//ans ++;
	//	}
	//	printf("ans[%d] = %d;\n",(year - 1960) / 10,ans - 2);
	//}
	//}
	while(scanf("%d",&year) && year){
		int k = (year - 1960) / 10 + 2;
		printf("%d\n",ans[k - 2]);
	}
	return 0;
}
