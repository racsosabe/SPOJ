#include<bits/stdc++.h>
using namespace::std;

int n,start;
int v[1002];
int memo[1002][1002];
int parent[1002][1002];
int p2;

int dp(int i, int j, int p){
	if(i==j){
		if(p == 2){
			return 0;
		}
		else{
			return v[i];
		}
	}
	if(memo[i][j]!=-1) return memo[i][j];
	int ans = 0;
	if(p==2){
		if(v[i]>v[j]){
			ans = dp(i+1,j,1);
			parent[i][j] = (i+1)*n+j;
		}
		else if (v[i]<v[j]){
			ans = dp(i,j-1,1);
			parent[i][j] = i*n+j-1;
		}
		else{
			ans = dp(i+1,j,1);
			parent[i][j] = (i+1)*n+j;
		}
	}
	else{
		if(v[i]+dp(i+1,j,2) > v[j]+dp(i,j-1,2)){
			ans = v[i]+dp(i+1,j,2);
			parent[i][j] = (i+1)*n+j;
		}
		else{
			ans = v[j]+dp(i,j-1,2);
			parent[i][j] = i*n+j-1;
		}
	}
	return memo[i][j] = ans;
}

int main(){
	int t=1;
	while(scanf("%d",&n)!=EOF && n!=0){
		memset(memo,-1,sizeof memo);
		for(int i=0; i<n; i++){
			cin >> v[i];
		}
		p2 = 0;
		int P = dp(0,n-1,1);
		int startx = 0, starty = n-1;
		bool p1= true;
		while(startx!=starty){
			if(p1){
				int carry = parent[startx][starty];
				startx = carry/n;
				starty = carry%n;
			}
			else{
				p2 += max(v[startx],v[starty]);
				int carry = parent[startx][starty];
				startx = carry/n;
				starty = carry%n;
			}
			p1 = !p1;
		}
		if(!p1) p2 += max(v[startx],v[starty]);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",t++,P-p2);
	}
	return 0;
}