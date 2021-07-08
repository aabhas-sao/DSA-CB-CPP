#include <iostream>
using namespace std;

void findPositions(int a[], int n, int& startPos, int& endPos) {
	int i = 0;
	for(; i < n; i++) {
		if(a[i] > 0) {
			startPos = i;
			break;
		}
	}
	
		if(a[j] > 0) {
			endPos = j;
		}
	}
}

void rainWater(int a[], int n) {
	int startPos = 0;
	int endPos = 0;
	int ans = 0;
	while(startPos != -1 && endPos != -1) {
		startPos = -1;
		endPos = -1;
		findPositions(a, n, startPos, endPos);
		for(int i = startPos + 1; i < endPos; i++) {
			if(a[i] <= 0) {
				ans++;
			}
		}
		for(int i = 0; i < n; i++) {
			a[i]--;
		}
	}
	cout<<ans<<endl;
}

int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	rainWater(a, n);
	return 0;
}