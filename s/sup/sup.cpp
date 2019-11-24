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


int cross(pint p1,pint p2){
	return p1.fi*p2.se-p1.se*p2.fi;
}

signed main(){
	int N,Q;
	scanf("%lld%lld",&N,&Q);
	vint qs(Q);
	rep(i,Q)scanf("%lld",&qs[i]);

	vint h(N);
	h[0]=1;
	for(int i=1;i<N;i++){
		int p;scanf("%lld",&p);
		p--;
		h[i]=h[p]+1;
	}

	int H=*max_element(all(h));
	vint s(H+1);
	rep(i,N)s[h[i]]++;
	for(int i=0;i<H;i++)s[i+1]+=s[i];

	stack<int>stk;
	stk.push(H);

	vint lim(H);
	for(int i=H-1;i>=0;i--){
		if(s[stk.top()]<=s[i])continue;

		while(stk.size()>1){
			int k=stk.top();
			stk.pop();

			pint v1(k-i,s[k]-s[i]);
			pint v2(stk.top()-i,s[stk.top()]-s[i]);
			if(cross(v1,v2)<=0)continue;
			stk.push(k);
			break;
		}

		int j=stk.top();
		lim[i]=(s[j]-s[i]+j-i-1)/(j-i)-1;
		stk.push(i);
	}

	vint mi(N,H);
	rep(i,H)chmin(mi[lim[i]],i);
	for(int i=N-1;i>0;i--)chmin(mi[i-1],mi[i]);

	vint ans(N);
	for(int i=1;i<N;i++){
		ans[i]=mi[i]+(s[H]-s[mi[i]]+i-1)/i;
	}

	rep(i,Q){
		if(i)printf(" ");
		if(qs[i]>=N)printf("%lld",H);
		else printf("%lld",ans[qs[i]]);
	}
	puts("");
	return 0;
}