/*
	@author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<=k ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define MOD 1000000007
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;

int memo[100];
int maxProfit(VI v, int length) {

	//base case
	if (length == 0)
		return 0;
	if (memo[length] != -1)
		return memo[length];

	int best = 0;
	FOR(i, 1, length, 1) {
		int max_profit_one = v[i] + maxProfit(v, length - i);
		best = max(best, max_profit_one);
	}

	memo[length] = best;
	return best;
}
//bottom-up

int maxProfitBottomUp(VI v, int length) {
	int dp[100] = {};

	FOR(len, 1, length, 1) {
		int best = 0;
		FOR(cut, 1, len, 1) {
			best = max(v[cut] + dp[len - cut], best);
		}
		dp[len] = best;
	}
	return dp[length];
}

int main() {
	int n;
	cin >> n;

	int input;
	VI v;
	v.PB(-1);
	for (int i = 1; i <= n; ++i)
	{
		cin >> input;
		v.PB(input);
	}
	MEM(memo, -1);

	// cout << maxProfit(v, n);
	cout<<maxProfitBottomUp(v,n);

	return 0;
}