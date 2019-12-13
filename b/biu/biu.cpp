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

int N,M;
vint G[111111];

signed main(){
	scanf("%lld%lld",&N,&M);
	rep(i,M){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		G[a].pb(b);G[b].pb(a);
	}

	int mi=0;
	rep(i,N)if(G[mi].size()>G[i].size())mi=i;

	vint lis{mi};
	for(auto u:G[mi])lis.pb(u);

	UnionFindTree uf(N);
	for(auto v:lis){
		vint g(N,1);
		for(auto u:G[v])g[u]=0;
		rep(u,N)if(g[u])uf.unite(v,u);
	}

	vint sz;
	rep(i,N){
		if(uf.find(i)!=i)continue;
		sz.pb(uf.size(i));
	}

	sort(all(sz));
	printf("%lld\n",(int)sz.size());
	rep(i,sz.size()){
		if(i)printf(" ");
		printf("%lld",sz[i]);
	}
	puts("");
	return 0;
}