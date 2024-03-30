#pragma once
#include "CSpace.h"
#include "Board.h"




class AccusedOfPlagiarism :public CSpace
{
private:
    int mMotivationCost;

public:
    AccusedOfPlagiarism(int type, std::string name);

    ~AccusedOfPlagiarism();

    void PlayerLands(CPlayer& player) override;

};


