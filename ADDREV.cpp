#include<bits/stdc++.h>
using namespace::std;

// 0.00s AC

int n, m;
 
int reverse(int x){
	int p = 1;
	int carry = x;
	while(carry){
		p*=10;
		carry /= 10;
	}
	int v = 0;
	p /= 10;
	while(x){
		v += (x%10)*p;
		p /= 10;
		x /= 10;
	}
	return v;
}
 
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		printf("%d\n",reverse(reverse(n)+reverse(m)));
	}
	return 0;
} 