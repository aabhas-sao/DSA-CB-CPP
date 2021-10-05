	#include <iostream>
	#include <vector>
	#include <cstring>
	#include <algorithm>
	using namespace std;



	string extractStringAtKey(string s, int key) {
		char *c = strtok((char *)s.c_str(), " ");
		while(key > 1) {
			c = strtok(NULL, " ");
			key--;
		}
		return (string)c;
	}

	bool lexicographicalCompare(pair<string, string> s1, pair<string, string> s2) {
		return s1.second < s2.second;
	}

	bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
		return stoi(s1.second) < stoi(s2.second);
	}

	int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		int n; cin >> n;
		cin.get();

		string s[n];
		for (int i = 0; i < n; i++) {
			getline(cin, s[i]);
		}
		pair<string, string> stPair[n];
		
		int key;
		string reverse, type;
		cin >> key >> reverse >> type;

		for (int i = 0; i < n; i++) {
			stPair[i].first = s[i];
			stPair[i].second = extractStringAtKey(s[i], key);
		}

		if(type == "lexicographical") {
			sort(stPair, stPair + n, lexicographicalCompare);
		} else {
			sort(stPair, stPair + n, numericCompare);
		}

		if(reverse == "true") {
			for (int i = 0; i < n / 2; i++) {
				swap(stPair[i], stPair[n - i - 1]);
			}
		}

		for (int i = 0; i < n; i++) {
			cout << stPair[i].first << endl;
		}
	}