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

template<class T>
struct  BinaryIndexedTree{
	int n;
	vector<T>dat;

	BinaryIndexedTree(int n=0):n(n),dat(n+1){}

	void add(int k,T x){
		for(k++;k<=n;k+=k&-k)dat[k]+=x;
	}
	T sum(int k){
		T ret{};
		for(k++;k;k-=k&-k)ret+=dat[k];
		return ret;
	}
};

int N,M;
int K;
vint own[333333];
int goal[333333];

int L[333333],R[333333],A[333333];
signed main(){
	scanf("%lld%lld",&N,&M);
	rep(i,M){
		int o;scanf("%lld",&o);
		o--;
		own[o].pb(i);
	}
	rep(i,N)scanf("%lld",&goal[i]);

	scanf("%lld",&K);
	rep(i,K)scanf("%lld%lld%lld",&L[i],&R[i],&A[i]),L[i]--;
	vint lb(N,0),ub(N,K+1);
	rep(lg,19){
		BinaryIndexedTree<int>bit(2*M+114);
		vector<vint>bucket(K);
		rep(i,N){
			if(lb[i]+1==ub[i])continue;
			int m=(ub[i]+lb[i])>>1;
			bucket[m-1].pb(i);
		}

		rep(i,K){
			int l,r;
			if(L[i]<R[i])tie(l,r)=pint(L[i],R[i]);
			else tie(l,r)=pint(L[i],M+R[i]);
			bit.add(l,A[i]);
			bit.add(r,-A[i]);
			for(auto st:bucket[i]){
				int sum=0;
				for(auto sc:own[st]){
					rep(t,2){
						int pos=sc+t*M;
						sum+=bit.sum(pos);
						chmin(sum,1001001001ll);
					}
				}
				if(sum>=goal[st]){
					ub[st]=i+1;
				}
				else{
					lb[st]=i+1;
				}
			}
		}
	}

	rep(i,N){
		if(lb[i]==K)puts("NIE");
		else printf("%lld\n",ub[i]);
	}
	return 0;
}