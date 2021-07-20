#include <iostream>
#include <unordered_map>
#include <map>
#include <string>
#include <climits>
using namespace std;

bool allPresent (unordered_map<char, int> u, map<char, int> m) {
    for(auto x: u) {
        if(m[x.first] == 0) {
            return false;
        }
    }

    return true;
}

void slidingWindow(string s1, string s2) {
    int l = 0;
    int r = 1;
    bool found = false;

    map<char, int> m;
    unordered_map<char, int> u;
    pair<int, int> ans = make_pair(0, INT_MAX);
    
    for(int i = 0; i < s2.length(); i++) {
        u[s2[i]]++;
    }
    m[s1[l]]++;

    while(l < r) {
        while(!allPresent(u, m)) {
            if(r >= s1.length()) {
                break;
            }
            m[s1[r]]++;
            r++;
        }

        while(true) {
            if(u.count(s1[l]) == 0) {
                m[s1[l]]--;
                l++;
            } else {
                break;
            }
        }

        
        if(allPresent(u, m)) {
            found = true;
            if(r - l < ans.second - ans.first) {
                ans.first = l;
                ans.second = r;
            }
            // cout << ans.first << " " << ans.second << endl;
        
            // for(int i = l; i < r; i++) {
            //     cout << s1[i];
            // }
            // cout << endl;
        }

        m[s1[l]]--;
        l++;
    }
    if(!found) {
        cout << "Not Found" << endl;
        return;
    }
    for(int i = ans.first; i < ans.second; i++) {
        cout << s1[i];
    }
    cout << endl;
}

int main() {
    string s1;
    string s2;
	getline(cin, s1);
	getline(cin, s2);
    slidingWindow(s1, s2);
    return 0;
}