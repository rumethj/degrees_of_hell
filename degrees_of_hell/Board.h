#pragma once
#include <sstream>
#include <vector>
#include <fstream>
#include <string>

//#include "CSpace.h"

// CHECK include these in header or cpp????
#include "Assessment.h"
#include "WelcomeWeek.h"
#include "SkipClasses.h"
#include "PlagiarismHearing.h"
#include "AccusedOfPlagiarism.h"
#include "ExtraCurricular.h"
#include "Bogus.h"
#include "Bonus.h"


#include "Spinner.h"


class CPlayer;
class CSpace;

class Board
{
private:
    Spinner& mSpinner;
    std::vector<CSpace*> mBoard;
    int mPlagiarismHearingIndex;
    int mAccusedOfPlagiarismIndex;

public:
    Board(std::string setUpFilePath, Spinner& spinner);

    ~Board();

    int GetSize() const;
    int GetPlagiarismHearingIndex() const;

    std::string GetSpaceName(int spacePos) const;

    void ShowBoard();

    void RunSpaceAction( CPlayer& player );
};
