/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>

using namespace std;

int LCS(string in, string in2 ) {
	int dp[100][100];

	int n = in.length();
	int m = in2.length();
	//leave space for empty " "
	//initialising the table
	for (int i = 0; i <= n; i++) dp[i][0] = 0;

	for (int i = 0; i <= m; ++i) dp[0][i] = 0;


	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
		{
			int q = 0;
			if (in[i - 1] == in2[j - 1]) {
				q = 1 + dp[i - 1][j - 1];
			}
			else {
				q = max(dp[i - 1][j], dp[i][j - 1]);
			}
			dp[i][j] = q;
		}
	}
	return dp[n][m];
}


int main() {
	string in, in2;
	cin >> in >> in2;

	cout << LCS(in, in2);

	return 0;
}