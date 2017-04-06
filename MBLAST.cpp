#include<bits/stdc++.h>
using namespace::std;

string x, y;
int d,n,m;

int memo[2001][2001];

int dp(int i, int j){
	if(i>=n && j<m) return (m-j)*d;
	if(j>=m && i<n) return (n-i)*d;
	if(i>=n && j>=m) return 0;
	if(memo[i][j]!=-1) return memo[i][j];
	int ans = min(d+dp(i,j+1),min(d+dp(i+1,j),abs(x[i]-y[j])+dp(i+1,j+1)));
	return memo[i][j] = ans;
}

int main(){
	memset(memo,-1,sizeof memo);
	cin >> x >> y >> d;
	n = x.size();
	m = y.size();
	cout << dp(0,0) << endl;
	return 0;
}