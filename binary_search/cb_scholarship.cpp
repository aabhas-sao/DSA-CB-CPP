#include<iostream>
#include<climits>
using namespace std;

#define long long ll

bool canGiveScholarship(ll n, ll mid, ll m, ll x, ll y) {
    ll coupons = m + (n - mid) * y;
    return mid * x <= coupons;
}

void cb(ll n, ll m, ll x, ll y) {
    ll s = 0;
    ll e = n;

    ll ans = ll_MIN;
	ll mid;
    while(s <= e) {
        mid = (s + e) / 2;
		if(canGiveScholarship(n, mid, m, x, y)) {
            s = mid + 1;
            ans = max(mid, ans);
        }
        else {
            e = mid - 1;
        }
    } 
    cout<<ans<<endl;
}

ll main() {
	ll n, m, x, y;
	cin>>n>>m>>x>>y;
	cb(n, m, x, y);
	return 0;
}