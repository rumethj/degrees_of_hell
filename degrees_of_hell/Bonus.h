#pragma once
#include "CSpace.h"
class Bonus : public CSpace
{
public:
    Bonus(int type, std::string name);

    ~Bonus();

    void PlayerLands(CPlayer& player) override;

};

