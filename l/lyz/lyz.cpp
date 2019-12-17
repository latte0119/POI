#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

const int INF=1001001001001001001;
struct data{
	int opt;
	int sum;
	int pre,suf;
	data():opt(0),sum(0),pre(0),suf(0){}
};

data op(const data &a,const data &b){
	data c;
	c.sum=a.sum+b.sum;
	c.pre=max(a.pre,a.sum+b.pre);
	c.suf=max(b.suf,b.sum+a.suf);
	c.opt=max(a.opt,b.opt);
	chmax(c.opt,a.suf+b.pre);
	return c;
}

struct segtree{
	static const int SEG=1<<18;
	vector<data>dat;
	segtree(int K):dat(SEG*2){
		for(int i=0;i<SEG;i++){
			dat[i+SEG-1].sum-=K;
		}
		for(int i=SEG-2;i>=0;i--)dat[i]=op(dat[i*2+1],dat[i*2+2]);
	}
	void add(int k,int x){
		k+=SEG-1;
		dat[k].sum+=x;
		dat[k].pre=dat[k].suf=dat[k].opt=max(dat[k].sum,0ll);
		while(k){
			k=(k-1)/2;
			dat[k]=op(dat[k*2+1],dat[k*2+2]);
		}
	}
	data query(int a,int b,int k=0,int l=0,int r=SEG){
		if(r<=a||b<=l)return data();
		if(a<=l&&r<=b)return dat[k];
		return op(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
	}
};

signed main(){
	int N,M,K,D;
	scanf("%lld%lld%lld%lld",&N,&M,&K,&D);
	D++;
	segtree seg(K);
	rep(i,M){
		int r,x;
		scanf("%lld%lld",&r,&x);
		r--;
		seg.add(r,x);

		auto d=seg.query(0,N);
		if(d.opt>=K*D-K+1){
			puts("NIE");
		}
		else{
			puts("TAK");
		}
	}
	return 0;
}