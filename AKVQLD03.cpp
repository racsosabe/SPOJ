#include<bits/stdc++.h>
using namespace::std;

// 0.19s AC

const int N = 1000000+5;

struct nodo{
	long long cnt;
};

int n, q;
nodo st[4*N];
nodo NIL;

nodo merge(nodo a, nodo b){
	nodo q;
	q.cnt = a.cnt+b.cnt;
	return q;
}

void build(int pos=1, int l=0, int r=n-1){
	if(l == r){
		st[pos].cnt = 0;
		return;
	}
	int mi = (l+r)/2;
	build(2*pos,l,mi);
	build(2*pos+1,mi+1,r);
	st[pos] = merge(st[2*pos],st[2*pos+1]);
}

void update(int x, int dif, int pos=1, int l=0, int r=n-1){
	if(l == r){
		st[pos].cnt += dif;
		return;
	}
	int mi = (l+r)/2;
	if(l <= x && x <= mi) update(x,dif,2*pos,l,mi);
	else update(x,dif,2*pos+1,mi+1,r);
	st[pos] = merge(st[2*pos],st[2*pos+1]);
}

nodo queryn(int x, int y, int pos=1, int l=0, int r=n-1){
	if(y < l || r < x) return NIL;
	if(x <= l && r <= y) return st[pos];
	int mi = (l+r)/2;
	nodo L = queryn(x,y,2*pos,l,mi);
	nodo R = queryn(x,y,2*pos+1,mi+1,r);
	return merge(L,R);
}

long long query(int x, int y){
	nodo ans = queryn(x,y);
	return ans.cnt;
}

int main(){
	string s;
	int a, b;
	NIL.cnt = 0LL;
	scanf("%d %d",&n,&q);
	build();
	while(q--){
		cin >> s;
		scanf("%d %d",&a,&b);
		if(s == "add"){
			update(a-1,b);
		}
		else printf("%lld\n",query(a-1,b-1));
	}
	return 0;
}