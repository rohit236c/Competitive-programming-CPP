/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>

using namespace std;

int adjSum(std::vector<int> v, int n) {
	stack<pair<int, int>>s;
	pair<int, int>p;
	p.first = v[0];
	p.second = 0;
	s.push(p);

	for (int i = 1; i < n; ++i)
	{
		pair<int, int> top  =  s.top();

		if (top.second == i - 1) {
			s.pop();
			auto newTop = s.empty()? v[i]: s.top().first + v[i];

			if (top.first < newTop) {
				p.first = s.empty()? v[i]: s.top().first + v[i];
				p.second = i;
				s.push(top);
				s.push(p);
			}
			else {
				p.first = v[i];
				p.second = i;
				s.push(p);
				s.push(top);
			}
		}
		else {
			p.first = top.first + v[i];
			p.second = i;
			s.push(p);
		}
	}

	auto ans = s.top();

	return ans.first;
}

int main() {
	int n;
	cin >> n;
	int a;
	vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		v.push_back(a);
	}
	int ans = adjSum(v, n);

	cout << ans;

	return 0;
}