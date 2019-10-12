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

void util() {

	int64 N, K;
	cin >> N >> K;
	int64 * Arr = new int64[N];

	for (int i = 0; i < N; ++i)
	{
		cin >> Arr[i];
	}

	

	 if(K >= 3*N && (N & 1)) Arr[N/2] = 0;
        K = K % (3*N); 
	

	for (int i = 0; i < K; ++i)
	{
		int64 pos = i % N;
		int64 a = Arr[pos];
		int64 pos_2  = N - (i % N) - 1;
		int64 b = Arr[pos_2];
		int64 ans = a ^ b;
		Arr[pos] = ans;
	}


	for (int i = 0; i < N; ++i)
	{
		cout << Arr[i] << " ";
	}

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