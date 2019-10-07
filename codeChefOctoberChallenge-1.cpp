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
class listData {
public:
	int price;
	int index;
};
class myComparator 
{ 
public: 
    bool operator()  ( listData p1, listData p2) 
    { 
        return p1.price > p2.price; 
    } 
}; 
void util() {
	int N;
	cin >> N;

	// std::vector<int> v(N);
	int v[100] = {0};
	std::priority_queue<listData,vector<listData>,myComparator >p;

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	int cnt = 1;
	listData l ;
	l.price = v[0];
	l.index = 0;

	p.push(l);

	for (int i = 1; i < N; ++i)
	{
		listData curTop = p.top();
		listData curObj;
		while(i - curTop.index > 5) {
			p.pop();
			curTop = p.top();
		}
		curObj.price = v[i];
		curObj.index = i;

		if(v[i] < curTop.price) {
			cnt++;
		}
		p.push(curObj);
	}
	cout<<cnt;
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