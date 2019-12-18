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



const int lg=15;
vector<int>bucket[1<<15];

int L[1111111];
int cnt[1<<15];
signed main(){
	int l;
	int N=0;
	while(scanf("%d",&l),l){
		bucket[l>>lg].pb(l);
		N++;
	}
	

	int n=0;
	rep(i,bucket[0].size())cnt[bucket[0][i]]++;
	for(int i=0;i<1<<lg;i++){
		rep(j,cnt[i]){
			L[n++]=i;
		}
	}


	for(int i=1;i<1<<lg;i++){
		if(bucket[i].size()>2){
			cout<<bucket[i][0]<<" "<<bucket[i][1]<<" "<<bucket[i][2]<<endl;
			return 0;
		}
		sort(all(bucket[i]));
		for(auto x:bucket[i]){
			L[n++]=x;
		}
	}

	for(int i=0;i+2<N;i++){
		if(L[i]+L[i+1]>L[i+2]){
			cout<<L[i]<<" "<<L[i+1]<<" "<<L[i+2]<<endl;
			return 0;
		}
	}

	rep(i,N)for(int j=i+1;j+1<N;j++){
		if(L[i]+L[j]>L[j+1]){
			cout<<L[i]<<" "<<L[j]<<" "<<L[j+1]<<endl;
			return 0;
		}
	}
	cout<<"NIE"<<endl;
	return 0;
}