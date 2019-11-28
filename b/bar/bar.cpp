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

const int INF=1001001001001001001ll;

int N;
string S;
signed main(){
    cin>>N>>S;

    vint acc(N+2);
    rep(i,S.size()){
        acc[i+1]=acc[i];
        if(S[i]=='p')acc[i+1]++;
        else acc[i+1]--;
    }
    acc[N+1]=-INF;

    vpint vec(N+2);
    rep(i,N+2)vec[i]=pint(acc[i],i);

    stack<pint>stk;
    stk.emplace(N+1,N);
    stk.emplace(N,N-1);
    int ans=0;
    for(int i=N-1;i>=0;i--){
        while(acc[stk.top().fi]>=acc[i]){
            int k=stk.top().se;
            stk.pop();
            if(acc[stk.top().se]<acc[k]){
                auto p=stk.top();
                stk.pop();
                p.se=k;
                stk.push(p);
            }
        }
        chmax(ans,stk.top().se-i);
        stk.emplace(i,i-1);
    }
    cout<<ans<<endl;
    return 0;
}