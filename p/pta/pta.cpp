
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

int N;
int H[1111111];
int dp[1111111];
void solve(){
    int K;scanf("%lld",&K);
    
    deque<int>deq;
    deq.pb(0);
    for(int i=1;i<N;i++){
        if(deq.front()+K<i)deq.pop_front();
        dp[i]=dp[deq.front()]+(H[deq.front()]<=H[i]);
        while(deq.size()&&(dp[deq.back()]>dp[i]||(dp[deq.back()]==dp[i]&&H[deq.back()]<=H[i])))deq.pop_back();
        deq.push_back(i);
    }
    printf("%lld\n",dp[N-1]);
}

signed main(){
    scanf("%lld",&N);
    rep(i,N)scanf("%lld",&H[i]);

    int Q;
    scanf("%lld",&Q);
    while(Q--)solve();
    return 0;
}