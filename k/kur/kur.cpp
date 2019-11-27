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

template<class T,class F>
struct SegmentTree{
    F f;
    T ti;
    vector<T>dat;
    int sz;
    SegmentTree(const F &f,const T &ti):f(f),ti(ti){}
    void build(const vector<T>&v){
        assert(v.size());
        sz=1;
        while(sz<v.size())sz<<=1;
        dat.resize(sz<<1,ti);
        for(int i=0;i<v.size();i++)dat[sz-1+i]=v[i];
        for(int i=sz-2;i>=0;i--)dat[i]=f(dat[i*2+1],dat[i*2+2]);
    }

    inline void update(int k,T x){
        k+=sz-1;
        dat[k]=x;
        while(k){
            k=(k-1)/2;
            dat[k]=f(dat[k*2+1],dat[k*2+2]);
        }
    }

    inline void add(int k,int x){
        k+=sz-1;
        dat[k]=f(dat[k],x);
        while(k){
            k=(k-1)/2;
            dat[k]=f(dat[k*2+1],dat[k*2+2]);
        }
    }

    inline T query(int a,int b){
        return query(a,b,0,0,sz);
    }
    T query(int a,int b,int k,int l,int r){
        if(r<=a||b<=l)return ti;
        if(a<=l&&r<=b)return dat[k];
        return f(query(a,b,k*2+1,l,(l+r)/2),query(a,b,k*2+2,(l+r)/2,r));
    }
};

auto f=[](pint p,pint q){
    if(p.se==q.se){
        p.fi+=q.fi;
        return p;   
    }
    if(p>q)swap(p,q);
    q.fi-=p.fi;
    return q;
};
SegmentTree<pint,decltype(f)>seg(f,pint(0,-1));

vint lis[555555];
signed main(){
    int N,Q;
    scanf("%lld%lld",&N,&Q);

    vpint ini;
    rep(i,N){
        int a;scanf("%lld",&a);
        ini.eb(1,a);
        lis[a].pb(i);
    }
    seg.build(ini);

    rep(i,Q){
        int l,r;
        scanf("%lld%lld",&l,&r);
        l--;
        auto p=seg.query(l,r);

        bool ok=false;
        if(p.fi){
            int cnt=lower_bound(all(lis[p.se]),r)-lower_bound(all(lis[p.se]),l);
            if(cnt*2>r-l)ok=true;
        }
        if(ok)printf("%lld\n",p.se);
        else puts("0");
    }
    return 0;
}