#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ri(x) scanf("%d",&(x))
#define ri2(x,y) scanf("%d %d",&(x),&(y))
#define ri3(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define rll(x) scanf("%lld",&(x))
#define rll2(x,y) scanf("%lld %lld",&(x),&(y))
#define rll3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z))
using namespace::std;

const int MOD = 1000000000 + 7;
const long double PI = acos(-1);

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<tll> vtll;
typedef vector<string> vs;

// 0.14s AC

const int N = 100000 +5;

int n,m,k;
vi G[N];
bool found[N];
bool wait[N];
int keys[N];
bool reachable[N];
bool door[N];

void BFS(int source){
	reachable[source] = true;
	queue<int> Q;
	Q.push(source);
	while(!Q.empty() && !reachable[n]){
		int u = Q.front();
		Q.pop();
		for(int i=0; i<G[u].size(); i++){
			int v = G[u][i];
			if(reachable[v]) continue;
			if(keys[v]!=0){
				int llave = keys[v];
				found[llave] = true;
				Q.push(v);
				if(wait[llave]){
					Q.push(llave);
					wait[llave] = false;
				}
			}
			else if(door[v]){
				if(found[v] || v==n){
					Q.push(v);
				}
				else{
					wait[v] = true;
				}
			}
			else{
				reachable[v] = true;
				Q.push(v);
			}
		}
		reachable[u] = true;
	}
}

int main(){
	int a, b;
	while(ri3(n,k,m) && n!=-1){
		for(int i=1; i<=n; i++) G[i].clear();
		memset(wait,0,sizeof wait);
		memset(found,0,sizeof found);
		memset(reachable,0,sizeof reachable);
		memset(keys,0,sizeof keys);
		memset(door,0,sizeof door);
		while(k--){
			ri2(a,b);
			keys[a] = b;
			door[b] = true;
		}
		while(m--){
			ri2(a,b);
			G[a].pb(b);
			G[b].pb(a);
		}
		BFS(1);
		bool can = reachable[n];
		if(can) puts("Y");
		else puts("N");
	}
	return 0;
}