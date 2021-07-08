#include <iostream>
#include <stack>
using namespace std;

void stockSpan(int prices[], int span[], int n) {
	stack<int> s;
	s.push(0);
	span[0] = 1;

	int currentHighest;

	for(int i = 1; i < n; i++) {
		currentHighest = prices[i];
		
		while(!s.empty() && prices[s.top()] <= currentHighest) {
			s.pop();
		}
		if(!s.empty()) {
			span[i] = i - s.top();
		} else {
			span[i] = i + 1;
		}

		s.push(i);
	}
}

int main() {
	int n;
	cin >> n;

	int a[n];
	int b[n];

	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	stockSpan(a, b, n);

	for(int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}

	cout << "END"<< endl;

	return 0;
}