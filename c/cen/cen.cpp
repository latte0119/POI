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

const int INF=1001001001;

int N,M,K,A,B;
vint G[111111];



int distA[111111];
void calcA(){
    fill_n(distA,N,INF);
    distA[K]=0;
    queue<int>que;
    que.push(K);
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:G[v]){
            if(distA[u]!=INF)continue;
            distA[u]=distA[v]+1;
            que.push(u);
        }
    }
}

int distB[111111];


bool mark[1111111];
void calcB(){
    vector<vint>sca(N);
    rep(i,N)sca[i]=G[i];
    fill_n(distB,N,INF);
    distB[K]=0;
    queue<int>que;
    que.push(K);
    while(que.size()){
        int v=que.front();
        que.pop();
        for(auto u:G[v])mark[u]=true;
        for(auto u:G[v]){
            vint nex;
            for(auto w:sca[u]){
                if(distB[w]!=INF)continue;
                if(mark[w]){
                    nex.pb(w);
                    continue;
                }
                distB[w]=distB[v]+1;
                que.push(w);
            }
            sca[u]=nex;
        }
        for(auto u:G[v])mark[u]=false;
    }
}
signed main(){
    scanf("%lld%lld%lld%lld%lld",&N,&M,&K,&A,&B);
    K--;

    rep(i,M){
        int a,b;
        scanf("%lld%lld",&a,&b);
        a--;b--;
        G[a].pb(b);G[b].pb(a);
    }

    calcA();
    calcB();

    rep(i,N){
        int ans=distA[i]*A;
        if(distA[i]&1){
            chmin(ans,A+distA[i]/2*B);
            chmin(ans,distB[i]*B);
        }
        else{
            chmin(ans,distA[i]/2*B);
        }
        printf("%lld\n",ans);
    }
    return 0;
}