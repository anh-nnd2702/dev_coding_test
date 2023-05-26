#include <bits/stdc++.h>
#include  <iostream>
using namespace std;

bool isPair(char a, char b){
	return (a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')');
}

bool checkBalance(string s){
	std::stack<char> box;
		
	int sLen = s.length();
	for(int i=0; i<sLen; i++){
		if(s[i]=='{'||s[i]=='['||s[i]=='('){
			box.push(s[i]);
		}
		else if(s[i]=='}'||s[i]==']'||s[i]==')'){
			if(box.empty()){
				return false;
			}
			
			char boxTop = box.top();
			box.pop();
			
			if(!isPair(boxTop,s[i])){
				return false;
			}
		}
	}
	
	return box.empty();
	/*if (i>=j) return true;
	if(!isPair(s[i], s[j])) {
		return false;
	}
	else {
		return checkBalance(s,i+1, j-1);
	}*/
}

int main(){
	int n = 0;
	
	do{
		cin>>n;
	} while (n<=0 || n>100);
	
	cin.ignore();
	
	string *arrStr = new string[n];
	
	for(int i = 0; i<n; i++){
		getline(cin,arrStr[i]);
	}
	
	for(int i = 0; i<n; i++){
		if((arrStr[i].length()%2)== 1){
			cout<<"false"<<endl;
		} 
		else if(arrStr[i].length() == 0){
			cout<<"true"<<endl;
		}
		else{
			
			if(checkBalance(arrStr[i])){
				cout<<"true"<<endl;
			}
			else{
				cout<<"false"<<endl;
			}
		}
		
	}
	
	delete [] arrStr;
	return 0;	
}
