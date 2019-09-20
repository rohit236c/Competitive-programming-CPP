/*
	author of this code is rohit sharma
*/
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string in, string out){
	
	int count[26]={0};

	if(in.length() != out.length()){
		return false;
	}


	for(int i = 0;i<in.length();i++){
		count[in[i]-'a']++;
	}

	for (int i = 0; i < out.length(); ++i)
	{
		count[in[i]-'a']--;
	}

	for (int i = 0; i < 26; ++i)
	{
		if(count[i]!=0)
			return false;
	}

	return true;

}

int main(){
		string patOne,patTwo;
		cin>>patOne;
		cin>>patTwo;
		cout<<isAnagram(patOne,patTwo);

	return 0;
}