#include<bits/stdc++.h>
using namespace std;

// #define int long long

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

int N,K;
int A[1111111];

int rnk[1111111];
int pre[1111111];
vint calc(vint &X){
	memset(rnk,-1,sizeof(rnk));
	memset(pre,-1,sizeof(pre));
	rep(i,X.size())rnk[X[i]]=i;

	vint dp(N);
	rep(i,N){
		if(rnk[A[i]]==-1)continue;
		if(rnk[A[i]]==0){
			dp[i]=i;
		}
		else{
			int c=X[rnk[A[i]]-1];
			if(pre[c]==-1)continue;
			dp[i]=dp[pre[c]];
		}
		pre[A[i]]=i;
	}
	return dp;
}

int cor[1111111];
int prefixMax[1111111];
signed main(){
	scanf("%d%d",&N,&K);
	rep(i,N)scanf("%d",&A[i]);

	int sizeX,sizeY;
	scanf("%d%d",&sizeX,&sizeY);
	vector<int>X(sizeX),Y(sizeY);
	rep(i,sizeX)scanf("%d",&X[i]);
	rep(i,sizeY)scanf("%d",&Y[i]);

	vint dpX=calc(X);
	reverse(A,A+N);
	vint dpY=calc(Y);
	reverse(all(dpY));
	reverse(A,A+N);

	memset(pre,-1,sizeof(pre));
	for(int i=N-1;i>=0;i--){
		if(pre[A[i]]==-1)pre[A[i]]=i;
		cor[i]=pre[A[i]];
	}

	for(int i=0;i<N;i++)prefixMax[i+1]=max(prefixMax[i],cor[i]);

	vint ans;
	rep(i,N){
		if(dpX[i]==0||dpY[i]==0)continue;
		if(A[i]!=X.back())continue;
		int tmp=prefixMax[dpX[i]];
		if(N-tmp<=dpY[i])ans.pb(i);
	}
	printf("%d\n",(int)ans.size());

	if(ans.size()){
		rep(i,ans.size()){
			if(i)printf(" ");
			printf("%d",ans[i]+1);
		}
		puts("");
	}
	return 0;
}