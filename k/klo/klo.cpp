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

int N,K;
int A[111111];

/*
lo.size()<=hi.size();
*lo.rbegin()<=*hi.begin();
*/
struct Median{
	multiset<int>lo,hi;
	int sumlo,sumhi;


	Median():sumlo(0),sumhi(0){}

	void adjust(){
		while(lo.size()>hi.size()){
			int tmp=*lo.rbegin();
			lo.erase(lo.find(tmp));
			sumlo-=tmp;
			hi.insert(tmp);
			sumhi+=tmp;
		}

		while(hi.size()>lo.size()+1){
			int tmp=*hi.begin();
			hi.erase(hi.find(tmp));
			sumhi-=tmp;
			lo.insert(tmp);
			sumlo+=tmp;
		}
	}

	void add(int x){
		if(hi.size()==0||*hi.begin()<=x){
			hi.insert(x);
			sumhi+=x;
		}
		else{
			lo.insert(x);
			sumlo+=x;
		}
		adjust();
	}
	void del(int x){
		if(*hi.begin()<=x){
			hi.erase(hi.find(x));
			sumhi-=x;
		}
		else{
			lo.erase(lo.find(x));
			sumlo-=x;
		}
		adjust();
	}

	int getMedian(){
		return *hi.begin();
	}
	int calcDistSum(){
		int m=getMedian();
		return (sumhi-m*(int)hi.size())+(m*(int)lo.size()-sumlo);
	}
};
const int INF=1001001001001001001;
signed main(){
	scanf("%lld%lld",&N,&K);
	rep(i,N)scanf("%lld",&A[i]);


	Median med;
	tuple<int,int,int>ans(INF,-1,-1);
	rep(i,K-1)med.add(A[i]);
	for(int i=K-1;i<N;i++){
		med.add(A[i]);
		int to=med.getMedian();
		int cost=med.calcDistSum();
		chmin(ans,make_tuple(cost,to,i-(K-1)));
		med.del(A[i-(K-1)]);
	}

	int cost,to,pos;
	tie(cost,to,pos)=ans;
	rep(i,K)A[pos+i]=to;
	printf("%lld\n",cost);
	rep(i,N)printf("%lld\n",A[i]);
	return 0;
}