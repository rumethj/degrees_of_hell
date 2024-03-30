#pragma once
#include "CSpace.h"

#include <vector>

class ExtraCurricular : public CSpace
{
private:
    int mMotivationalCost;
    int mSuccessAchievement;
    std::vector<CPlayer*> mUndertakenBy;

public:
    ExtraCurricular(int type, std::string name, int motivationalCost);

    ~ExtraCurricular();

    void PlayerLands(CPlayer& player) override;

};
