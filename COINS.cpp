#include<bits/stdc++.h>
using namespace::std;

// 0.00s AC

long long n;
map<int,bool> vis;
map<int,long long> memo;

long long dp(long long q){
	if(q == 0) return 0;
	if(vis[q]) return memo[q];
	long long ans = max(q,dp(q/2)+dp(q/3)+dp(q/4));
	vis[q] = true;
	return memo[q] = ans;
}

int main(){
	while(scanf("%lld",&n)!=EOF){
		vis.clear();
		printf("%lld\n",dp(n));
	}
	return 0;
}