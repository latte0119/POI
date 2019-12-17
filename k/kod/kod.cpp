#include<bits/stdc++.h>
using namespace std;


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

const int INF=1001001001;
static const int SEG=1<<15;
pint dat[SEG*2];
int put[SEG*2];
void add(int a,int b,int x,int k=0,int l=0,int r=SEG){
	if(r<=a||b<=l)return;
	if(a<=l&&r<=b){
		put[k]+=x;
		dat[k].fi+=x;
		return;
	}
	add(a,b,x,k*2+1,l,(l+r)/2);
	add(a,b,x,k*2+2,(l+r)/2,r);
	dat[k]=min(dat[k*2+1],dat[k*2+2]);
	dat[k].fi+=put[k];
}
pint query(int a,int b,int k=0,int l=0,int r=SEG){
	if(r<=a||b<=l)return pint(INF,-1);
	if(a<=l&&r<=b)return dat[k];
	pint ret=min(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
	ret.fi+=put[k];
	return ret;
}
signed main(){
	int N;
	scanf("%d",&N);
	vint B(N);
	rep(i,N)scanf("%d",&B[i]);

	rep(i,N){
		dat[i+SEG-1]=pint(B[i],-i);
	}
	for(int i=SEG-2;i>=0;i--){
		dat[i]=min(dat[i*2+1],dat[i*2+2]);
	}

	vint ans(N);
	for(int i=N;i>0;i--){
		pint p=query(0,N);
		if(p.fi!=0){
			puts("NIE");
			return 0;
		}
		int pos=-p.se;
		ans[pos]=i;
		add(pos,pos+1,INF);
		add(pos+1,N,-1);
	}
	rep(i,N){
		printf("%d\n",ans[i]);
	}
	return 0;
}