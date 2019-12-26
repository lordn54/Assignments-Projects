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
    inline void setName(string name) {
        cout << "What's the player's name? ";
        cin >> name;
        playerName = name;
    }
    inline void setGoals(int goals) {
        cout << "How many goals did the player get? ";
        cin >> goals;
        numOfGoals = goals;
    }
    inline void setAssists(int assists) {
        cout << "How many assists did the player get? ";
        cin >> assists;
        numOfAssists = assists;
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
    player1Total = player1.numOfGoals + player1.numOfAssists;
    player2Total = player2.numOfGoals + player2.numOfAssists;
    if (player1Total > player2Total) {
        cout << player1.playerName << " is better than " << player2.playerName;
    } else if (player1Total < player2Total) {
        cout << player2.playerName << " is better than " << player1.playerName;
    } else {
        cout << player1.playerName << " " << player1.playerName << " are equal. " ;
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
