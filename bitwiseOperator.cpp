/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long c=0;
	//property of XOR here used as a sum without CARRY..
	while (n) {
		c += n % 2 ? 0 : 1;
		n /= 2;
	}
	c = pow(2, c);
	cout<<c;
	return 0;
}