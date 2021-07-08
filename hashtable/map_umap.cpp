#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

class Game {
public:
    string title;
    int releaseYear;
    Game(string t, int y) {
        title = t;
        releaseYear = y;
    }

    bool operator==(const Game &s) const {
        return title == s.title;
    }
};

class MyHashFn {
public:
    size_t operator()(const Game &s) const {
        return s.title.length();
    }
};

int main() {
    unordered_map<Game, int, MyHashFn> gameStore;
    Game g1 = Game("Forza Horizon 4", 2018);
    Game g2 = Game("Horizon Zero Dawn", 2019);
    Game g3 = Game("GTA V", 2013);
    gameStore[g1] = 5;
    gameStore[g2] = 5;
    gameStore[g3] = 5;

    for(auto x: gameStore) {
        cout << x.first.title << " " << x.first.releaseYear << " rating: " << x.second << endl;
    }
    
    return 0;
}