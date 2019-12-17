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

const int INF=1001001001;
int N,M;
int A[333333];
int B[333333];
int preMin[333333];
signed main(){
	scanf("%d%d",&N,&M);
	rep(i,N)scanf("%d",&A[i]);
	rep(i,M)scanf("%d",&B[i]);
	preMin[0]=INF;
	for(int i=0;i<N;i++)preMin[i+1]=min(preMin[i],A[i]);
	int last=N;
	rep(i,M){
		int lb=0,ub=N+1;
		while(ub-lb>1){
			int mid=(ub+lb)/2;
			if(preMin[mid]<B[i])ub=mid;
			else lb=mid;
		}
		int nex=lb-1;
		chmin(nex,last-1);
		last=nex;
		if(last<0)break;
	}
	if(last<0)last=0;
	else last++;
	cout<<last<<endl;
	return 0;
}