#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
#include <vector>

#include "Game.h"

void main()
{
    std::vector<std::string> players;
    players.push_back("Vyvyan");
    players.push_back("Rick");

    const std::string boardSetUpFilePath = "degrees.txt";
    const int rounds = 20;
    
    Game* degreesGame = new Game(players, boardSetUpFilePath, rounds);

    degreesGame->StartGame();
    degreesGame->EndGame();

    delete degreesGame;

    _CrtDumpMemoryLeaks();
}