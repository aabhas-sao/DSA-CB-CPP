#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

bool allPresent(string s2, unordered_map<char, int> u) {
    for (auto x: s2) {
        if(u[x] == 0) {
            return false;
        }
    }
    return true;
}

void display(int i, int j, string s) {
    for(int k = i; k <= j; k++) {
        cout << s[k];
    }
    cout << endl;
}

int main() {
    string s, s2;
    getline(cin, s);
    getline(cin, s2);
    int n = s.length();
    char c[1000];

    unordered_map<char, int> u;
    unordered_map<char, int> v;
    char missing;
    bool foundMissing = false;

    for(int i = 0; i < s2.length(); i++) {
        v[s2[i]]++;
    }

    int i = 0, j = 0;

    while (j < n && !allPresent(s2, u)) {
        u[s[j]]++;
        j++;
    }
    
    j--;

    string ans = "";

    int p = 0;

    if(allPresent(s2, u)) {
        for(int k = i; k <= j; k++) {
            c[p++] = s[k]; 
        }
        c[p] = '\0';
        ans = string(c);
        u[s[j]]++;

        while(i < n) {
            foundMissing = false;
            u[s[i]]--;
            missing = s[i];
            i++;
            
            while(v[s[i]] == 0) {
                u[s[i]]--;
                i++;
            }

            while(j < n) {
                j++;
                u[s[j]]++;
                
                if(s[j] == missing) {
                    foundMissing = true;
                    break;
                }
            }
            if(!foundMissing) {
                break;
            }
            if((j - i + 1) < ans.length()) {
                p = 0;
                for(int k = i; k <= j; k++) {
                    c[p++] = s[k]; 
                }
                c[p] = '\0';
                ans = string(c);
            }
        }
    }

    cout << ans << endl;

    return 0;
}