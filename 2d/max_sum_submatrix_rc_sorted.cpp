#include<iostream>
#include<climits>
using namespace std;

void print_2d(int** a, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}

void build_suffix_array(int** a, int r, int c) {
    //row wise
    for(int i = r-2; i >= 0; i--) {
        for(int j = 0; j < c; j++) {
            a[i][j] += a[i+1][j];
        }
    }

    //col wise
    for(int i = 0; i < r; i++) {
        for(int j = c-2; j >= 0; j--) {
            a[i][j] += a[i][j+1];
        }
    }
}

int find_max(int** a, int r, int c) {
    int maxy = INT_MIN;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            maxy = max(maxy, a[i][j]); 
        }
    }
    return maxy;
}

int max_sum(int** a, int r, int c) {
    build_suffix_array(a, r, c);
    return find_max(a, r, c);
}

int main() {
    int** a;
    int r,c;
    cin>>r>>c;
    a = new int*[r];
    for(int i = 0; i < r; i++) {
        a[i] = new int[c];
    }
    int val = -4;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            a[i][j] = val++;
        }
    }


    cout<<max_sum(a, r, c)<<endl;
    return 0;
}