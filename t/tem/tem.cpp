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
int X[1111111],Y[1111111];

int dp[1111111];
signed main(){
	scanf("%d",&N);
	rep(i,N)scanf("%d%d",&X[i],&Y[i]);


	vint mi,ma;
	for(int i=N-1;i>=0;i--){
		while(mi.size()&&X[mi.back()]<=X[i])mi.pop_back();
		int pos=N;
		if(mi.size())pos=mi.back();


		int lb=-1,ub=ma.size();
		while(ub-lb>1){
			int mid=(ub+lb)/2;
			if(Y[ma[mid]]>=X[i])ub=mid;
			else lb=mid;
		}
		if(lb==-1)chmin(pos,N);
		else chmin(pos,ma[lb]);

		while(ma.size()&&Y[ma.back()]>=Y[i])ma.pop_back();

		if(pos==N||Y[pos]<X[i]){
			dp[i]=pos-i;
		}
		else{
			dp[i]=pos-i+dp[pos];
		}

		ma.pb(i);mi.pb(i);
	}

	cout<<*max_element(dp,dp+N)<<endl;
	return 0;
}