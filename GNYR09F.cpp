#include<bits/stdc++.h>
using namespace::std;

// 0.00s AC

int n,k;
int memo[105][3][105];

int dp(int pos, int last, int sum){
	if(pos == n){
		if(sum == 0) return 1;
		return 0;
	}	
	if(memo[pos][last][sum]!=-1) return memo[pos][last][sum];
	int ans = 0;
	if(last == 0){
		ans += dp(pos+1,0,sum);
		ans += dp(pos+1,1,sum);
	}
	else{
		ans += dp(pos+1,0,sum);
		if(sum>=1)
		ans += dp(pos+1,1,sum-1);
	}
	return memo[pos][last][sum] = ans;
}

int main(){
	int t;
	int c;
	scanf("%d",&t);
	while(t--){
		memset(memo,-1,sizeof memo);
		scanf("%d %d %d",&c,&n,&k);
		cout << c << " " << dp(1,0,k) + dp(1,1,k) << endl;
	}
	return 0;
}