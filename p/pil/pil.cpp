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

signed main(){
	int T,N;
	scanf("%lld%lld",&T,&N);
	vint A(N);
	rep(i,N)scanf("%lld",&A[i]);

	deque<int>ma{0},mi{0};
	int r=1;
	int ans=0;
	rep(i,N){
		if(ma.front()<i)ma.pop_front();
		if(mi.front()<i)mi.pop_front();
		if(ma.size()==0){
			ma.pb(i);mi.pb(i);
			r=i+1;
		}
		while(r<N&&max(A[ma.front()],A[r])-min(A[mi.front()],A[r])<=T){
			while(ma.size()&&A[ma.back()]<=A[r])ma.pop_back();
			while(mi.size()&&A[mi.back()]>=A[r])mi.pop_back();
			ma.pb(r);
			mi.pb(r);
			r++;
		}
		chmax(ans,r-i);
	}
	cout<<ans<<endl;
	return 0;
}