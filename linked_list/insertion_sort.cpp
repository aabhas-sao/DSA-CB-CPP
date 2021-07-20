#include <iostream>
#include <list>
using namespace std;


void insertion_sort(list<int>& l) {
	
	for(auto it = ++l.begin(); it != l.end(); it++) {
		auto jt = it;
		auto prev = jt;
		prev--;
		// cout << *it << endl;
		// cout << *prev << " " << *jt << endl;
		while(prev != l.end() && *prev > * jt) {
			// cout << *prev << " " << *jt << endl;
			swap(*prev, *jt);
			// cout << *prev << " " << *jt << endl;
			// break;
			jt--;
			prev--;		
		}
	}
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	list<int> l (a, a + n);

	// auto it = l.begin();
	// it--;
	// cout << *it << endl;

	insertion_sort(l);

	// list<int>::iterator b = l.begin();
	// list<int>::iterator s = l.begin();
	// s++;

	// swap(*b, *s);
	// ++b;
	// --s;
	// cout << *b << endl;
	for(int x: l) {
		cout<< x <<" ";
	}
	return 0;
}