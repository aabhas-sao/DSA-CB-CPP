#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

bool reduntantParenthesis(string s) {
    int i = 0;
    stack<int> st;
    bool hasSauce = false;
    while(!s.empty() && i < s.length()) {
        if (s[i] == ')') {
            if( st.top() != '(' ) {
                hasSauce = true;
            } else {
                return false;
            }

            while(st.top() != '(' ) {
                st.pop();
            }
            st.pop();
            
        } else {
            st.push(s[i]);
            hasSauce = false;
        }
        i++;
    }

    return true;
}

int main() {
    int t;
    cin >> t;
    string s;
    
    while(t--) {
        cin >> s;

        if(reduntantParenthesis(s)) {
            cout << "Not Duplicates" << endl;
        } else {
            cout << "Duplicate" << endl;
        }
    }

    return 0;
}