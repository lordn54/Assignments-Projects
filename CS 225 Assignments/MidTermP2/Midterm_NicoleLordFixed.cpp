/*
* Name: Nicole Lord
* File: Midterm_NicoleLord.cpp
* Assignment: Midterm Part 2
* Date: 10/08/2019
*/

#include <iostream>
#include <string>
using namespace std;

class SoccerPlayer {
private:
    string playerName;
    int numOfGoals, numOfAssists;
public:
    SoccerPlayer();
    SoccerPlayer(string, int, int);
    inline string getName() {
        return playerName;
    }
    inline int getGoals() {
        return numOfGoals;
    }
    inline int getAssists() {
        return numOfAssists;
    }
};

SoccerPlayer::SoccerPlayer() {
    playerName = "Nicole Lord";
    numOfGoals = 1;
    numOfAssists = 3;
}

SoccerPlayer::SoccerPlayer(string name, int goals, int assist) {
    playerName = name;
    numOfGoals = goals;
    numOfAssists = assist;
}

void bestPlayer(SoccerPlayer& player1, SoccerPlayer& player2) {
    int player1Total;
    int player2Total;
    player1Total = player1.getGoals() + player1.getAssists();
    player2Total = player2.getGoals() + player2.getAssists();
    if (player1Total > player2Total) {
        cout << player1.getName() << " is better than " << player2.getName() << endl;
    } else if (player1Total < player2Total) {
        cout << player2.getName() << " is better than " << player1.getName() << endl;
    } else {
        cout << player1.getName() << " and " << player1.getName() << " are equal. " << endl ;
    }
}

int main() {
    SoccerPlayer mia("Mia Hamm", 103, 72);
    SoccerPlayer brandi("Brandi Chastain", 30, 26);
    SoccerPlayer joe("Joe Smith", 25, 31);
    SoccerPlayer me;
    bestPlayer(mia, brandi);
    bestPlayer(brandi, joe);
    bestPlayer(me, joe);
}
