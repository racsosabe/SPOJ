#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define ri(x) scanf("%d",&(x))
#define ri2(x,y) scanf("%d %d",&(x),&(y))
#define ri3(x,y,z) scanf("%d %d %d",&(x),&(y),&(z))
#define rll(x) scanf("%lld",&(x))
#define rll2(x,y) scanf("%lld %lld",&(x),&(y))
#define rll3(x,y,z) scanf("%lld %lld %lld",&(x),&(y),&(z))
#define rc(x) scanf("%c",&(x))
#define pq priority_queue
using namespace::std;
 
const long double PI = acos(-1);
const int MOD = 1000000007;
 
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> tll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<string> vs;
 
ll gcd(ll a, ll b){ return b==0?a:gcd(b,a%b);}
 
int add(int a, int b){ return (a%MOD + b%MOD)%MOD;}
 
int mul(ll a, ll b){ return ((a%MOD)*(b%MOD))%MOD;}
 
 
 
/****************************************
*************P*L*A*N*T*I*L*L*A************
*****************************************/

// 0.00s AC

int n, x, y;
 
int root(int a){
	int lo = 0 , hi = 1370;
	while(lo < hi){
		int mi = lo + (hi-lo+1)/2;
		if(mi*mi <= a) lo = mi;
		else hi = mi-1;
	}
	return lo;
}
 
int main(){
	int t;
	ri(t);
	while(t--){
		ri3(n,x,y);
		if(n > 2){
			puts("impossible");
		}
		else if(n == 2){
			int carry = x*x + y*y;
			int r = root(carry);
			//cout << carry << " " << r << endl;
			if(r*r!=carry) puts("impossible");
			else printf("%d\n",r);
		}
		else{
			printf("%d\n",x+y);
		}
	}
	return 0;
}