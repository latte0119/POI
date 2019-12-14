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
	int N;
	scanf("%lld",&N);
	vint H(N);
	rep(i,N){
		int w;
		scanf("%lld%lld",&w,&H[i]);
	}

	set<int>idx;
	vint ord(N);iota(all(ord),0);
	sort(all(ord),[&](int i,int j){
		if(H[i]==H[j])return i<j;
		return H[i]<H[j];
	});

	int ans=0;
	for(auto i:ord){
		auto it=idx.lower_bound(i);
		if(it!=idx.begin()){
			it--;
			if(H[*it]==H[i]);
			else ans++;
		}
		else{
			ans++;
		}
		idx.insert(i);
	}
	cout<<ans<<endl;
	return 0;
}