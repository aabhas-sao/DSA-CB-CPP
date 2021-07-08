#include<iostream>
using namespace std;

void spiral_print(int a[][1000], int row, int col) {
    int startCol = 0;
    int endCol = col - 1;
    int startRow = 0;
    int endRow = row - 1;


    while(startCol < endCol and startRow < endRow) {
        // first 
        for(int i = startCol; i <= endCol; i++) {
            cout<<a[startRow][i]<<" ";
        }
        startRow++;

        //second
        for(int i = startRow; i <= endRow; i++) {
            cout<<a[i][endCol]<<" ";
        }
        endCol--;

        //third
        for(int i = endCol; i >= startCol; i--) {
            cout<<a[endRow][i]<<" ";
        }
        endRow--;

        //fourth
        for(int i = endRow; i >= startRow; i--) {
            cout<<a[i][startCol]<<" ";
        }
        startCol++;
    }

    // m x n matrix when n > m
    if(startCol!= endCol) {
        for(int i = startCol; i <= endCol; i++) {
            cout<<a[startRow][i]<<" ";
        }
    }
    // m x n matrix when n < m
    else if(startRow != endRow) {
        for(int i = startRow; i <= endRow; i++) {
            cout<<a[i][startCol]<<" ";
        }
    }
    // n x n matrix when n is odd
    else {
        cout<<a[startRow][startCol]<<" ";
    }
}

void display(int a[][1000], int m, int n) {
    for(int i= 0; i < m; i ++) {
        for(int j = 0; j < n; j++) {
            cout<<a[i][j]<<" "; 
        }
    }
}

int main() {
    int a[1000][1000];
    int n;
    int m;
    cout<<"enter no of rows: ";
    cin>>m;
    cout<<"enter no of columns: ";
    cin>>n;

    for(int i= 0; i < m; i ++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = i * n + j + 1; 
        }
    }

    display(a, m, n);
    cout<<endl;
    spiral_print(a, m, n);
    cout<<endl;
    return 0;
}