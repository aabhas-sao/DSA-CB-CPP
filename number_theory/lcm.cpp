#include<iostream>
using namespace std;

long long int gcd(long long int a, long long int b) {
	if(a == 0) {
		return b;
	}
	return gcd(b % a, a);
}

long long int lcm(long long int a, long long int b) {
	long long int ans = a * b;
	ans /= gcd(a, b);
	return ans;
}

int main() {
	long long int a, b;
	cin>>a>>b;

	cout<<lcm(a, b);
	return 0;
}