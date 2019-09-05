#include<bits/stdc++.h>
using namespace std;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
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

int dp[101][101];

int minSteps(string input, string output) {

	int inLength = input.length();
	int outLength = output.length();

	//fill the empty " "
	dp[0][0] = 0;
	FOR(i, 1, outLength + 1, 1) dp[0][i] = dp[0][i - 1] + 1; // insertion

	FOR(i, 1, inLength + 1, 1) dp[i][0] = dp[i - 1][0] + 1; //deletion

	FOR(i, 1, inLength + 1, 1) {
		FOR(j, 1, outLength + 1, 1) {

			int q1 = dp[i-1][j-1]; //replace
			int q2 = dp[i-1][j];  //delete
			int q3 = dp[i][j-1];

			dp[i][j] = min(q1,min(q2,q3)) + (input[i] != output[j]);
		}
	}

	return dp[inLength][outLength];
}


int main() {
	string s;
	string s_two;
	cin >> s;
	cin >> s_two;
	cout<<minSteps(s,s_two);
	return 0;
}