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

const int INF=1001001001001001001;
int N;
int A[1111111];

int pre[1111111],suf[1111111];
signed main(){
	scanf("%lld",&N);
	rep(i,N)scanf("%lld",&A[i]);

	int p=0;
	while(p<N&&A[p]==0)p++;
	if(p==N){
		puts("0");
		return 0;
	}
	if(p&&A[p]==-1){
		puts("BRAK");
		return 0;
	}
	if(A[p]==1){
		int ans=0;
		for(int i=p;i<N;i++)ans+=1-A[i];
		printf("%lld\n",ans);
		return 0;
	}

	for(int i=0;i<N;i++){
		pre[i+1]=pre[i]+(A[i]+1);
	}
	for(int i=N-1;i>=0;i--){
		suf[i]=suf[i+1]+(1-A[i]);
	}

	p=N-1;
	while(A[p]==0)p--;
	int ans=pre[p];

	p=-1;
	for(int i=0;i<N;i++){
		if(A[i]==0)continue;
		if(A[i]==1){
			if(A[p]==-1){
				chmin(ans,pre[p]+suf[i]);
			}
			else{
				chmin(ans,pre[p]+1+suf[i]);
			}
		}
		p=i;
	}
	cout<<ans<<endl;
	return 0;
}