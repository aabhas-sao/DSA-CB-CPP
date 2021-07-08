#include <iostream>
using namespace std;

// improve this soln

void soln(int a[], int n) {
	int curr;
	int greater;
	for(int i = 0; i < n; i++) {
		curr = a[i];
		for(int j = i + 1; j < i + n; j++) {
			if(a[j] > curr) {
				greater = a[j];
				break;
			}
		}
		cout << greater << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	int a[2 * n];
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		a[i + n] = a[i];
	}


}