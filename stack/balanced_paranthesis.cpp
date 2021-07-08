#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool paranthesis(string s) {
	int i = 0;
	stack<char> c;
	while(i < s.length()) {
		if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
			c.push(s[i]);
		}
		else {
			if(c.empty()) {
				return false;
			}
			if(s[i] == '}') {
				if(c.top() == '{') {
					c.pop();
				} else {
					return false;
				}
			}
			if(s[i] == ']') {
				if(c.top() == '[') {
					c.pop();
				} else {
					return false;
				}
			}
			if(s[i] == ')') {
				if(c.top() == '(') {
					c.pop();
				} else {
					return false;
				}
			}
		}
		i++;
	}
	if(!c.empty()) {
		return false;
	}
	return true;
}

int main() {
	string s;
	cin>>s;
	// cout<<s;
	if(paranthesis(s)) {
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}
	return 0;
}