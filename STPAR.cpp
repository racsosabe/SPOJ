#include<bits/stdc++.h>
using namespace::std;

// 0.00s AC

int n;

int main(){
	int x;
	while(scanf("%d",&n) && n!=0){	
		stack<int> S;
		int pos = 1;
		for(int i=0; i<n; i++){
			scanf("%d",&x);
			if(pos == x){
				pos++;
			}
			if(!S.empty() && pos == S.top()){
				while(!S.empty() && S.top()==pos){
					pos++;
					S.pop();
				}
			}
			if(pos <= x) S.push(x);
		}
		if(!S.empty() && pos == S.top()){
			while(!S.empty() && S.top()==pos){
				pos++;
				S.pop();
			}
		}
		if(S.size()==0) puts("yes");
		else puts("no");
	}
	return 0;
}