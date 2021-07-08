#include <iostream>
#include <climits>
using namespace std;

int bitonic(int inc[], int dec[], int a[], int n) {
	int i = 0;
	inc[0] = 1;
	dec[n - 1] = 1;
	
	for(int i = 1; i < n; i++) {
		if (a[i] >= a[i - 1]) {
			inc[i] = inc[i - 1]  + 1;
		}
		else {
			inc[i] = 1;
		}
		// if (a[n-i-1] >= a[n - i]) {
		// 	dec[n - i - 1] = dec[n - i] + 1; 
		// } else {
		// 	dec[i] = 1;
		// }
	}

	for(int i = 0; i < n; i++) {
		cout<<inc[i]<<" ";
	}
	cout<<endl;
	for(int i = 0; i < n; i++) {
		cout<<dec[i]<<" ";
	}

	int ans = INT_MIN;

	for(int i = 0; i < n; i++) {
		ans = max(inc[i] + dec[i], ans);
	}
	return ans - 1;
}


int main() {
	int t;
	cin>>t;
	int a[100000];
	int inc[100000];
	int dec[100000];
	while(t--) {
		int n;
		cin>>n;
		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}
		int inc[n];
		int dec[n];
		cout<<bitonic(inc, dec, a, n)<<endl;
	}
	return 0;
}