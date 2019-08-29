/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;

void printAllSequencesUtil(std::map<int, std::vector<int>>&map,int*arr,int n,int index){
	if(index == n){
		return;
	}
	vector<int> v;
	
	if(map.count(arr[index]) == 0){
		map[arr[index]];
	}
	for (int i = index + 1; i < n; ++i)
	{
		v.push_back(arr[i]);
	}
	map[arr[index]] = v;

	printAllSequencesUtil(map,arr,n,index+1);

}

void printAllSequences(int * arr,int n,int r){
	std::map<int, vector<int> > mymap;
	int index = 0;
	printAllSequencesUtil(mymap,arr,n,index);

	for(auto element: mymap){
		for (int i = 0; i < element.second.size(); ++i)
		{
			cout<<element.first<<"->"<<element.second[i]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	int n,r;
	cin>>n>>r;
	int arr[100] = {0};
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	printAllSequences(arr,n,r);
	

	return 0;
}