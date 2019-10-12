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

void factorAndCount(int64 x, int64 index, multimap<int64, pair<int64, int64>>&map) {
	int i = 1;

	while (i * i <= x) {

		if (x % i == 0) {
			std::multimap<int64, pair<int64, int64>>::iterator it = map.find(i);
			if (it != map.end()) {

				if (it->second.first > index) {
					it->second.second++;
				}
				
			}
			if (x / i != i) {
				int64 n = x / i;
				std::multimap<int64, pair<int64, int64>>::iterator it2 = map.find(n);
				cout << " i n " << x << " " << it2->second.first << " " << it2->second.second << endl;
				if (it2 != map.end()) {
					// cout<<" i n "<<x<<" "<<it->second.first<<endl;
					if (it2->second.first > index) {
						it2->second.second++;
					}
				}
			}
		}
		i++;
	}
}

void util() {

	int64 N;
	cin >> N;
	int64 Arr[100000];
	multimap<int64, pair<int64, int64>>map;

	for (int i = 0; i < N ; i++) {
		cin >> Arr[i];
		pair<int64, int64>s(i, 0);
		std::multimap<int64, pair<int64, int64>>::iterator it2 = map.find(Arr[i]);
		if (it2 != map.end()) {
			map.erase(it2);
		}
		map.insert(pair<int64, pair<int64, int64>>(Arr[i], s));
	}
	for (int i = 0; i < N; i++) {
		factorAndCount(Arr[i], i, map);
	}
	int64 maxNum = 0;
	for (auto x : map) {
		maxNum = max(maxNum, x.second.second);
	}

	cout << maxNum;
	// cout << endl;
	// for (auto x : map) {
	// 	cout << x.first << " " << x.second.second << endl;
	// }


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