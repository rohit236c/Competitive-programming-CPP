#include<iostream>
#include<string.h>
#include<algorithm>
#include<stdio.h>
using namespace std;

void missing_pangram(char str[],int n){
	int check[25];
	int j=0;
	for(int i=0;i<=25;i++){
		check[i]=-1;
	}
	for(int i=0;i<n;i++){
			if(str[i]>='a' && str[i]<='z'){
				j=str[i]-'a';
			}
				check[j]=str[i]-'a';
					/////////j++;
	}
	//sort(check,check+25);
	for(int i=0;i<=25;i++){
		cout<<check[i]<<" ";
	}
	cout<<endl;

	for(int i=0;i<=25;i++){
		if(check[i]==-1){
			char symbol = (char)('a'+ i);
			cout<<symbol<<" ";
		}
	}



}

int main(){
	char str[50];
	gets(str);
	missing_pangram(str,strlen(str));
	cout<<strlen(str);






}