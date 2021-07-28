#include <iostream>
#include <deque>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> callingOrder;
    deque<int> idealOrder;
    int x;
    int cost = 0;
    for (int i = 0; i < n; i++) {
        cin >> x;
        callingOrder.push_back(x);
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        idealOrder.push_back(x);
    }

    while(!idealOrder.empty()) {
        if(idealOrder.front() == callingOrder.front()) {
            cost++;
            idealOrder.pop_front();
            callingOrder.pop_front();
        } else {
            x = callingOrder.front();
            callingOrder.pop_front();
            callingOrder.push_back(x);
            cost++;
        }
    }
    
    cout << cost << endl;
    
    return 0;
}