#include<iostream>
#include<climits>
using namespace std;

int main () {
	int a, b;
	cin>>a>>b;

	int ans = INT_MIN;

	for(int i = a; i <= b; i++) {
		for(int j = i + 1; j <= b; j++) {
			int x = i ^ j;
			ans = max(x, ans);
		}
	}

	cout<<ans<<endl;
	
	return 0;
}