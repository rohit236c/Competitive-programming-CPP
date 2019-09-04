#include<bits/stdc++.h>

using namespace std;

long long int missingnumber(){
	vector<long long int> v;
	v.clear();
	v.push_back(-1);
	long long int n;
	cin>>n;
	long long int k = 0;
	for(long long int i = 1 ; i < n;i++){
		cin>>k;
		v.push_back(k);
		k = 0;
	}
	for(long long int i = 1;i < n;i++){
		cout<<v[i]<<" ";
	}

	for (long long int i = 1; i < n; ++i)
	{
		if(v[i]!=i){
			return i;
		}
	}
}

int main(){
	        long long int t ;
			cin>>t ;
			while(t--){
				long long int ans = missingnumber();
				cout<<ans;
			
			}	

	return 0;
}