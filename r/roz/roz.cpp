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

char buf[1111111];
string strin(){
    scanf("%s",buf);
    return buf;
}

const int INF=1001001001;

int N;
string S;
vint idx[26];

int arr[1111111];
int acc[1111111];
signed main(){
    scanf("%d",&N);
    S=strin();
    rep(i,N){
        idx[S[i]-'a'].pb(i);
    }

    int ans=0;
    rep(i,26)rep(j,26){
        if(i==j)continue;

        int ii=0,jj=0;
        int n=idx[i].size()+idx[j].size();
        while(ii+jj<n){
            if(ii==idx[i].size()||(jj!=idx[j].size()&&idx[i][ii]>idx[j][jj])){
                arr[ii+jj]=-1;
                jj++;
            }
            else{
                arr[ii+jj]=1;
                ii++;
            }
        }
        rep(k,n)acc[k+1]=acc[k]+arr[k];

        int ma=-INF;
        int las=-1;
        for(int k=0;k<n;k++){
            if(arr[k]==-1){
                while(las<k){
                    las++;
                    chmax(ma,-acc[las]);
                }
            }
            chmax(ans,acc[k+1]+ma);
        }
    }
    cout<<ans<<endl;
    return 0;
}