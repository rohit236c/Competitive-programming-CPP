#include<bits/stdc++.h>

using namespace std;

int main(){
	int n ;
	cin>>n;
	double p = 0;
	double ne = 0;
	double z = 0;
	int arr[100];
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}
	for (int i = 0; i < n; ++i)
		{
			if(arr[i]>0){
				p++;
			}
			else if(arr[i]<0){
				ne++;
			}
			else if(arr[i]==0){
				z++;
			}
		}	
	p = p/n;
	ne = ne/n;
	z = z/n;
	cout<< setprecision(6)<<p<<endl;
	cout<< setprecision(6)<<ne<<endl;
	cout<< setprecision(6)<<z<<endl;


	return 0;
}
