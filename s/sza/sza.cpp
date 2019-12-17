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

char ukunichiachang[1111111];
string strin(){
	scanf("%s",ukunichiachang);
	return ukunichiachang;
}

template<class T>
vector<int>zalgorithm(T s){
    vector<int>a(s.size());
    a[0]=s.size();
    int i=1,j=0;
    while(i<s.size()){
        while(i+j<s.size()&&s[j]==s[i+j])j++;
        a[i]=j;
        if(j==0){i++;continue;}
        int k=1;
        while(i+k<s.size()&&k+a[k]<j)a[i+k]=a[k],k++;
        i+=k;j-=k;
    }
    return a;
}
int nex[555555],pre[555555];
vint bucket[555555];

signed main(){
	string S=strin();
	auto z=zalgorithm(S);
	int N=S.size();
	rep(i,N){
		nex[i]=i+1;
		pre[i+1]=i;
	}

	for(int i=1;i<N;i++){
		bucket[z[i]].pb(i);
	}

	int ma=1;
	for(int i=1;i<=N;i++){
		for(auto x:bucket[i-1]){
			int l=pre[x];
			int r=nex[x];
			nex[l]=r;
			pre[r]=l;
			chmax(ma,r-l);
		}
		if(ma<=i){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}