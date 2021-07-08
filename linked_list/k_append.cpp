#include <iostream>
#include <list>
using namespace std;

int main() {
	list<int> l;
	int n;
	cin>>n;
	int c = n;
	while(c--) {
		int x;
		cin>>x;
		l.push_back(x);
	}
	int k;
	cin>>k;
	k %= n;

	cout<<k<<endl;
	list<int>::iterator it = l.end();
	list<int>::iterator head = l.begin();

	while(k--) {
		it--;
	}

 	l.splice(l.begin(), l, it, l.end());

	for(int x: l) {
		cout<<x<<" ";
	}
	cout<<endl;
	return 0;
}