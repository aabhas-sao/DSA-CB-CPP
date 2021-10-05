#include <bits/stdc++.h>
using namespace std;

void formIslands(char a, string s, vector<pair<int, int>>& islands) {
	bool start = false;
	int count = 0;
	int sc;
	for (int i = 0; i < s.length(); i++) {
		if(s[i] == a && !start) {
			count++;
			sc = i;
			start = true;
		} 
		else if (s[i] == a && start) {
			count++;
		}
		else if (s[i] != a && start){
			islands.push_back({count, sc});
			count = 0;
			start = false;
		}
	}

	if (count != 0) {
		islands.push_back({count, sc});
	}
}


int ss(string s, int k) {
	char c[s.length()];
	for (int i = 0; i < s.length(); i++) {
		c[i] = s[i];
	}
	vector<pair<int, int>> islands;
	int countA = 0;
	int countB = 0;
	for (int i = 0; i < s.length(); i++) {
		if(s[i] == 'a') {
			countA++;
		} else {
			countB++;
		}
	}

	char maxChar;

	if(countA > countB) {
		formIslands('b', s, islands);
		maxChar = 'a';
	} else {
		formIslands('a', s, islands);
		maxChar = 'b';
	}

	vector<pair<int, int>> islandsCopy(islands);


	sort(islands.begin(), islands.end());


	for(int i = 0; i < n; i) {
		cout << x.first << endl;
		for (int i = x.second; i < x.second + x.first; i++) {
			c[i] = maxChar;
			cout << "i " << i << endl;
			k--;
			if(k==0) break;
		}
		
		cout << x.first << " " << x.second << endl;
		if(k==0) break;
	}

	for (int i = 0; i < s.length(); i++) {
		cout << c[i];
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k;
	cin>>k;
	string s;
	cin>>s;

	ss(s, k);

	return 0;
}