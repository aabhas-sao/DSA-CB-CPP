#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

void print(string a[], int n) {
	for(int i = 0; i < n; i++) {
		cout<<a[i]<<" ";
	}
}

bool compare(string a, string b) {
	int i = 0; 
	int j = 0;
	
	while(i < a.length() && j < b.length()) {
		if(a[i] > b[j]) {
			return true;
		} 
		else if(a[i] > b[j]) {
			return false;
		}
		i++;
		j++;
	}
	if(i < a.length()) {
		return true;
	}
	else {
		return false;
	}
}

string greatest(int a[], int n) {
    string s[n];
    for(int i = 0; i < n; i++) {
        s[i] = to_string(a[i]);
    }
	sort(s, s + n, compare);
    print(s, n);
    cout<<"---------"<<endl;
	string sum = "";
	for(int i = 0; i < n; i++) {
		sum += s[i];
	}
	return sum;
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++) {
			cin>>a[i];
		}

		cout<<greatest(a, n)<<endl;
	}

	return 0;
}