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

int N,M;
vint G[222222];
int ans[222222];
bool vis[222222];
void dfs(int v,int c){
	ans[v]=c;
	vis[v]=true;
	for(auto u:G[v]){
		if(vis[u])continue;
		dfs(u,c^1);
	}
}
signed main(){
	scanf("%lld%lld",&N,&M);
	rep(i,M){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		G[a].pb(b);G[b].pb(a);
	}

	rep(i,N){
		if(G[i].size()==0){
			puts("NIE");
			return 0;
		}
	}

	rep(i,N){
		if(!vis[i]){
			dfs(i,0);
		}
	}
	puts("TAK");
	rep(i,N){
		if(ans[i])puts("K");
		else puts("S");
	}
	return 0;
}