#pragma once
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

#include "CSpace.h"

// CHECK include these in header or cpp????
#include "Assessment.h"
#include "SkipClasses.h"



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
