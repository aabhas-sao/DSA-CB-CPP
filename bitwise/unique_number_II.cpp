#include<iostream>
#include<vector>
using namespace std;

int firstSetBit(int a) {
    int pos = 0;
    int i = 1;
    while(a > 0) {
        if(a&i) {
        	return pos;
        }
        a = a>>1;
		pos++;
    }
	return -1;
}

void uq(int a[], int n) {
	int x = 0;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		x = x ^ a[i];
	}
	int z = firstSetBit(x);

	for (int i = 0; i < n; i++) {
		if(firstSetBit(a[i]) == z) {
			v.push_back(a[i]);
		}
	}

	int n1 = 0;
	for(int x: v) {
		n1 = n1 ^ x;
	}
	int n2 = n1 ^ x;
	if(n1 > n2) {
		cout<<n2<<" "<<n1<<endl;
	} else {
		cout<<n1<<" "<<n2<<endl;
	}
}

int main() {
	int n;
	cin>>n;
    int a[n];

	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	
	uq(a, n);
	return 0;
}