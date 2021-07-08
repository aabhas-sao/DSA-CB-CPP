#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;



int main() {
    unordered_map<string, vector<string>> phonebook;
    vector<string> v1 = {"9024335853", "9893776137"};
    vector<string> v2 = {"9819418957"};
    phonebook["Aabhas"] = v1;
    phonebook["Rohan"] = v2;

    for(auto x: phonebook) {
        cout << x.first << " ";
        for(auto z: x.second) {
            cout<< z << ", ";
        }
        cout << endl;
    }

    return 0;
}