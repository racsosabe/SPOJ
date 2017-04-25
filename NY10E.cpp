#include<bits/stdc++.h>
using namespace::std;

// 0.00s AC

int n;
long long memo[65][11];

long long dp(int pos, int digit){
	if(pos == n-1){
		return 1LL;
	}
	if(memo[pos][digit]!=-1) return memo[pos][digit];
	long long ans = 0LL;
	for(int i=digit; i<10; i++) ans+= dp(pos+1,i);
	return memo[pos][digit] = ans;
}

int main(){
	int t,c;
	scanf("%d",&t);
	while(t--){
		memset(memo,-1,sizeof memo);
		scanf("%d %d",&c,&n);
		long long ans = 0;
		for(int i=0; i<10; i++) ans+=dp(0,i);
		printf("%d %lld\n",c,ans);
	}
	return 0;
}