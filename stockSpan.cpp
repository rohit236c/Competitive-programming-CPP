/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>

using namespace std;

void stockSpan(int * arr, int n) {
	stack<int>s;
	int spanArray[100] = {0};
	for (int day = 0; day < n; day++) {
		int curPrice = arr[day];
		while (!s.empty() && arr[s.top()] < curPrice) {
			s.pop();
		}
		int maxDay = s.empty() ? 0 : s.top();
		int span = day - maxDay;
		spanArray[day] = span;
		s.push(day);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << spanArray[i] << " ";
	}
}

int main() {
	int t ;
	cin >> t ;
	while (t--) {
		int n;
		cin >> n;
		int arr[1000];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		stockSpan(arr,n);
		cout<<endl;
	}


	return 0;
}