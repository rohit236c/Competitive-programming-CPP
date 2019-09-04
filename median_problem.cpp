/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>

using namespace std;

void median(vector<double> v, int n) {
	vector<double> median_vector;
	double median;
	priority_queue<double>maxHeap;
	priority_queue<double,vector<double>,greater<double>>minHeap;
	median = v[0];
	for (int i = 0; i < n; ++i)
	{
		if (median>= v[i]) {
			maxHeap.push(v[i]);
		}
		else {
			minHeap.push(v[i]);
		}
		int leftSize = maxHeap.size();
		int rightSize = minHeap.size();

		if (leftSize - rightSize > 1) {
			while(leftSize - rightSize > 1){
				double top = maxHeap.top();
				maxHeap.pop();
				minHeap.push(top);
				leftSize--;
				rightSize++;	
			}
			
		}
		else if (rightSize - leftSize > 1) {
			while(rightSize - leftSize > 1){
				double top = minHeap.top();
				minHeap.pop();
				maxHeap.push(top);
				// cout<<top<<"minHeap "<<i<<'\n';
				leftSize++;
				rightSize--;	
			}
			
		}
		// cout<<leftSize - rightSize<<endl;
		// cout<<"right "<<rightSize - leftSize<<endl;
		if(leftSize == rightSize){
			double topMax = maxHeap.top();
			double topMin = minHeap.top();
			// cout<<topMax<<" in q"<<endl;
			median = (topMax + topMin)/2;
			// cout<<median<<" in equal "<<endl;
			median_vector.push_back(median);
		}
		else if(leftSize > rightSize){
			double topMax = maxHeap.top();
			median = topMax;
			// cout<<median<<" in leftGt "<<endl;
			median_vector.push_back(median);
		}
		else if(leftSize < rightSize){
			double topMin = minHeap.top();
			median = topMin;
			// cout<<median<<" in rightGt "<<endl;
			median_vector.push_back(median);
		}
	}
	for(int i = 0;i<median_vector.size();i++){
		cout << fixed;
		cout<<setprecision(1)<<median_vector[i]<<endl;
	}
}

int main() {
	int n;
	double number;
	cin >> n;
	vector<double> v;

	for (int i = 0; i < n; ++i)
	{
		cin >> number;
		v.push_back(number);
	}
	median(v, n);

	return 0;
}