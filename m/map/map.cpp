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

int N,R;
int A[333][333];
int acc[333][333];
int sum(int y,int x,int yy,int xx){
	chmax(y,0);
	chmax(x,0);
	chmin(yy,N);
	chmin(xx,N);
	return acc[yy][xx]-acc[y][xx]-acc[yy][x]+acc[y][x];
}
signed main(){
	scanf("%lld%lld",&N,&R);
	rep(i,N)rep(j,N)scanf("%lld",&A[i][j]);
	rep(i,N)rep(j,N)acc[i+1][j+1]=A[i][j]+acc[i+1][j]+acc[i][j+1]-acc[i][j];

	rep(i,N){
		rep(j,N){
			int ans=sum(i-R,j-R,i+R+1,j+R+1);
			if(j)printf(" ");
			printf("%lld",ans);
		}
		puts("");
	}
	return 0;
}