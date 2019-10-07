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
	int N, M, Q;
	cin >> N >> M >> Q;

	int row[1000000];
	int col[1000000];
	MEM(row,0);
	MEM(col,0);


	for (int i = 0; i < Q; ++i){
		for (int j = 0; j < 2; ++j) {
            int temp;
            cin>>temp;
			if(j == 0) {
				row[temp]++;
			}
			else {
				col[temp]++;
			}
		}
	}
	int cnt = 0;
	int cntRow = 0;
	int cntCol = 0;
	for (int i = 1; i <= N; ++i)
	{
		if(row[i]&1){
			cntRow++;
		}
	}
	for (int i = 1; i <= M; ++i)
	{
		if(col[i]&1){
			cntCol++;
		}
	}
	int eleRow = M*cntRow;
	int eleCol = N*cntCol;
	int commEle = cntRow*cntCol;
	cnt = eleRow + eleCol - 2*commEle;

	cout<<cnt;
}

int main() {
	int t ;
	cin >> t ;
	while (t--) {

		util();
		cout<<endl;
	}

	return 0;
}