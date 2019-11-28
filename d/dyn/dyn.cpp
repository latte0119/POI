#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
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
int N,M;
int D[333333];
vint G[333333];
int K;
int ans;
int dfs(int v,int p,int d){
    int ex=INF;
    int wn=-INF;
    if(D[v])wn=d;

    for(auto u:G[v]){
        if(u==p)continue;
        int tmp=dfs(u,v,d+1);
        if(tmp==0)continue;
        if(tmp>0){
            chmax(wn,tmp);
        }
        else{
            chmin(ex,-tmp);
        }
    }


    if(wn==-INF&&ex==INF)return 0;
    if(wn==-INF)return -ex;

    if(wn+ex-2*d<=K)return -ex;
    if(v==0||wn-d==K){
        ans++;
        return -d;
    }
    return wn;
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,N)scanf("%lld",&D[i]);
    rep(i,N-1){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }


    int lb=-1,ub=N;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        ans=0;
        K=mid;
        dfs(0,-1,0);
        if(ans<=M)ub=mid;
        else lb=mid;
    }
    cout<<ub<<endl;
    return 0;
}