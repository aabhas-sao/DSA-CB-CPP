#include <iostream>
#include <stack>
#include <climits>
using namespace std;

void histo(int a[], int n) {
	stack<int> s;
	int max_area = INT_MIN;
	int curr_area;
	int prev;

	int i = 0;

	for(; i < n; i++) {
		if(s.empty()) {
			s.push(i);
		} else {
			while(!s.empty() && a[s.top()] > a[i]) {
				prev = s.top();			
				s.pop();
			
				if(s.empty()) {
					curr_area = a[prev] * (i);
					max_area = max(max_area, curr_area);
				} else {
					curr_area = a[prev] * (i - s.top() - 1);
					max_area = max(max_area, curr_area);

					cout << max_area << endl;
				}
			}
			s.push(i);
		}
	}

	while(!s.empty()) {
		int x = s.top();
		s.pop();
		if(s.empty()) {
			curr_area = a[x] * (i);
			max_area = max(curr_area, max_area);
		} else {
			curr_area = a[x] * (i - s.top() - 1);
			max_area = max(curr_area, max_area);
		}
	}

	cout << max_area << endl;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	histo(a, n);
	return 0;
}