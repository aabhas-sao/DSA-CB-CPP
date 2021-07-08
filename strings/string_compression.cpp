#include<iostream>
#include<vector>
#include<string>
using namespace std;

void stringCompression(string s) {
	vector<pair<char, int>> ans;
	int n = s.length();
	for(int i = 0; i < n - 1; i++) {
		char c = s[i];
		int count = 1;
		while(s[i + 1] == c) {
			count++;
			i++;
		}
		ans.push_back(make_pair(c, count));
	}
	if(s[n - 1] != s[n - 2]) {
		ans.push_back(make_pair(s[n - 1], 1));
	}
	for(auto x: ans) {
		cout<<x.first<<x.second;
	}
	cout<<endl;
}


int main() {
	string s;
	cin>>s;

	stringCompression(s);

	return 0;
}