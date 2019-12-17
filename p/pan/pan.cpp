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

inline bool in(pint p,int k){
	if((p.fi-1)/k<p.se/k)return true;
	return false;
}
void solve(){
	pint A,B;
	scanf("%d%d%d%d",&A.fi,&A.se,&B.fi,&B.se);
	int LIM=1;
	while(LIM*LIM<A.se||LIM*LIM<B.se)LIM++;
	if(A.se>B.se)swap(A,B);
	if(B.fi<=A.se){
		printf("%d\n",A.se);
		return;
	}

	int ans=1;
	for(int i=1;i<=LIM;i++){
		if(in(A,i)&&in(B,i))ans=i;
	}

	rep(uku,2){
		for(int i=1;i<=LIM;i++){
			int x=(A.fi+i-1)/i;
			if(A.se<x*i)continue;
			if(in(B,x))chmax(ans,x);
		}
		swap(A,B);
	}

	pint a=A;
	pint b=B;
	int da=1,db=1;
	while(da<=LIM&&db<=LIM){
		if(a.se<b.se){
			db++;
			b=pint((B.fi+db-1)/db,B.se/db);
		}
		else{
			da++;
			a=pint((A.fi+da-1)/da,A.se/da);
		}
		if(a.fi>a.se||b.fi>b.se)break;

		if(a.se<b.fi||b.se<a.fi)continue;
		chmax(ans,min(a.se,b.se));
		break;
	}
	cout<<ans<<endl;
}

signed main(){
	int N;
	scanf("%d",&N);
	while(N--)solve();
	return 0;
}