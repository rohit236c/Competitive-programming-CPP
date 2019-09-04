#include<bits/stdc++.h>

using namespace std;

int powerSum(int X,int P,int N=1) {

	int i_pow = pow(N,P);

	//base case
    if (i_pow > X)
        return 0;

    else if (i_pow == X)
        return 1;

      // subproblem
    return powerSum(X,P,N+1) + powerSum(X-i_pow,P,N+1);

}

int main() {
	int n, power;
	cin >> n >> power;
	int count = 0;

	cout<<powerSum(n,power,1);

	return 0;
}