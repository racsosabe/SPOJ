#include<bits/stdc++.h>
using namespace::std;

// 0.54s AC

const int N = 30000 + 5;

struct nodo{
	int abren;
	int cierran;
};

int n, m;
string v;
nodo st[4*N], NIL;

nodo merge(nodo a, nodo b){
	nodo q;
	q.cierran = a.cierran;
	q.abren = b.abren;
	if(a.abren < b.cierran){
		q.cierran += b.cierran - a.abren;
	}
	else{
		q.abren += a.abren - b.cierran;
	}
	return q;
}

void build(int pos = 1, int l = 0, int r = n-1){
	if(l == r){
		st[pos].abren = v[l]=='(';
		st[pos].cierran = v[l]==')';
		return;
	}
	int mi = (l+r)/2;
	build(2*pos,l,mi);
	build(2*pos+1,mi+1,r);
	st[pos] = merge(st[2*pos],st[2*pos+1]);
}

void update(int x, int pos=1, int l=0, int r=n-1){
	if(l == r){
		int a = st[pos].abren;
		st[pos].abren = 1-a;
		st[pos].cierran = a;
		return;
	}
	int mi = (l+r)/2;
	if(l <= x && x <= mi) update(x,2*pos,l,mi);
	else update(x,2*pos+1,mi+1,r);
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

bool query(int x, int y){
	nodo ans = queryn(x,y);
	return ans.abren==0 && ans.cierran == 0;
}

int main(){
	NIL.abren = 0;
	NIL.cierran = 0;
	int x;
	for(int t=1; t<=10; t++){
		printf("Test %d:\n",t);
		scanf("%d",&n);
		cin >> v;
		build();
		scanf("%d",&m);
		while(m--){
			scanf("%d",&x);
			if(x == 0){
				if(query(0,n-1)) puts("YES");
				else puts("NO");
			}
			else{
				update(x-1);	
			}
		}
	}
	return 0;
}