/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define FORM(i,j) for(int i=1; i<=j;i+=1)
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

int dp[100][100];
//Write CPP code here
int count( int S[], int m, int n )
{
	//we need a two dimensional matrix to store the result
	int table[m + 1][n + 1];

	// Initialize all table values as 0
	memset(table, 0, sizeof(table));

	// Base case (If given value is 0)
	for (int i = 0; i < m; i++)
		table[0][i] = 1;

	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (S[i - 1] > j)
				table[i][j] = table[i - 1][j];
			
			else
				table[i][j] = table[i - 1][j] + table[i][j - (i - 1)];
		}
	}
	return table[m][n];
}
int coinProblem(VI v, int n, int c) {
	// memset(table, 0, sizeof(table));
	MEM(dp, 0);
	// FOR(i,0,c,1){
	// 	FOR(j,0,n,1){
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	REP(i, c)
	dp[0][i] = 1;


	FORM(i, c) {
		FORM(j, n) {
			if (v[i - 1] > j)
			{
				dp[i][j] = dp[i - 1][j];

			}
			else {
				//calculating current box = excluding cur coin + including cur coin
				dp[i][j] = dp[i - 1][j] + dp[i][j - (i - 1)];
			}
		}
	}

	REP(i, c) {
		cout << i << " =  ";
		REP(j, n) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	return dp[c][n];
}

void util() {
	int numOfCoins;
	cin >> numOfCoins;

	int input;

	VI v;
	int arr[10];
	REP(i, numOfCoins) {
		cin >> arr[i];
		// v.PB(input);
	}
	int totalAmount;
	cin >> totalAmount;



	// cout << coinProblem(v, totalAmount, numOfCoins);
	cout<<count(arr,numOfCoins,totalAmount);
}


int main() {
	int t ;
	cin >> t ;
	while (t--) {
		util();
		cout << endl;
	}


	return 0;
}