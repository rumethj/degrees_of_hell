#include <iostream>
#include <vector>

#include "Game.h"

int main()
{
    std::vector<std::string> players;
    players.push_back("Vyvyan");
    players.push_back("Rick");

    const std::string boardSetUpFilePath = "degrees.txt";
    const int rounds = 20;
    
    Game* degreesGame = new Game(players, boardSetUpFilePath, rounds);

    degreesGame->StartGame();

    return 0;
}