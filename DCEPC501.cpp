#include<bits/stdc++.h>
using namespace::std;

// 0.30s AC

int n;
long long v[100002];
long long memo[100002][4];

long long dp(int pos, int q){
	if(pos >= n){
		return 0;
	}
	if(memo[pos][q]!=-1) return memo[pos][q];
	long long ans = LLONG_MIN;
	for(int i=1; i<4; i++){
		if(pos+i<n){
			if(pos>0)
			ans = max(ans,v[pos+i-1]-v[pos-1]+dp(pos+2*i,i));
			else
			ans = max(ans,v[pos+i-1]+dp(pos+2*i,i));
		}
		else{
			if(pos>0)
			ans = max(ans,v[n-1]-v[pos-1]+dp(pos+2*i,i));
			else
			ans = max(ans,v[n-1]+dp(pos+2*i,i));		
		}
	}
	return memo[pos][q] = ans;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(memo,-1,sizeof memo);
		scanf("%d",&n);
		for(int i=0; i<n; i++){
			scanf("%lld",v+i);
			if(i>0) v[i] += v[i-1];
		}
		printf("%lld\n",dp(0,1));
	}
	return 0;
}