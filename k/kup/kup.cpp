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

int N,K;
signed A[2222][2222];

int acc[2222][2222];
int sum(int y,int x,int yy,int xx){
    return acc[yy][xx]-acc[y][xx]-acc[yy][x]+acc[y][x];
}


void solve(int y,int x,int yy,int xx){
    while(sum(y,x,yy,xx)>2*K){
        if(yy-y>1){
            int my=y+1;
            if(sum(y,x,my,xx)>=K)yy=my;
            else y=my;
        }
        else{
            int mx=x+1;
            if(sum(y,x,yy,mx)>=K)xx=mx;
            else x=mx;
        }
    }
    cout<<x+1<<" "<<y+1<<" "<<xx<<" "<<yy<<endl;
}

signed main(){
    scanf("%lld%lld",&K,&N);
    rep(i,N)rep(j,N)scanf("%d",&A[i][j]);
    
    rep(i,N)rep(j,N){
        if(K<=A[i][j]&&A[i][j]<=2*K){
            cout<<j+1<<" "<<i+1<<" "<<j+1<<" "<<i+1<<endl;
            return 0;
        }
    }

    rep(i,N)rep(j,N){
        acc[i+1][j+1]=A[i][j]+acc[i][j+1]+acc[i+1][j]-acc[i][j];
    }
    vector<int>H(N);
    
    for(int i=N-1;i>=0;i--){
        rep(j,N){
            if(2*K<A[i][j])H[j]=0;
            else H[j]++;
        }
        stack<int>stk;
        vint L(N),R(N);
        for(int j=0;j<N;j++){
            while(stk.size()&&H[stk.top()]>=H[j])stk.pop();
            if(stk.size())L[j]=stk.top()+1;
            else L[j]=0;
            stk.push(j);
        }
        stk=stack<int>();
        for(int j=N-1;j>=0;j--){
            while(stk.size()&&H[stk.top()]>=H[j])stk.pop();
            if(stk.size())R[j]=stk.top();
            else R[j]=N;
            stk.push(j);
        }

        rep(j,N){
            int y=i,x=L[j],yy=i+H[j],xx=R[j];
            if(sum(y,x,yy,xx)>=K){
                solve(y,x,yy,xx);
                return 0;
            }
        }
    }

    puts("NIE");
    return 0;
}