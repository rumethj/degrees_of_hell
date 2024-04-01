// G21155159
// Rumeth Jayasinghe

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
#include <vector>

#include "Game.h"

void main()
{
    // Assign player names
    std::vector<std::string> players;
    players.push_back("Vyvyan");
    players.push_back("Rick");

    // Assign board setup file and number of rounds
    const std::string boardSetUpFilePath = "degrees.txt";
    const int rounds = 20;
    
    // New game
    Game* degreesGame = new Game(players, boardSetUpFilePath, rounds);

    // Start and ending game
    degreesGame->StartGame();
    degreesGame->EndGame();

    delete degreesGame;

    _CrtDumpMemoryLeaks();
}