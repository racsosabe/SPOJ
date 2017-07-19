#include<stdio.h>
#include<math.h>

// 0.00s AC

int n;
int v[105];
int h[105];
 
int abs(int x){ return x<0?-x:x;}
 
int max(int a, int b){ return a<b?b:a;}
 
int height(int pos){
	if(pos > n) return 0;
	if(v[pos]==-1) return h[pos] = 0;
	if(h[pos]!=-1) return h[pos];	
	int ans = 1 + max(height(2*pos),height(2*pos+1));
	return h[pos] = ans;
}
 
int balance(int pos){
	if(pos > n || v[pos]==-1) return 1;
	int l = height(pos<<1);
	int r = height(2*pos+1);
	if(abs(l-r)<=1 && balance(pos<<1) && balance(2*pos+1)) return 1;
	return 0;
}
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){	
		scanf("%d",&n);
		for(int i=1; i<=n; i++) h[i] = -1;
		for(int i=1; i<=n; i++) scanf("%d",v+i);
		if(n<=2) puts("T");
		else{
			int h = height(1);
			if(balance(1)){
				puts("T");
			}
			else puts("F");
		}
	}
	return 0;
} 