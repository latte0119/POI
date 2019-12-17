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
	scanf("%s",&buf);
	return buf;
}

int N,K;
string S;
signed main(){
	scanf("%d%d",&N,&K);
	S=strin();

	vector<int>idx,black;
	vector<vint>ans;
	rep(i,N){
		idx.pb(i);
		if(S[i]=='c')black.pb(i);
		if(idx.size()<K+1)continue;
		if(black.size()==0)continue;
		int l=idx[idx.size()-(K+1)];
		if(black.back()<l)continue;
		if(black.size()>1&&black[black.size()-2]>=l)continue;
		ans.eb(idx.end()-(K+1),idx.end());
		idx.erase(idx.end()-(K+1),idx.end());
		black.pop_back();
	}

	reverse(all(ans));
	for(auto &v:ans){
		rep(i,v.size()){
			if(i)printf(" ");
			printf("%d",v[i]+1);
		}
		puts("");
	}
	return 0;
}