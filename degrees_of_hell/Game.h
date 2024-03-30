#pragma once

#include <string>
#include <vector>
#include <iostream>

#include "CPlayer.h"
#include "Board.h"
#include "Spinner.h"

class Game
{
private:
    std::vector<CPlayer*> mPlayers;
    Board* mpBoard;
    Spinner* mpSpinner;
    int mRounds;

public:
    Game(std::vector<std::string> players, std::string filePath, int rounds);
    ~Game();


    void StartGame();
    void EndGame();

    void InitialisePlayers(std::vector<std::string> players);

    void InitialiseBoard(std::string filePath);

};


