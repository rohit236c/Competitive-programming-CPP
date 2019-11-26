/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[100];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	int k;
	cin >> k;
	deque<int>d(k);
	int i;
	for (i = 0; i < k; i++) {
		while (!d.empty() && arr[i] > arr[d.back()]) {
			d.pop_back();
		}
		d.push_back(i);
	}
	for (; i < n; i++) {
		cout << arr[d.front()] << " ";

		//remove the elements that are not part of window...
		while (!d.empty() && i - k >= d.front()) {
			d.pop_front();
		}
		// remove the elements that are not useful in the window....
		while (!d.empty() && arr[i] > arr[d.front()]) {
			d.pop_back();
		}
		//add the new elements...
		d.push_back(i);
	}

	cout << arr[d.front()];

	return 0;
}