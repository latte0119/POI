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
vint G[333333];
int K;
int dp[333333];
void dfs(int v,int p){
    dp[v]=0;
    for(auto u:G[v]){
        if(u==p)continue;
        dfs(u,v);
        dp[v]+=dp[u];
    }
    dp[v]=max(0ll,dp[v]-K);
    dp[v]++;
}

bool check(int k){
    K=k;
    dfs(0,-1);
    return dp[0]==1;
}

signed main(){
    scanf("%lld",&N);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }
    int lb=-1,ub=N;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(check(mid))ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;
}