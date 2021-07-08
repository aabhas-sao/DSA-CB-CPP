#include<iostream>
using namespace std;

void print_2d(int** a, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

int sum_sm(int** a, int r, int c) {
    int sum = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            sum += a[i][j] * ((i+1)*(j+1) * (r-i)*(c-j));
        }
    }
    return sum;
}



int main() {
    int** a;
    int r,c;
    cin>>r>>c;
    a = new int*[r];
    for(int i = 0; i < r; i++) {
        a[i] = new int[c];
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            a[i][j] = 1;
        }
    }

    cout<<sum_sm(a, r, c);
    return 0;
}