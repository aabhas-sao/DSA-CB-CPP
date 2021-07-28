#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

class Pokemon {
    string name;
    int age;
public:
    Pokemon(string name, int age) {
        this->name = name;
        this->age = age;
    }

    int getAge() {
        return age;
    }

    string getName() {
        return name;
    }
};

class PokemonCompare {
public:
    bool operator()(Pokemon p1, Pokemon p2) {
        return p1.getAge() < p2.getAge();
    }
};

int main() {
    priority_queue< Pokemon, vector<Pokemon>, PokemonCompare > pq;

    pq.push(Pokemon("Pikachu", 20));
    pq.push(Pokemon("Bulbasaur", 21));
    pq.push(Pokemon("Weasel", 14));
    pq.push(Pokemon("Charrizard", 32));
    pq.push(Pokemon("Mewto", 100000));

    while(!pq.empty()) {
        Pokemon p = pq.top();
        cout << p.getName() << " ";
        cout << p.getAge() << endl;
        pq.pop();
    }
}