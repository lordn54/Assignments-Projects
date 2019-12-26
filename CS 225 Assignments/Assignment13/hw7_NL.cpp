#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <time.h>
#include <algorithm>
using namespace std;

/*
*  Name: Nicole Lord
*  Date: November 11, 2019
*  Assignment Name: Homework #07
*  File #01: hw7_NL.cpp
*/

class Pokemon {
private:
    string name;
    int cp;
public:
    Pokemon ();
    friend ostream& operator<<(ostream &os, Pokemon poke);
    bool operator<(const Pokemon &p2) const;
};

Pokemon::Pokemon() {
    string pokemonName[10] = {"Pikachu", "Charzard", "Eevee", "Venusaur", "Magikarp", "Mewtwo", "Snorlax",
                             "Ho-Oh", "Wobbuffet", "Wigglytuff"};
    int pokemonCP[10] = {291, 2889, 837, 612, 129, 300, 330, 244, 382, 295};
    int i;
    srand (time(NULL));
    i = rand() % 10;
    name = pokemonName[i];
    cp = pokemonCP[i];
}

ostream& operator<<(ostream &os, Pokemon poke){
    os << "    Pokemon: " << poke.name << " Combat Power: " << poke.cp << endl;
    return os;
}

bool Pokemon::operator<(const Pokemon &p2) const{
    return p2.cp < this->cp;
}

int main() {
    vector<Pokemon> poke;
    Pokemon temp;
    int userInput = 2;
    int i = 0;
    while (userInput != 0) {
        Pokemon pokem;
        cout << "A pokemon appears in the wild." << endl;
        cout << "Would you like to catch it? (0 = no, 1 = yes) ";
        cin >> userInput;
        if (userInput == 1) {
            poke.push_back(pokem);
            cout << "\n         Your Pokemon are:" << endl;
            cout << "******************************************" << endl;
            for (vector<Pokemon>::iterator it = poke.begin();
                                   it != poke.end(); it++) {
                cout << *it << endl;
            }
        }        
    }
    cout << "Sorted pokemon from strongest to weakest for battle:" << endl;
    sort(poke.begin(), poke.end());
    cout << "\n         Your Pokemon are:" << endl;
    cout << "******************************************" << endl;
    for (vector<Pokemon>::iterator it = poke.begin();
                                   it != poke.end(); it++) {
        cout << *it << endl;
    }
}