#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// unordered_set<int> ans;
int ans = 0;

int cb[] = {2,3,5,7,11,13,17,19,23,29};

bool cbNum(int n) {
	if(n == 0 || n == 1) {
		return false;
	}
	for(int i = 0; i < 10; i++) {
		if( n == cb[i] ) {
			return true;
		}
	}
	for(int i = 0; i < 10; i++) {
		if(n % cb[i] == 0) {
			return false;
		}
	}	
	return true;
}

void substrings(string s, int n) {
	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			int num = 0;
			for(int k = i; k <= j; k++) {
				num = num * 10 + (int)s[k] - '0';	
			}
			if(cbNum(num)) {
				ans++;
				// ans.insert(num);
				i = j + 1;
			}	
		}
	}	
}

int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	substrings(s, n);
	// for(int x: ans) {
	// 	cout<<x<<" ";
	// }
	cout<<ans<<endl;
	return 0;
}