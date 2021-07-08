	#include<iostream>
	#include<climits>
	using namespace std;

	#define ll long long int

	bool isPossible(ll a[], ll mid, ll k, ll n) {
		ll pallersUsed = 1;
		ll boardTime = 0;
		for(ll i = 0; i < n; i++) {
			if(boardTime + a[i] > mid) {
				pallersUsed++;
				boardTime = a[i];
				if(pallersUsed > k) {
					return false;
				}
			} else {
				boardTime += a[i];
			}		
		}
		return true;
	}

	void paint(ll a[], ll n, ll k, ll t) {
		ll largest = INT_MIN;
		ll e = 0;
		for(ll i = 0; i < n; i++) {
			largest = max(largest, a[i]);
			e += a[i];
		}
		
		ll s = largest;
		ll ans;

		while(s<=e) {
			ll mid = (s + e) / 2;
			if(isPossible(a, mid, k, n)) {
				e = mid - 1;
				ans = mid;
			}
			else {
				s = mid + 1;
			}
		}
		ans = (ans * 5) % 10000003;
		cout<<((ans%10000003)*(t%10000003))%10000003<<endl;
	}

	int main() {
		ll n, k, t;
		cin>>n>>k>>t;

		ll a[n];
		for(ll i = 0; i < n; i++) {
			cin>>a[i];
		}

		paint(a, n, k, t);
		return 0;
	}

	/*
		test case 1
		4 3 5 
		10 20 30 40
	*/