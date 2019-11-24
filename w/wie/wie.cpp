#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

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

vint calc(vpint X){
	int N=X.size();
	vector<vint>lis(N);
	rep(i,X.size())lis[X[i].fi].pb(i);

	priority_queue<pint,vpint,greater<pint>>que;

	vint x(N);
	rep(i,N){
		for(auto k:lis[i])que.emplace(X[k].se,k);
		if(que.size()==0)return {};
		if(que.top().fi<=i)return {};
		x[que.top().se]=i;
		que.pop();
	}
	return x;
}

signed main(){
	int N;cin>>N;

	vpint X,Y;
	rep(i,N){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		a--;b--;
		Y.eb(a,c);
		X.eb(b,d);
	}

	vint x=calc(X);
	vint y=calc(Y);

	if(x.size()==0||y.size()==0)cout<<"NIE"<<endl;
	else{
		rep(i,N)cout<<y[i]+1<<" "<<x[i]+1<<endl;
	}
	return 0;
}