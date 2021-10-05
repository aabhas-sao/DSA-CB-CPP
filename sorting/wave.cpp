#include <iostream>
using namespace std;

void wave(int a[], int n) {
	for(int i = 0; i < n; i += 2) {
		if(i != 0 && a[i] < a[i - 1]) {
			swap(a[i], a[i - 1]);
		}
		
		if(i != (n - 1) && a[i] < a[i + 1]) {
			swap(a[i], a[i + 1]);
		}
	}
}

void display(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main() {
	int a[] = {1, 3, 4, 2, 7, 8};
	int n = sizeof(a) / sizeof(int);
	wave(a, n);
	display(a, n);
	return 0;
}