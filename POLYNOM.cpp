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

// 0.02s AC

const int N = 1005;
 
int n;
int v[N];
int anum,aden,bnum,bden,cnum,cden,dnum, dden;
bool can;
 
int main(){
	int t;
	ri(t);
	while(t--){
		ri(n);
		for(int i=1; i<=n; i++) ri(v[i]);
		if(n <= 3) puts("YES");
		else{
			anum = -v[1] + 3*v[2] - 3*v[3] + v[4];
			aden = 6;
			bnum = 9*v[1] -24*v[2] + 21*v[3] - 6*v[4];
			bden = 6;
			cnum = -26*v[1] + 57*v[2] - 42*v[3] + 11*v[4];
			cden = 6;
			dnum = 24*v[1] - 36*v[2] + 24*v[3] - 6*v[4];
			dden = 6;
			can = true;
			for(int i=5; i<=n && can; i++){
				if(abs(anum*i*i*i + bnum*i*i + cnum*i + dnum)%6!=0){
					can = false;
					continue;
				}
				if((anum*i*i*i + bnum*i*i + cnum*i + dnum)/6!=v[i]){
					can = false;
					continue;
				}
			}
			if(can) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}