#include<iostream>
#include<climits>
using namespace std;

bool isValid(long long int n, int k, long long int mid) {
	long long int ans = 1;
	k += 1;
	while(k--) {		
		if(ans > n) {
			return false;
		}
		long long int oldAns = ans;
		ans *= mid;

		if (oldAns != 0 && ans / oldAns != mid) {
			// overflow handling
			return false;
		}
	}
	return true;
}

void kthroot(long long int n, int k) {
	long long int s = 0;
	long long int e = n;

	long long int mid;
	long long int ans = INT_MIN;
	while(s<=e) {
		mid = (s + e) / 2;
		if(isValid(n, k, mid)) {
			ans = max(mid, ans);
			s = mid + 1;
		}
		else {
			e = mid - 1;
		}
	}
	cout<<ans<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		long long int n;
		int k;
		cin>>n>>k;
		kthroot(n, k);
	}
	return 0;
}