#include <iostream>
using namespace std;

bool canIPlace(pair<int, int>** board, int r, int c) {
    // check if lies outside board
    if(board[r][c].first == 0) {
        return false;
    } else {
        // If the spot is already visited return false
        if(board[r][c].second == 1) {
            return false;
        }
    }

    return true;
}

void funkyBoard(pair<int, int>** board, int n, int r, int c) {
    // base case
    // Knight cannot move any place then K / O return false
    
    // mark as visited
    board[r][c].second = 1;
    
    bool attempt1 = canIPlace(board, r - 2, c - 1);
    bool attempt2 = canIPlace(board, r - 2, c + 1);
    bool attempt3 = canIPlace(board, r - 1, c - 2);
    bool attempt4 = canIPlace(board, r - 1, c + 2);
    bool attempt5 = canIPlace(board, r + 1, c - 2);
    bool attempt6 = canIPlace(board, r + 1, c + 2);
    bool attempt7 = canIPlace(board, r + 2, c - 1);
    bool attempt8 = canIPlace(board, r + 2, c + 1);

    if(attempt1) {
        funkyBoard(board, n, r - 2, c - 1);
        board[r][c].second = 0;
    }

    if(attempt2) {
        funkyBoard(board, n, r - 2, c + 1);
        board[r][c].second = 0;
    }
    
    if(attempt3) {
        funkyBoard(board, n, r - 1, c - 2);
        board[r][c].second = 0;
    }

    if(attempt4) {
        funkyBoard(board, n, r - 1, c + 2);
        board[r][c].second = 0;
    }

    if(attempt5) {
        funkyBoard(board, n, r + 1, c - 2);
        board[r][c].second = 0;
    }

    if(attempt6) {
        funkyBoard(board, n, r + 1, c + 2);
        board[r][c].second = 0;
    }

    if(attempt7) {
        funkyBoard(board, n, r + 2, c - 1);
        board[r][c].second = 0;
    }

    if(attempt8) {
        funkyBoard(board, n, r + 2, c + 1);
        board[r][c].second = 0;
    }

    board[r][c].second = 0;

    cout << r << " " << c << " " << board[r][c].second << endl; 
    if(
        attempt1 == false && 
        attempt2 == false && 
        attempt3 == false && 
        attempt4 == false && 
        attempt5 == false && 
        attempt6 == false && 
        attempt7 == false && 
        attempt8 == false 
        ) {
            int c = 0;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(board[i][j].first == 1 && board[i][j].second == 0) {
                        c++;
                    }
                }
            }
            cout << c << endl;
            return;
    }
}

int main() {
    int n;
    cin >> n;
    pair<int, int>** board = new pair<int, int>*[n];

    for(int i = 0; i < n; i++) {
        board[i] = new pair<int, int>[n];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j].first;
            board[i][j].second = 0;
        }
    }

    funkyBoard(board, n, 0, 0);

    return 0;
}