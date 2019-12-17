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

struct UnionFindTree{
	vector<int>par,sz;
	UnionFindTree(int n){
		par.resize(n);
		sz.resize(n);
		for(int i=0;i<n;i++){
			par[i]=i;
			sz[i]=1;
		}
	}
	int find(int x){
		return x==par[x]?x:par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x=find(x);y=find(y);
		if(x==y)return;
		if(sz[x]<sz[y])swap(x,y);
		sz[x]+=sz[y];
		par[y]=x;
	}
	bool areSame(int x,int y){
		return find(x)==find(y);
	}
	int size(int x){
		return sz[find(x)];
	}
};

signed main(){
	int N;scanf("%lld",&N);
	UnionFindTree uf(N);
	rep(i,N){
		int a;scanf("%lld",&a);
		a--;
		uf.unite(i,a);
	}

	int ans=0;
	rep(i,N)if(uf.find(i)==i)ans++;
	cout<<ans<<endl;
	return 0;
}