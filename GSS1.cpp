#include<bits/stdc++.h>
#define ri(x) scanf("%d",&(x))
#define rll(x) scanf("%lld",&(x))
using namespace::std;

// 0.21s AC

const int N = 500005;

typedef long long ll;

struct nodo{
	int preffix_sum;
	int suffix_sum;
	int ans;
	int total;
};

int n;
int v[N];
nodo st[4*N];
nodo NIL;

nodo merge(nodo a, nodo b){
	nodo q;
	q.ans = max(a.ans,b.ans);
	q.ans = max(q.ans,a.suffix_sum+b.preffix_sum);
	q.preffix_sum = max(a.preffix_sum,a.total+b.preffix_sum);
	q.suffix_sum = max(b.suffix_sum,b.total+a.suffix_sum);
	q.total = a.total+b.total;
	return q;
}

void build(int pos=1, int left=0, int right=n-1){
	if(left == right){
		st[pos].preffix_sum = v[left];
		st[pos].suffix_sum = v[left];
		st[pos].ans = v[left];
		st[pos].total = v[left];
		return;
	}
	int mi = (left+right)/2;
	build(pos<<1,left,mi);
	build((pos<<1) + 1, mi+1,right);
	st[pos] = merge(st[pos<<1],st[(pos<<1)+1]);
}

nodo query2(int x, int y, int pos=1, int left=0, int right=n-1){
	if(y < left || x > right) return NIL;
	if(x <= left && right<= y ) return st[pos];
	int mi = (left+right)/2;
	nodo L = query2(x,y,pos<<1,left,mi);
	nodo R = query2(x,y,(pos<<1)+1,mi+1,right);
	return merge(L,R);
}

int query(int x, int y, int pos=1, int left=0, int right=n-1){
	nodo q = query2(x,y);
	return q.ans;
}

void update(int x, int z, int pos=1, int left = 0, int right = n-1){
	if(x < left || right < x) return;
	if(x <= left && right <= x){
		st[pos].ans += z;
		st[pos].total+=z;
		st[pos].preffix_sum+=z;
		st[pos].suffix_sum+=z;
		return;
	}
	int mi = (left+right)/2;
	update(x,z,pos<<1,left,mi);
	update(x,z,(pos<<1)+1,mi+1,right);
	st[pos] = merge(st[pos<<1],st[(pos<<1)+1]);
}

int main(){
	NIL.ans = -(1<<30);
	NIL.suffix_sum = -(1<<30);
	NIL.preffix_sum = -(1<<30);
	NIL.total = 0;
	int q,l,r,x,pos;
	int op;
	ri(n);
	for(int i=0; i<n; i++) ri(v[i]);
	build();
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&l,&r);
		l--;r--;
		printf("%d\n",query(l,r));
	}
	return 0;
}
