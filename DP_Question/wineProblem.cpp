/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;
int divisibleSumPairs(int n, int k, vector<int> ar) {
    int count = 0;
    for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n;j++){
            if((ar[i]+ar[j])%k==0)
            	// cout<<i<<" "<<j<<endl;
                count++;
        }
    }
    return count;
}
void rotLeft(vector<int> a, int d) {
	queue<int>q;

	for (int i = 0; i < a.size(); ++i)
	{
		q.push(a[i]);
	}
	for (int i = 0; i < d ; ++i)
	{
		int first = q.front();
		q.pop();
		q.push(first);
	}
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
}

int main() {
	int n;
	cin>>n;
	int d;
	cin>>d;
	int a;
	std::vector<int> v;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		v.push_back(a);
	}
	// rotLeft(v,d);
	cout<<divisibleSumPairs(n,d,v);

	return 0;
}