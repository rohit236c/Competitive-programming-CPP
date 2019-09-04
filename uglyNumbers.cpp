#include<bits/stdc++.h>
using namespace std;

int uglyNumbers(int n) {

	if (n == 1 || n == 2 || n == 3  || n == 5)
		return n;

	if(n % 2 == 0)
		return 2 + uglyNumbers(n/2);

	if(n % 3 == 0)
		return 3 + uglyNumbers(n/3);

	if(n % 5 == 0)
		return 5 + uglyNumbers(n/5);

	else
		return 0;
}

int main() {
	int n;
	cin >> n;

	cout<<uglyNumbers(n);

	return 0;
}
