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

int N,M;
string S;

signed main(){
	scanf("%lld%lld",&N,&M);
	cin>>S;
	vint acc(N+1);
	rep(i,N){
		acc[i+1]=acc[i];
		if(S[i]=='T')acc[i+1]+=2;
		else acc[i+1]++;
	}


	vint cand;
	for(int i=0;i<N;i++){
		if(S[i]=='W'){
			cand.pb(i);
			break;
		}
	}
	for(int i=N-1;i>=0;i--){
		if(S[i]=='W'){
			cand.pb(i);
			break;
		}
	}

	while(M--){
		int cost;
		scanf("%lld",&cost);
		
		int pos=lower_bound(all(acc),cost)-acc.begin();
		if(pos<acc.size()&&acc[pos]==cost){
			printf("1 %lld\n",pos);
			continue;
		}

		if(cand.size()){
			int l=cand.front();
			pos=lower_bound(all(acc),acc[l]+cost)-acc.begin();
			if(pos<acc.size()&&acc[pos]==acc[l]+cost){
				printf("%lld %lld\n",l+1,pos);
				continue;
			}
			pos=lower_bound(all(acc),acc[l+1]+cost)-acc.begin();
			if(pos<acc.size()&&acc[pos]==acc[l+1]+cost){
				printf("%lld %lld\n",l+2,pos);
				continue;
			}

			int r=cand.back();
			pos=lower_bound(all(acc),acc[r]-cost)-acc.begin();
			if(pos<acc.size()&&acc[pos]==acc[r]-cost){
				printf("%lld %lld\n",pos+1,r);
				continue;
			}
			pos=lower_bound(all(acc),acc[r+1]-cost)-acc.begin();
			if(pos<acc.size()&&acc[pos]==acc[r+1]-cost){
				printf("%lld %lld\n",pos+1,r+1);
				continue;
			}
		}
		puts("NIE");
	}
	return 0;
}