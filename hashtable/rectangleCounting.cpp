#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    bool compare(Point p2) {
        if(this->x == p2.x) {
            return this->y < p2.y;
        }

        return this->x < p2.x;
    }
};

int rectanglesCount(const vector<Point> coordinates) {
    set<Point, compare> s;

    for(auto x: coordinates) {
        s.insert(x);
    }

    for(auto it = coordinates.begin(); it != --coordinates.end(); it++) {
        for(auto jt = ++it; jt != coordinates.end(); jt++) {
            Point p1 = *it;
            Point p2 = *jt;
        }
    }
    
}

int main() {

    int t;
    vector<Point> coordinates;
    while(t--) {
        int x, y;
        cin >> x >> y;
        Point p(x, y);
        coordinates.push_back(p);
    }

    return 0;
}