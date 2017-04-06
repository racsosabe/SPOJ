#include<bits/stdc++.h>
using namespace::std;

int h,a;
int memo[2001][2001][3];

int dp(int h, int a, int p){
	if(h<=0 || a<=0) return -1;
	if(memo[h][a][p] !=-1) return memo[h][a][p];
	int ans = INT_MIN;
	if(p!=0)
	ans = max(ans,1+dp(h+3,a+2,0));
	if(p!=1)
	ans = max(ans,1+dp(h-5,a-10,1));
	if(p!=2)
	ans = max(ans,1+dp(h-20,a+5,2));
	return memo[h][a][p] = ans;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		memset(memo,-1,sizeof memo);
		cin >> h >> a;
		int ans = INT_MIN;
		for(int i=0; i<3; i++) ans = max(ans,dp(h,a,i));
		cout << ans << endl;
	}
	return 0;
}