#pragma once
#include "CSpace.h"

#include <string>
#include <vector>

class Board;

class CPlayer
{
private:
    std::string mName;
    int mYear;
    int mMotivation;
    int mSuccess;
    int mPosition;
    Board& mpBoard;
    std::vector<CSpace*> mCompletedAssessments;

public:
    CPlayer(std::string name, Board& board);

    ~CPlayer();

    std::string GetName() const;
    int GetPosition() const;
    int GetMotivation() const;
    int GetSuccess() const;
    int GetYear() const;
    int GetPlagiarismHearingIndex() const;

    void SetPosition(int pos);

    void AddMotivation(int motivation);

    void DeductMotivation(int motivation);

    void AddSuccess(int success);

    void AddCompleteAssessment(CSpace& assessment);


    void UpdateYear();
};


