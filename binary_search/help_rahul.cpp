#include <iostream>
using namespace std;

int help_rahul(int a[], int n, int key) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int mid = (s + e) / 2;
		if(a[mid] == key) {
			return mid;
		}
		else if(a[mid] >= a[s]) {
			if(key >= a[s] and key < a[mid]) {
				e = mid - 1;
			} else {
				s = mid + 1;
			}
		} else {
			if(key <= a[e] and key > a[mid]) {
				s = mid + 1;
			} else {
				e = mid - 1;
			}
		}
	}
	return -1;
}

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k;
	cin >> k;
	cout << help_rahul(a, n, k) << endl;
}
