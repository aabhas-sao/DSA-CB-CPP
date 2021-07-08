#include<iostream>
using namespace std;

int b[31] = {0};

void bits(int n) {
	int i = 31;
	int mask = 1;
	while(n) {
		int res = n & mask;
		b[i] = b[i] + res;
		int p = b[i];
		n = n>>1;
		i--;
	}
}

int binToInt(int a[]) {
	int p = 1;
	int ans = 0;
	for(int i = 31; i >= 0; i--) {
		ans += p * a[i];
		p *= 2;
	}
	return ans;
}

void uq3(int a[], int n) {
	for(int i = 0; i < n; i++) {
		bits(a[i]);
	}

	for(int i = 0; i <= 31; i++) {
		b[i] %= 3;
	}

	cout<<binToInt(b)<<endl;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}

	uq3(a, n);


	// bits(3);
	// bits(2);
	// bits(2);
	// bits(2);
	// bits(1);
	// bits(1);
	// bits(1);
	// for(int i = 0; i < 32; i++) {
	// 	cout<<b[i]<<" ";
	// }

	return 0;
}