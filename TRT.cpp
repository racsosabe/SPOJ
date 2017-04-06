#include<bits/stdc++.h>
using namespace::std;

int n;
int v[2001];
int memo[2001][2001];

int dp(int i, int j){
	int day = n-1-j+i+1;
	if(i==j) return memo[i][j] = v[i]*day;
	if(memo[i][j]!=-1) return memo[i][j];
	int ans = max(v[i]*day + dp(i+1,j),v[j]*day + dp(i,j-1));
	return memo[i][j] = ans;
}

int main(){
	memset(memo,-1,sizeof memo);
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> v[i];
	}
	cout << dp(0,n-1) << endl;
	return 0;
}