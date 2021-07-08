#include<iostream>
using namespace std;

int ssm(int a[][1000], int n) {
    int sum = 0;
    for(int li = 0; li < n; li++) {
        for(int lj = 0; lj < n; lj++) {
            for(int bi = li; bi < n; bi++) {
                for(int bj = lj; bj < n; bj++) {
                    for(int i = li; i <= bi; i++) {
                        for(int j = lj; j <= bj; j++) {
                            sum += a[i][j];
                        }
                    }
                }
            }
        }
    }
    return sum;
}

int main() {
    int n = 60;
    int a[1000][1000];
    for(int i = 0; i< n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = 1;
        }
    }
    cout<<ssm(a, n)<<endl;
    return 0;
}