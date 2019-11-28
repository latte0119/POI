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

int N,M;
int L[333333],R[333333];

bool used[333333];
set<int>s;
int calc(int k){
    int ret=R[k]-L[k];
    auto it=s.lower_bound(k);
    if(it!=s.end()){
        ret-=max(0ll,R[k]-L[*it]);
    }
    if(it!=s.begin()){
        it--;
        ret-=max(0ll,R[*it]-L[k]);
    }
    chmax(ret,0ll);
    return ret;
}

signed main(){
    scanf("%lld%lld",&N,&M);
    rep(i,M)scanf("%lld%lld",&L[i],&R[i]);

    priority_queue<pint,vector<pint>,greater<pint>>que;
    rep(i,M){
        que.emplace(R[i]-L[i],i);
    }

    while(que.size()){
        int c,i;
        tie(c,i)=que.top();
        que.pop();

        if(used[i])continue;
        used[i]=true;
        s.insert(i);
        printf("%lld\n",i+1);

        auto it=s.lower_bound(i);
        if(it!=s.begin()){
            it--;
            if(*it+2<i){
                que.emplace(calc(*it+1),*it+1);
            }
        }

        if(i+1<M&&!used[i+1]){
            que.emplace(calc(i+1),i+1);
        }
        if(i&&!used[i-1])que.emplace(calc(i-1),i-1);
    }

    return 0;
}