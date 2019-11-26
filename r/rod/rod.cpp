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


mt19937 mt(119);
uniform_int_distribution<int>uku;
inline int rnd(){
	return uku(mt);	
}

struct Node{
	int val;
	Node *lch,*rch;
	int pri;
	int cnt;

	Node(int v):val(v),lch(nullptr),rch(nullptr),pri(rnd()),cnt(1){}
	Node(){}
};

inline int cnt(Node *t){
	if(t==nullptr)return 0;
	return t->cnt;
}

Node* update(Node *t){
	if(t!=nullptr){
		t->cnt=cnt(t->lch)+1+cnt(t->rch);
	}
	return t;
}

const int POOL=1001001;
Node pool[POOL];
int tail=0;
Node* alloc(int val){
	pool[tail]=Node(val);
	return &pool[tail++];
}

Node* merge(Node *l,Node *r){
	if(l==nullptr)return r;
	if(r==nullptr)return l;

	if(l->pri>r->pri){
		l->rch=merge(l->rch,r);
		return update(l);
	}
	else{
		r->lch=merge(l,r->lch);
		return update(r);
	}
}

pair<Node*,Node*>split(Node *t,int k){
	if(t==nullptr)return pair<Node*,Node*>(nullptr,nullptr);

	if(t->val<k){
		auto p=split(t->rch,k);
		t->rch=p.first;
		return pair<Node*,Node*>(update(t),p.second);
	}
	else{
		auto p=split(t->lch,k);
		t->lch=p.second;
		return pair<Node*,Node*>(p.first,update(t));
	}
}

Node *uni(Node *t1,Node *t2,int &in){
	if(t1==nullptr)return t2;
	if(t2==nullptr)return t1;


	int swp=0;
	if(t1->pri<t2->pri){
		swap(t1,t2);
		swp=1;
	}

	auto uku=split(t2,t1->val);
	pair<Node*,Node*>latte(t1->lch,t1->rch);

	if(swp)swap(uku,latte);
	t1->lch=t1->rch=nullptr;
	t1=update(t1);

	in+=(cnt(latte.second)+(1-swp))*(cnt(uku.first)+swp);
	return merge(uni(latte.first,uku.first,in),merge(t1,uni(latte.second,uku.second,in)));
}


int ans=0;
Node* solve(int &ans){
	int p;scanf("%lld",&p);
	if(p==0){
		Node *l=solve(ans);
		Node *r=solve(ans);

		int in=0;
		int pr=cnt(l)*cnt(r);
		l=uni(l,r,in);
		chmin(in,pr-in);
		ans+=in;
		return l;
	}
	else{
		return alloc(p);
	}
}

void dmp(Node *t){
	if(!t)return;
	dmp(t->lch);
	cout<<t->val<<endl;
	dmp(t->rch);
}

signed main(){
	int n;scanf("%lld",&n);
	
	int ans=0;
	solve(ans);
	cout<<ans<<endl;
	
	return 0;
}