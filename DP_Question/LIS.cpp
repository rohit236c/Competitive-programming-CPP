/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;

int LIS(int * arr, int n){
	int dp[100];
	std:fill(dp,dp+n,1);
	int ans = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(arr[i] >= arr[j]){
				int curlen = dp[j]+1;
				dp[i] = max(dp[i],curlen);
			}
		}
		ans = max(ans,dp[i]);
	}
	return ans;
}

int main() {
	int n;
	cin>>n;
	int arr[100];

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	cout<<LIS(arr,n);
	

	return 0;
}