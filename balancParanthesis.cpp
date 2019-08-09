/*
	author of this code is rohit sharma
*/

#include<bits/stdc++.h>

using namespace std;

bool balanceParanthesis(string s) {
	stack<char> st;
	for (int i = 0; i < s.length(); i++) {
		if(s[i]=='(' || s[i] == '{' || s[i] == '['){
			st.push(s[i]);
		}
		else if(s[i]==')' || s[i] == '}' || s[i] == ']') {
			if(st.empty()){
				return false;
			}
			char stack_top = st.top();
			st.pop();
			if((stack_top == '{' && s[i] != '}') ||(stack_top == '(' && s[i] != ')') || (stack_top == '[' && s[i] != ']')){
				return false;
			}
		}
	}
	return st.empty() ;
}

int main() {
	string s ;
	cin >> s;
	bool ans = balanceParanthesis(s);
	if (ans) {
		cout << "expression is balanced";
	}
	else {
		cout << "expression is not balanced";
	}

	return 0;
}