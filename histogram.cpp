/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>

using namespace std;

int histogramArea(int * arr, int n) {
	stack <int> s ;
	int area = 0;
	int maxArea = 0;
	int i = 0;
	int top;
	while(i<n)
	{
		if (s.empty() || arr[s.top()] <= arr[i]) {
			s.push(i++);
		}
		else {
			top = s.top();
			s.pop();
			area = arr[top] * (s.empty() ? i : i - s.top() - 1);
			maxArea = max(maxArea, area);
		}
	}
	while (!s.empty()) {
			top = s.top();
			s.pop();
			area = arr[top] * (s.empty() ? i : i - s.top() - 1);
			maxArea = max(maxArea, area);
		}
	return maxArea;
}

int main() {
	int arr[100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int ans = histogramArea(arr, n);
	cout << "ans = " << ans;

	return 0;
}