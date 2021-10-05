#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;


typedef tree <
int,
null_type,
greater<int>,
rb_tree_tag,
tree_order_statistics_node_update
> PBDS;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	PBDS St;
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		ans += St.order_of_key(a[i]);
		St.insert(a[i]);
	}

	cout << ans << endl;

	return 0;
}