#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int defkin(int b[3][2]) {
    int x[5], y[5];
    x[0] = y[0] = 0;
    x[4] = y[4] = 12;
    
    for(int i = 1; i <= 3; i++) {
        x[i] = b[i - 1][0];
        y[i] = b[i - 1][1];
    }

    sort(x, x + 5);
    sort(y, y + 5);

    for(int i = 0; i < 5; i++) {
        cout << x[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < 5; i++) {
        cout << y[i] << " ";
    }
    cout << endl;

    int max_x = INT_MIN;
    int max_y =  INT_MIN;
    for(int i = 1; i <= 3; i++) {
        int temp_x = x[i] - x[i - 1];
        int temp_y = y[i] - y[i - 1];
        
        max_x = max(max_x, temp_x);
        max_y = max(max_y, temp_y);
    }
    return (max_x - 1)* (max_y - 1);
}

int main() {
    int b[3][2] = {{11, 3}, {8, 6}, {3, 8}};

    cout << defkin(b) << endl;
    return 0;
}