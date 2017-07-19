#include<iostream>

// 114p AC without this comment

int main(){
	int t, x, S=0;
	std::cin >> t;
	while(t--){ std::cin >> x; S += x>0?x:0;}
	std::cout << S << "\n";
	return 0;
}