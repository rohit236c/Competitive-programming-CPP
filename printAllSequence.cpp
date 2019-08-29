/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;

// method 1
void printAllSequencesUtil(std::map<int, std::vector<int>>&map, int*arr, int n, int index) {
	//base case
	if (index == n) {
		return;
	}
	vector<int> v;

	if (map.count(arr[index]) == 0) {
		map[arr[index]];
	}
	for (int i = index + 1; i < n; ++i)
	{
		v.push_back(arr[i]);
	}
	map[arr[index]] = v;
	printAllSequencesUtil(map, arr, n, index + 1);
}

void printAllSequences(int * arr, int n, int r) {
	std::map<int, vector<int> > mymap;
	int index = 0;

	printAllSequencesUtil(mymap, arr, n, index);

	for (auto element : mymap) {
		for (int i = 0; i < element.second.size(); ++i)
		{
			cout << element.first << "->" << element.second[i] << " ";
		}
		cout << endl;
	}
}

//method 2

void printCombinationUtil(int*arr, int*data, int start, int end,int index ,int r) {

	//base case
	if (index == r) {
		//print the data array
		for (int i = 0; i < r; i++) {
			cout << data[i];
		}
		cout << endl;
		return;
	}

	// replace index with all possible  
    // elements. The condition "end-i+1 >= r-index" 
    // makes sure that including one element  
    // at index will make a combination with  
    // remaining elements at remaining positions  
    
	for(int i = start;i<=end && end-i+1 >= r-index;i++){
		data[index] = arr[i];
		printCombinationUtil(arr,data,i+1,end,index+1,r);
	}

}

void printCombination(int*arr, int n, int r) {
	int data[r];

	printCombinationUtil(arr, data, 0, n - 1, 0, r);

}

int main() {
	int n, r;
	cin >> n >> r;
	int arr[100] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	printAllSequences(arr, n, r);


	return 0;
}