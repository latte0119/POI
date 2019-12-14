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
const int INF=1001001001;
int N,M;
int H[222222][2];

vpint G[222222];
int ans[222222];
void dfs(int v,int p,int mi){
	ans[v]=mi;
	for(auto e:G[v]){
		if(e.fi==p)continue;
		dfs(e.fi,v,min(mi,e.se));
	}
}
signed main(){
	scanf("%d%d",&N,&M);
	rep(i,N)rep(j,2){
		scanf("%d",&H[i][j]);
		if(H[i][j]>0)H[i][j]--;
	}

	vector<tuple<int,int,int>>es;
	rep(i,M){
		int m,h;
		scanf("%d%d",&m,&h);
		m--;h--;
		es.eb(i,m,H[m][h]);
		H[m][h]=-1;
	}
	rep(i,N)rep(j,2)if(H[i][j]!=-1){
		es.eb(INF,i,H[i][j]);
	}
	sort(all(es));
	reverse(all(es));
	UnionFindTree uf(N);
	for(auto tup:es){
		int cost,u,v;
		tie(cost,u,v)=tup;
		if(uf.areSame(u,v))continue;
		uf.unite(u,v);
		G[u].eb(v,cost);
		G[v].eb(u,cost);
	}
	dfs(0,-1,INF);
	rep(i,N){
		if(ans[i]==INF)puts("-1");
		else printf("%d\n",ans[i]);
	}
	return 0;
}