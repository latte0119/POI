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

void read_uint(int *x){
  char c=0;
  while(c<'0') c = getchar();
 
  *x = c-'0';
  c = getchar();
 
  while(c>='0') {
    *x *= 10;
    *x += c-'0';
    c = getchar();
  }
}

int N,M;
int req[1111111];
int A[1111111];
int num;
int cnt[1111111];
inline void add(int x){
	if(cnt[x]==req[x])num--;
	cnt[x]++;
	if(cnt[x]==req[x])num++;
}
inline void del(int x){
	if(cnt[x]==req[x])num--;
	cnt[x]--;
	if(cnt[x]==req[x])num++;
}

int L[1111111],C[1111111];
signed main(){
	read_uint(&N);
	read_uint(&M);
	rep(i,M)read_uint(&L[i]);
	rep(i,M)read_uint(&C[i]);
	rep(i,M){
		C[i]--;
		req[C[i]]=L[i];
	}
	rep(i,N){
		read_uint(&A[i]);
		A[i]--;
	}

	num=N-M;
	int len=0;
	rep(i,N)len+=req[i];

	rep(i,len-1){
		add(A[i]);
	}

	int ans=0;
	for(int i=len-1;i<N;i++){
		add(A[i]);
		if(num==N)ans++;
		del(A[i-(len-1)]);
	}
	cout<<ans<<endl;
	return 0;
}