#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> l;
	while(1) {
		int n;
		cin>>n;
		if(n == -1) {
			break;
		}
		l.push_back(n);
	}
	int k;
	cin>>k;

	int c = k;
	
	list<int>::iterator a = l.begin();
	list<int>::iterator b = l.begin();
	while(c--) {
		b++;
	}

	while(b != l.end()) {
		a++;
		b++;
	}

	cout<<*a<<endl;
	return 0;
}