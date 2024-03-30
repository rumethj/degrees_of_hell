#pragma once

#include <iostream>
#include <vector>

#include "CSpace.h"


class Assessment : public CSpace
{
private:
    int mMotivationalCost;
    int mSuccessAchievement;
    int mYear;
    std::vector<CPlayer*> mpCompletedBy;

public:
    Assessment(int type,std::string name,int motivationalCost,int successAchievement,int year);

    ~Assessment();

    void PlayerLands(CPlayer& player) override;

};

