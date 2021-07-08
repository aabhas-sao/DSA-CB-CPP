#include <iostream>
using namespace std;

bool canPlaceQueen(int board[10][10], int row, int col, int n) {
    // along col
    for(int i = 0; i <= row; i++) {
        if(board[i][col] == 1) {
            return false;
        }
    }
    // check left diagonal
    int x = row;
    int y = col;

    while(x >= 0 && y >= 0) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }
    // check right diagonal
    x = row;
    y = col;
    while(x >=0 && y < n) {
        if(board[x][y] == 1) {
            return false;
        }
        x--;
        y++;
    }
    return true;
}

bool nqueen(int board[10][10], int row, int n) {
    // base case
    if(row == n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 0) {
                    cout<<"_ ";
                }
                else {
                    cout<<"Q ";
                }
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    
    // rec
    for(int i = 0; i < n; i++) {
        if(canPlaceQueen(board, row, i, n)) {
            board[row][i] = 1;
            bool nexQueenRakhPaye = nqueen(board, row + 1, n);
            if(nexQueenRakhPaye) {
                return true;
            }
            board[row][i] = 0; // backtrack
        } 
    }
    return false;
}

int main() {
    int n;
    cin>>n;
    int board[10][10] = {0};
    nqueen(board, 0, n);
    return 0;
}