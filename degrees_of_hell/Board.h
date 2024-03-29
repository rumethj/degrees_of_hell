#pragma once
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

#include "CSpace.h"


class Board
{
private:
    std::vector<CSpace*> mBoard;

public:
    Board(std::string setUpFilePath);

    ~Board();

    int GetSize() const;


    std::string GetSpaceName(int spacePos) const;

    void ShowBoard();

    void RunSpaceAction( CPlayer& player );
};
