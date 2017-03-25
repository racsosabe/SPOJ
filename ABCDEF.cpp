#include<bits/stdc++.h>
#define pb push_back
#define all(v) (v).begin(),(v).end()
using namespace::std;

// 1.54s AC

typedef long long ll;

vector<ll> a,b;
int n;
ll v[105];


int main(){
	scanf("%lld",&n);
	for(int i=0; i<n; i++){
		scanf("%lld",v+i);
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k =0; k<n; k++){
				a.pb(v[i]*v[j]+v[k]);
			}
		}
	}
	for(int i=0; i<n; i++){
		if(v[i])
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				//cout << v[i] << " " << v[j] << " " << v[k] << endl;
				b.pb(v[i]*(v[j]+v[k]));
			}
		}
	}
	sort(all(a));
	sort(all(b));
	ll len = a.size();
	ll lim = b.size();
	ll count = 0LL;
	for(int i=0; i<len;){
		ll x = a[i];
		ll lo = i, hi = len;
		while(lo<hi){
			ll mi = lo + (hi-lo)/2;
			if(a[mi]<=x) lo = mi+1;
			else hi = mi;
		}
		ll times = lo-1;
		lo = 0, hi = lim;
		while(lo<hi){
			ll mi = lo + (hi-lo)/2;
			if(b[mi]<x) lo = mi+1;
			else hi = mi;
		}
		ll lower = lo;
		if(b[lower]!=x){
			i = times+1;
			continue;
		}
		lo = 0;
		hi = lim;
		while(lo<hi){
			ll mi = lo + (hi-lo)/2;
			if(b[mi]<=x) lo = mi+1;
			else hi = mi;
		}
		ll upper = lo-1;
		count+= (upper-lower+1)*(times-i+1);
		i = times+1;
	}
	cout << count << endl;
	return 0;
}