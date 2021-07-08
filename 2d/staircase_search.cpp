#include<iostream>
using namespace std;

int staircase_search(int[][1000] a, int row, int col, int target) {
    int i = 0;
    int j = col - 1;
    while(i < row && j >= 0) {
        if(a[i][j] == target) {
            return 1;
        }
        else if(a[i][j] < target) {
            j++;
        }   else {
            i--;
        }
    }
    return 0;
}

int main() {
    int m, n, target;
    int a[1000][1000];
    cin>>m;
    cin>>n;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }
    cin>>target;
    cout<<staircase_search(a, m, n, target)<<endl;

    return 0;
}