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

int N;
vint G[5555];
int cnt[5555];
void dfs(int v,int p,int d){
	cnt[d]++;
	for(auto u:G[v]){
		if(u==p)continue;
		dfs(u,v,d+1);
	}
}
signed main(){
	scanf("%lld",&N);
	rep(i,N-1){
		int a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		G[a].pb(b);G[b].pb(a);
	}

	int ans=0;
	rep(i,N){
		vector<vint>bucket(N);
		for(auto u:G[i]){
			dfs(u,i,0);
			for(int j=0;cnt[j];j++){
				bucket[j].pb(cnt[j]);
				cnt[j]=0;
			}
		}
		for(int j=0;j<N;j++){
			int sum1=0,sum2=0;
			for(auto s:bucket[j]){
				ans+=sum2*s;
				sum2+=sum1*s;
				sum1+=s;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}