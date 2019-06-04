#include<iostream>
using namespace std;

void wavesort(int *arr,int n){

	for(int i=0;i<n;i++){
		int j=i+1;
		if(j<n){
		if(i%2==0){
			if(arr[i] < arr[j]){
				swap(arr[i],arr[j]);
			}
		}
		if(i % 2 !=0 ){
			if(arr[i] > arr[j]){
				swap(arr[i],arr[j]);
			}
		}

	}
}



}

int main(){

	int arr[50];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	wavesort(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}



}
