#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void multiply(vector<int>& res, int x) {
    int carry = 0;
    int dig = 0;
    for(int i = 0; i < res.size(); i++) {
        dig = res[i] * x + carry;
        carry = dig / 10;
        dig %= 10;
        res[i] = dig;
    }

    if(carry) {
        while(carry) {
            res.push_back(carry % 10);
            carry = carry / 10;
        }
    }
}

vector<int> factorial(int n) {
    vector<int> res;
    res.push_back(1);

    for(int i = 2; i <= n; i++) {
        multiply(res, i);
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    int n;
    cin>>n;

    for(int x : factorial(n)) {
        cout<<x;
    }
    cout<<endl;
}