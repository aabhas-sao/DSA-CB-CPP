#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin>>n;
	stack<int> s;
	while(n--) {
		int k;
		cin>>k;
		if(k == 1) {
			if(!s.empty()) {
				cout<<s.top()<<endl;
				s.pop();
			} else {
				cout<<"No code"<<endl;
			}
		}
		else {
			int val;
			cin>>val;
			s.push(val);
		}
	}
	return 0;
}