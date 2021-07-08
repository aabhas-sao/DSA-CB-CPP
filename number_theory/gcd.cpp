#include<iostream>
using namespace std;

void gcd(long long int a, long long int b) {
	if(a == 0) {
		cout<<b<<endl;
		return;
	}
	return gcd(b % a, a);
}

int main() {
	long long int a, b;
	cin>>a>>b;

	gcd(a, b);
	return 0;
}