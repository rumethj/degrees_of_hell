#pragma once
#include "CSpace.h"

class PlagiarismHearing : public CSpace
{

public:
    PlagiarismHearing(int type, std::string name);

    ~PlagiarismHearing();

    void PlayerLands(CPlayer& player) override;

};
