#include<bits/stdc++.h>
using namespace::std;

// 0.05s AC

const int N = 100000+5;

struct nodo{
	long long max1;
	long long max2;
};

int n, q;
nodo st[4*N];
nodo NIL;
long long v[N];

nodo merge(nodo a, nodo b){
	nodo q;
	q.max1 = max(a.max1,b.max1);
	if(a.max1 > b.max1){
		q.max2 = max(a.max2,b.max1);
	}
	else{
		q.max2 = max(b.max2,a.max1);	
	}
	return q;
}

void build(int pos=1, int l=0, int r=n-1){
	if(l == r){
		st[pos].max1 = v[l];
		st[pos].max2 = -1;
		return;
	}
	int mi = (l+r)/2;
	build(2*pos,l,mi);
	build(2*pos+1,mi+1,r);
	st[pos] = merge(st[2*pos],st[2*pos+1]);
}

void update(int x,long long val, int pos=1, int l=0, int r=n-1){
	if(l == r){
		st[pos].max1 = val;
		return;
	}
	int mi = (l+r)/2;
	if(l <=x && x<= mi) update(x,val,2*pos,l,mi);
	else update(x,val,2*pos+1,mi+1,r);
	st[pos] = merge(st[2*pos],st[2*pos+1]);
}

nodo queryn(int x, int y, int pos=1, int l=0, int r=n-1){
	if(y < l || r < x) return NIL;
	if(x <=l && r <= y) return st[pos];
	int mi = (l+r)/2;
	nodo L = queryn(x,y,2*pos,l,mi);
	nodo R = queryn(x,y,2*pos+1,mi+1,r);
	return merge(L,R);
}

long long query(int x, int y){
	nodo ans = queryn(x,y);
	return ans.max1+ans.max2;
}

int main(){
	char op;
	int x, y;
	long long val;
	NIL.max1 = -1;
	NIL.max2 = -1;
	scanf("%d",&n);
	for(int i=0; i<n; i++) scanf("%lld\n",v+i);	
	build();
	scanf("%d\n",&q);
	while(q--){
		scanf("%c",&op);
		if(op == 'U'){
			scanf("%d %lld\n",&x,&val);
			update(x-1,val);
		}
		else{
			scanf("%d %d\n",&x,&y);
			printf("%lld\n",query(x-1,y-1));
		}
	}
	return 0;
}