#include <iostream>
#include<stack>
#include<cstring>
using namespace std;

int balancepa(char *str,int n){
	stack<char>s,s1;
	bool flag = false;
	for(int i=0;i<strlen(str);i++){
		
			s.push(str[i]);
		
	}
	if(s.top()==')'){
		while(!s.empty()){
		
			if(s.top() == ')'){
				
				while(s.top() != '('){
				s1.push(s.top());
				s.pop();
			}
			// cout<<s.top()<<endl;
			// cout<<s1.top();
			if(s.top() =='('){
				if(s1.top()==')'){
					flag = true;
					// return true;
					s.pop();
					s1.pop();
				}
			}
			if(s.empty() && !s1.empty()){
				flag = false;
				break;
			}
			


			if(!s1.empty()){
				s.push(s1.top());
				s1.pop();
				}
			
				// cout<<s.top();
			if(!s.empty()){
			if(s.top()=='('){
				flag = false;
				break;			
			}
			// if(s.size()==1 && s1.empty()){
			// 	flag = false;
			// 	break;
			// }
		}
		}
	}
}
		if(!s.empty()){
		 if(s.top() == '('){
			flag = false;
		}
	}
	
		return flag;


	}




int main(){
	char str[100000];
	cin.getline(str,100);
	int n = strlen(str);
	int ans = balancepa(str,n);
	if(ans==true){
	cout<<"YES ";
}
	else{
		cout<<"NO";
	}
}