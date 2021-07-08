#include <iostream>
using namespace std;

// void genPrefixArr() {
//     prefix[0][0] = tiles(1, 1);
//     prefix[1][0] = tiles(2, 1);
//     for(int i = 1; i < 100000; i++) {
//         for(int j = 1; j < 100000; j++) {
//             if(n < m) {
//                 prefix[i][j] = 1;
//             }
//             if(n == m) {
//                 prefix[i][j] = 2;
//             }
//             prefix[i][j] = prefix[i - 1][j] + prefix[i - 1][j + 1];
//         }
//     }
//     cout<<prefix[1][1];
// }

int tiles(int n, int m, int **prefix) {
    // base case
    if(m == 1) {
        return 1;
    }
    if(n == 2 && m == 2) {
        return 2;
    }
    if(n < m) {
        return 1;
    }
    cout<<prefix[n - 1][ m - 1]<<endl;
    prefix[n - 1][ m - 1] = tiles(n - 1, m, prefix) + tiles(n - m, m, prefix);
    return prefix[n - 1][m - 1];
}

int main() {
    int **prefix = new int*[100000];
    for(int i = 0; i < 100000; i++) {
        prefix[i] = new int[100000];
    }
    // int t;
    // cin>>t;
    // while(t--) {
    //     int n, m;
    //     cin>>n>>m;
    //     int ans = tiles(n, m);
    //     ans = ans % 1000000007;
    //     cout<<ans<<endl;
    // }
    tiles(100000, 100000, prefix);
    int n = 4;
    int m = 2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout<<prefix[i][j]<<" ";
        }
    cout<<endl;
    }
    return 0;   
}