#include <iostream>
#include <queue>
using namespace std;

int joinRopes(priority_queue<int, vector<int>, greater<int>> pq) {
    int cost = 0;

    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        int newRope = a + b;
        cost += newRope;
        pq.push(newRope);
    }

    return cost;
}

int main() {
    int ropes[] = {2, 3, 6, 4};
    int n = sizeof(ropes) / sizeof(int);
    priority_queue<int, vector<int>, greater<int>> pq(ropes, ropes + n);

    cout << joinRopes(pq) << endl;
    return 0;
}