#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
using namespace std;

string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

string searchIn [] = {
            "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
            "utkarsh", "divyam", "vidhi", "sparsh", "akku"
    };

void smartKeypad(string s, char c[], int i, int j, unordered_map<string, vector<string>> u) {
    // base case
    if(j >= s.length()) {
        c[i] = '\0';
        string z(c);
        for(auto x: u[z]) {
            cout << x << endl;
        } 
        return;
    }
    int pos = s[i] - '0';
    string p = table[pos];
    for(int k = 0; k < p.length(); k++) {
        c[i] = p[k];
        smartKeypad(s, c, i + 1, j + 1, u);
    }
}

int main() {
    string s;
    char c[11];
    cin >> s;
    int sl = 11;

    unordered_map<string, vector<string>> u;

    // hash all subarrays of searchIn arrays
    for(int i = 0; i < sl; i++) {
        string str = searchIn[i];
        for(int j = 0; j < str.length(); j++) {
            for(int k = j; k < str.length(); k++) {
                int p = 0;
                for(int l = j; l <= k; l++) {
                    c[p] = str[l];
                    p++;
                }
                c[p] = '\0';
                string substr(c);
                u[substr].push_back(str);
            }
        }
    }

    smartKeypad(s, c, 0, 0, u);
    return 0;
}