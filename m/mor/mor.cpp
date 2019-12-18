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

int N,M,K;
vint G[5555];

const int INF=1001001001;
int dist[5010][2];
void bfs(int s){
	rep(i,N)rep(j,2)dist[i][j]=INF;
	dist[s][0]=0;
	queue<pint>que;
	que.emplace(s,0);
	while(que.size()){
		int v,p;
		tie(v,p)=que.front();
		que.pop();
		for(auto u:G[v]){
			if(dist[u][p^1]!=INF)continue;
			dist[u][p^1]=dist[v][p]+1;
			que.emplace(u,p^1);
		}
	}
}

int S[1111111],T[1111111],D[1111111];
vint bucket[1111111];
bool ans[1111111];
signed main(){
	scanf("%d%d%d",&N,&M,&K);
	rep(i,M){
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		G[a].pb(b);G[b].pb(a);
	}

	rep(i,K)scanf("%d%d%d",&S[i],&T[i],&D[i]),S[i]--,T[i]--;
	rep(i,K)bucket[S[i]].pb(i);

	rep(s,N){
		bfs(s);
		for(auto q:bucket[s]){
			int tmp=dist[T[q]][D[q]&1];
			if(tmp<=D[q]&&G[T[q]].size())ans[q]=true;
		}
	}
	rep(i,K){
		if(ans[i])puts("TAK");
		else puts("NIE");
	}
	return 0;
}