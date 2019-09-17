#include<bits/stdc++.h>
using namespace std;

int iceCreamUtil(int m,int n,std::vector<int> v){
	std::multimap<int, int> mymap;
	int index = -1,indexTwo = -1; 

	for (int i = 0; i < n; ++i)
	{
		 mymap.insert(std::pair<int,int>(v[i],i));
	}
	int searchItem;

	for (int i = 0; i < n; ++i)
	{
		searchItem = m - v[i];

		// mymap.erase(v[i]);
		if(searchItem == v[i]){
			auto item = mymap.find(searchItem);
			mymap.erase(item);
		}

		auto ans = mymap.find(searchItem);
	
		if(ans != mymap.end()){
			index = i+1;
			indexTwo = ans->second + 1;
			break;
		}
	}
	cout<<index<<" "<<indexTwo<<" ";
}

void iceCream(){
	int m;
	cin>>m;
	int n;
	cin>>n;
	std::vector<int> v;
	int a;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		v.push_back(a);
	}
	iceCreamUtil(m,n,v);
	cout<<endl;
}


int main() {
	int t ;
	cin >> t ;
	while (t--) {
		iceCream();
	}

	return 0;
}