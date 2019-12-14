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

char buf[1111111];
string strin(){
	scanf("%s",buf);
	return buf;
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

int N;
signed main(){
	scanf("%lld",&N);
	string S,T;
	S=strin();
	T=strin();

	vint P(N);
	vector<vint>bucketS(26),bucketT(26);
	rep(i,N){
		bucketS[S[i]-'A'].pb(i);
		bucketT[T[i]-'A'].pb(i);
	}

	rep(i,26){
		rep(j,bucketS[i].size()){
			P[bucketS[i][j]]=bucketT[i][j];
		}
	}

	BinaryIndexedTree<int>bit(N+114);
	int ans=0;
	for(int i=N-1;i>=0;i--){
		ans+=bit.sum(P[i]);
		bit.add(P[i],1);
	}
	cout<<ans<<endl;
	return 0;
}