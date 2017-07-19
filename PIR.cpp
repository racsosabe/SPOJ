#include<bits/stdc++.h>
#define ri(x) scanf("%d",&(x))
using namespace::std;

// 0.00s AC

double U,V,W,u,v,w;
 
double area(){
	double x = (U-v+w)*(v-w+U);
	double y = (V-w+u)*(w-u+V);
	double z = (W-u+v)*(u-v+W);
	double X = (w-U+v)*(U+v+w);
	double Y = (u-V+w)*(V+w+u);
	double Z = (v-W+u)*(W+u+v);
	double a = sqrt(x*Y*Z);
	double b = sqrt(y*Z*X);
	double c = sqrt(z*X*Y);
	double d = sqrt(x*y*z);
	double B1 = b+c+d-a;
	double B2 = a+c+d-b;
	double B3 = a+b+d-c;
	double B4 = a+b+c-d;
	double den = 192*u*v*w;
	double S = sqrt(B1*B2*B3*B4);
	return S/den;
}
 
int main(){
	int t;
	ri(t);	
	while(t--){
		cin >> u >> v >> w >> W >> V >> U;
		cout << setprecision(4) << fixed << area() << endl;
	}	
	return 0;	
}