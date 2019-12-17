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

int N;
int A[1111111];
vector<pint>bucket[1111111];
int M;
vector<int>B[1111111];
bool ok[1111111];
signed main(){
	scanf("%d",&N);
	rep(i,N)scanf("%d",&A[i]);

	scanf("%d",&M);
	rep(i,M){
		int n;scanf("%d",&n);
		B[i].resize(n);
		rep(j,n)scanf("%d",&B[i][j]);

		bucket[B[i][0]].eb(i,0);
	}

	rep(i,N){
		auto v=bucket[A[i]];
		bucket[A[i]].clear();
		for(auto p:v){
			if(B[p.fi].size()==p.se+1){
				ok[p.fi]=true;
			}
			else{
				bucket[B[p.fi][p.se+1]].eb(p.fi,p.se+1);
			}
		}
	}

	rep(i,M){
		if(ok[i])puts("TAK");
		else puts("NIE");
	}
	return 0;
}